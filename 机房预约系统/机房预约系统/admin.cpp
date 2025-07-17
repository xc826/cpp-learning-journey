#include"admin.h"

//默认构造
admin::admin()
{

}

//有参构造  管理员姓名，密码
admin::admin(string name, string pwd)
{
	m_name = name;
	m_pwd = pwd;

	init_vector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computer_room com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	cout << "当前机房数量为： " << vcom.size() << endl;
	ifs.close();
}

//选择菜单
void admin::per_menu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号  
void admin::add_person()
{
	string filename;
	string tip;
	ofstream ofs;
	string errorTip; //重复错误提示

	int select = 0;

	while (true)
	{
		cout << "请输入添加账号的类型" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;


		cin >> select;

		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "请输入学号： ";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "请输入职工编号：";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else
		{
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
			per_menu();
			//break;
		}
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = check_repeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}


	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//调用初始化容器接口，重新获取文件中的数据
	init_vector();
}

void printstudent(student& s)
{
	cout << "学号： " << s.m_sid << " 姓名： " << s.m_name << " 密码：" << s.m_pwd << endl;
}
void printteacher(teacher& t)
{
	cout << "职工号： " << t.m_tid << " 姓名： " << t.m_name << " 密码：" << t.m_pwd << endl;
}

//查看账号
void admin::show_person()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vst.begin(), vst.end(), printstudent);
	}
	else
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vte.begin(), vte.end(), printteacher);
	}
	system("pause");
	system("cls");
}


//查看机房信息
void admin::show_computer()
{
	cout << "机房信息如下： " << endl;
	for (vector<computer_room>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号： " << it->m_cid << " 机房最大容量： " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}


//清空预约记录
void admin::clean_file()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void admin::init_vector()
{
	vst.clear();
	vte.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	student s;
	while (ifs >> s.m_sid && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vst.push_back(s);
	}
	cout << "当前学生数量为： " << vst.size() << endl;
	ifs.close(); //学生初始化

	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	while (ifs >> t.m_tid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vte.push_back(t);
	}
	cout << "当前教师数量为： " << vte.size() << endl;
	ifs.close(); //教师初始化
}

//检测重复    id号，类型
bool admin::check_repeat(int id,int type)
{
	if (type == 1)
	{//检测学生
		for (vector<student>::iterator it = vst.begin(); it != vst.end(); it++)
		{
			if (id == it->m_sid)
			{
				return true;
			}
		}
	}
	else
	{//检测教师
		for (vector<teacher>::iterator it = vte.begin(); it != vte.end(); it++)
		{
			if (id == it->m_tid)
			{
				return true;
			}
		}
	}
	return false;
}