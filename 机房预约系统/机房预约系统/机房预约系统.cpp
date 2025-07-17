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
		//��������˵�
		ad->per_menu();

		//������ָ��ǿתΪ����ָ�룬�Ա����������г�Ա
		admin* adm = (admin*)ad;

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			adm->add_person();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			adm->show_person();
		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			adm->show_computer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			adm->clean_file();
		}
		else
		{
			delete ad;
			cout << "ע���ɹ�" << endl;
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
		//��������˵�
		st->per_menu();

		//������ָ��ǿתΪ����ָ�룬�Ա����������г�Ա
		student*  stu= (student*)st;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->apply_order();
		}
		else if (select == 2)//�鿴�ҵ�ԤԼ
		{
			//cout << "�鿴�˺�" << endl;
			stu->show_myorder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->show_allorder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancel_order();
		}
		else
		{
			delete st;
			cout << "ע���ɹ�" << endl;
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
		//��������˵�
		te->per_menu();

		//������ָ��ǿתΪ����ָ�룬�Ա����������г�Ա
		teacher* tea = (teacher*)te;

		int select = 0;
		cin >> select;

		if (select == 1)//�鿴����ԤԼ
		{
			tea->show_allorder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->valid_order();
		}
		else
		{
			delete te;
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id=0;
	string name;
	string pwd;

	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;


	if (type == 1)
	{
		//ѧ����¼��֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");	
				person = new student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				student_menu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//�����ʦ���Ӳ˵�
				teacher_menu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤

		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new admin(name, pwd);
				//�������Ա���Ӳ˵�
				admin_menu(person);

				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;

}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;

		switch (select)
		{
		case 1://ѧ�����
			login_in(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			login_in(TEACHER_FILE, 2);

			break;
		case 3://����Ա���
			login_in(ADMIN_FILE, 3);

			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		//system("pause");

		//return 0;
	}
}