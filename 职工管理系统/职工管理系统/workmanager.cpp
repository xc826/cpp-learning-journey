#include "workermanager.h"

workermanager::workermanager()
{

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		m_workernum = 0;
		m_workerarr = NULL;
		m_fileisempty = true;

		ifs.close();
		return;//终止当前构造函数的执行，并返回，避免执行后续可能导致错误的代码
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		m_workernum = 0;
		m_workerarr = NULL;
		m_fileisempty = true;

		ifs.close();
		return;
	}

	//获取职工个数
	int num = get_workernum();
	//cout << "职工个数是：" << num << endl;
	m_workernum = num;

	//初始化职工数组
	m_workerarr = new worker * [m_workernum];
	init_workerarr();

	//测试代码
	//for (int i = 0; i < m_workernum; i++)
	//{
	//	cout << "职工号： " << this->m_workerarr[i]->m_id
	//		<< " 职工姓名： " << this->m_workerarr[i]->m_name
	//		<< " 部门编号： " << this->m_workerarr[i]->m_did << endl;
	//}
}



workermanager::~workermanager()
{
	//要先吧每一个数组中的元素先释放掉，因为它们也是new在堆区开辟的，然后在释放掉数组
	if (m_workerarr != NULL)
	{
		for (int i = 0; i < m_workernum; i++)
		{
			if (m_workerarr[i] != NULL)
			{
				delete m_workerarr[i];
			}
		}
		delete[] m_workerarr;
		m_workerarr = NULL;
	}
}

int workermanager::get_workernum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;

}

void workermanager::init_workerarr()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* w = NULL;
		if (did == 1)
		{
			w = new employee(id, name, did);
		}
		else if (did == 2)
		{
			w = new manager(id, name, did);
		}
		else
		{
			w = new boss(id, name, did);
		}
		m_workerarr[index] = w;
		index++;

	}

	ifs.close();

}


//展示菜单
void workermanager::showmenu()
{
	cout << "***********************************************************" << endl;
	cout << "*****************   欢迎使用职工管理系统!  ****************" << endl;
	cout << "********************   0.退出管理系统   *******************" << endl;
	cout << "********************   1.增加职工信息   *******************" << endl;
	cout << "********************   2.显示职工信息   *******************" << endl;
	cout << "********************   3.删除离职职工   *******************" << endl;
	cout << "********************   4.修改职工信息   *******************" << endl;
	cout << "********************   5.查找职工信息   *******************" << endl;
	cout << "********************   6.按照编号排序   *******************" << endl;
	cout << "********************   7.清空所有文档   *******************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

//退出系统
void workermanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加新员工
void workermanager::add_worker()
{
	cout << "请输入要增加的职工数量：" << endl;
	int addnum;
	cin >> addnum;

	if (addnum > 0)
	{
		//计算新数组的大小
		int newsize = m_workernum + addnum;

		//开辟新空间
		worker** newspace = new worker * [newsize];

		//将原有数组放到新空间
		if (m_workerarr != NULL)
		{
			for (int i = 0; i < m_workernum; i++)
			{
				newspace[i] = m_workerarr[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dselect;

			cout << "请输入要增加的第 " << i + 1 << " 位新职工编号：" << endl;
			while (true)
			{
				cin >> id;
				int flag = isexist(id);
				if (flag != -1)
				{
					cout << "您输入的职工编号已存在，请重新输入!" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "请输入要增加的第 " << i + 1 << " 位新职工姓名：" << endl;
			cin >> name;

			cout << "请选择要增加的第 " << i + 1 << " 位新职工的岗位：" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			worker* w = NULL;
			switch (dselect)
			{
			case 1:
				w = new employee(id, name, 1);
				break;
			case 2:
				w = new manager(id, name, 2);
				break;
			case 3:
				w = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[m_workernum+i] = w;

		}
		//释放原有空间
		delete[] m_workerarr;
		//更改新空间的指向
		m_workerarr = newspace;
		//更新新的员工个数
		m_workernum = newsize;
		m_fileisempty = false;
		cout << "成功添加 " << addnum << " 位新职工！" << endl;

		//保存数据到文件中
		save();


	}
	else
	{
		cout << "输入错误" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void workermanager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < m_workernum; i++)
	{
		ofs << m_workerarr[i]->m_id << " " << m_workerarr[i]->m_name << " " << m_workerarr[i]->m_did << endl;
	}
	ofs.close();
}

//显示职工
void workermanager::showworker()
{
	if (m_fileisempty)
	{
		cout << "文件为空或文件不存在" << endl;
	}
	else
	{
		for (int i = 0; i < m_workernum; i++)
		{
			m_workerarr[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void workermanager::del_worker()
{
	if (m_fileisempty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工的职工编号：" << endl;
		int id;
		cin >> id;
		int flag = isexist(id);
		if (flag != -1)
		{
			for (int i = flag; i < m_workernum; i++)
			{
				m_workerarr[i] = m_workerarr[i + 1];
			}
			m_workernum--;

			//将删除后的数据同步到数据文件中
			save();
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "要删除的员工不存在，删除失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int workermanager::isexist(int id)
{
	int flag = -1;
	for (int i = 0; i < m_workernum; i++)
	{
		if (m_workerarr[i]->m_id == id)
		{
			flag = i;
			break;
		}
	}
	return flag;
}

//修改职工
void workermanager::modify_worker()
{
	if (m_fileisempty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工的职工编号：" << endl;
		int id;
		cin >> id;
		int flag = isexist(id);
		if (flag != -1)
		{
			delete m_workerarr[flag];
			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "请输入修改后该职工的职工编号" << endl;
			cin >> new_id;

			cout << "请输入修改后该职工的职工姓名" << endl;
			cin >> new_name;

			cout << "请输入修改后该职工的职工岗位" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> new_did;

			worker* w = NULL;
			switch (new_did)
			{
			case 1:
				w = new employee(new_id, new_name, new_did);
				break;
			case 2:
				w = new manager(new_id, new_name, new_did);
				break;
			case 3:
				w = new boss(new_id, new_name, new_did);
				break;
			default:
				break;
			}

			m_workerarr[flag] = w;
			cout << "修改成功" << endl;

			//将删除后的数据同步到数据文件中
			save();

		}
		else
		{
			cout << "要修改的员工不存在，修改失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void workermanager::find_worker()
{
	if (m_fileisempty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "请输入要查找的职工的职工编号：" << endl;
			int id;
			cin >> id;
			int flag = isexist(id);
			if (flag != -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				m_workerarr[flag]->showinfo();
			}
			else
			{
				cout << "查找失败，查找不存在！" << endl;

			}
		}
		else if (select == 2)
		{
			//可能有重名的人，因此和前面按编号查找方式有区别，需要遍历出所有该名字的人，然后打印出信息
			cout << "请输入要修改的职工的职工姓名：" << endl;
			string name;
			cin >> name;			
			bool issame = false;
			for (int j = 0; j < m_workernum; j++)
			{
				if (m_workerarr[j]->m_name == name)
				{
					cout << "查找成功，职工编号为：" << m_workerarr[j]->m_id << " 的职工信息如下" << endl;
					m_workerarr[j]->showinfo();
					issame = true;
				}
	
			}
			if (issame == false)
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序
void workermanager::sort_worker()
{
	if (m_fileisempty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_workernum; i++)
		{
			int minormax = i;//声明最大值或者最小值下标
			for (int j = i + 1; j < m_workernum; j++)
			{
				if (select == 1)//升序
				{
					if (m_workerarr[minormax]->m_id > m_workerarr[j]->m_id)
					{
						minormax = j;
					}
				}
				else//降序
				{
					if (m_workerarr[minormax]->m_id < m_workerarr[j]->m_id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				worker* temp = m_workerarr[i];
				m_workerarr[i] = m_workerarr[minormax];
				m_workerarr[minormax] = temp;
			}

		}
		cout << "排序成功，排序后结果为：" << endl;
		save();//可加可不加，加上之后文件里也排好序了
		showworker();
		

	}
}

//清空文件
void workermanager::clean_file()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs;
		ofs.open(filename, ios::trunc);//这种方式是先删除文件内容，再重新创建
		ofs.close();

		if (m_workerarr != NULL)
		{
			//删除堆区每个职工对象
			for (int i = 0; i < m_workernum; i++)
			{
				if (m_workerarr[i] != NULL)
				{
					delete m_workerarr[i];
				}
			}
			//删除堆区数组指针
			delete[] m_workerarr;
			m_workerarr = NULL;
			m_workernum = 0;
			m_fileisempty = true;
		}
		cout << "清空成功" << endl;
		
	}
	system("pause");
	system("cls");

}

