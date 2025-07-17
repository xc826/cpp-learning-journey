#include"student.h"

//默认构造函数
student::student()
{

}

//有参构造：学号、姓名、密码
student::student(int id, string name, string pwd)
{
	m_sid = id;
	m_name = name;
	m_pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computer_room c;
	while (ifs >> c.m_cid && ifs >> c.m_maxnum)
	{
		vcom.push_back(c);
	}

	ifs.close();
}

//登录界面
void student::per_menu()
{
	cout << "欢迎学生代表：" << this->m_name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//申请预约
void student::apply_order()
{
	int date=0;
	int interval=0;
	int room = 0;

	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;

	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_cid << "号机房的容量为：" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << m_sid << " ";
	ofs << "stuname:" << m_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//查看我的预约
void student::show_myorder()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == m_sid)
		{
			cout << "预约日期： 周" << of.m_orderdata[i]["date"];
			cout << " 时段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderdata[i]["roomid"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (of.m_orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderdata[i]["status"] == "2")
			{
				status += "已预约";
			}
			else if (of.m_orderdata[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else if (of.m_orderdata[i]["status"] == "0")
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");


}

//查看所有预约
void student::show_allorder()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期： 周" << of.m_orderdata[i]["date"];
		cout << " 时段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderdata[i]["stuid"];
		cout << " 姓名：" << of.m_orderdata[i]["stuname"];
		cout << " 机房：" << of.m_orderdata[i]["roomid"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "已预约";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else if (of.m_orderdata[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//取消预约
void student::cancel_order()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == m_sid)
		{
			if (of.m_orderdata[i]["status"]== "1" || of.m_orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期： 周" << of.m_orderdata[i]["date"];
				cout << " 时段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_orderdata[i]["roomid"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderdata[v[select - 1]]["status"] = "0";
				of.update_order();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}