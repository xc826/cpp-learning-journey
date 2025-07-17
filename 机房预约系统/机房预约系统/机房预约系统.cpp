#include<iostream>
using namespace std;
#include<fstream>
#include"globalfile.h"
#include"identity.h"
#include"student.h"
#include"admin.h"
#include"teacher.h"

void admin_menu(identity*& ad)
{
	while (true)
	{
		//调用子类菜单
		ad->per_menu();

		//将父类指针强转为子类指针，以便访问子类独有成员
		admin* adm = (admin*)ad;

		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
			//cout << "添加账号" << endl;
			adm->add_person();
		}
		else if (select == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			adm->show_person();
		}
		else if (select == 3)//查看机房
		{
			//cout << "查看机房" << endl;
			adm->show_computer();
		}
		else if (select == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			adm->clean_file();
		}
		else
		{
			delete ad;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void student_menu(identity*& st)
{
	while (true)
	{
		//调用子类菜单
		st->per_menu();

		//将父类指针强转为子类指针，以便访问子类独有成员
		student*  stu= (student*)st;

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->apply_order();
		}
		else if (select == 2)//查看我的预约
		{
			//cout << "查看账号" << endl;
			stu->show_myorder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->show_allorder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancel_order();
		}
		else
		{
			delete st;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacher_menu(identity*& te)
{
	while (true)
	{
		//调用子类菜单
		te->per_menu();

		//将父类指针强转为子类指针，以便访问子类独有成员
		teacher* tea = (teacher*)te;

		int select = 0;
		cin >> select;

		if (select == 1)//查看所有预约
		{
			tea->show_allorder();
		}
		else if (select == 2)//审核预约
		{
			tea->valid_order();
		}
		else
		{
			delete te;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void login_in(string file_name, int type)
{
	identity* person = NULL;

	ifstream ifs;
	ifs.open(file_name, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id=0;
	string name;
	string pwd;

	if (type == 1)//学生登录
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工编号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//学生登录验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");	
				person = new student(id, name, pwd);
				//进入学生身份的子菜单
				student_menu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//进入教师的子菜单
				teacher_menu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证

		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new admin(name, pwd);
				//进入管理员的子菜单
				admin_menu(person);

				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;

}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学    生           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;

		switch (select)
		{
		case 1://学生身份
			login_in(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			login_in(TEACHER_FILE, 2);

			break;
		case 3://管理员身份
			login_in(ADMIN_FILE, 3);

			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
		//system("pause");

		//return 0;
	}
}