#include"admin.h"

//Ĭ�Ϲ���
admin::admin()
{

}

//�вι���  ����Ա����������
admin::admin(string name, string pwd)
{
	m_name = name;
	m_pwd = pwd;

	init_vector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computer_room com;
	while (ifs >> com.m_cid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	cout << "��ǰ��������Ϊ�� " << vcom.size() << endl;
	ifs.close();
}

//ѡ��˵�
void admin::per_menu()
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�  
void admin::add_person()
{
	string filename;
	string tip;
	ofstream ofs;
	string errorTip; //�ظ�������ʾ

	int select = 0;

	while (true)
	{
		cout << "����������˺ŵ�����" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;


		cin >> select;

		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "������ѧ�ţ� ";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "������ְ����ţ�";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else
		{
			cout << "����������������룡" << endl;
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


	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	init_vector();
}

void printstudent(student& s)
{
	cout << "ѧ�ţ� " << s.m_sid << " ������ " << s.m_name << " ���룺" << s.m_pwd << endl;
}
void printteacher(teacher& t)
{
	cout << "ְ���ţ� " << t.m_tid << " ������ " << t.m_name << " ���룺" << t.m_pwd << endl;
}

//�鿴�˺�
void admin::show_person()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vst.begin(), vst.end(), printstudent);
	}
	else
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vte.begin(), vte.end(), printteacher);
	}
	system("pause");
	system("cls");
}


//�鿴������Ϣ
void admin::show_computer()
{
	cout << "������Ϣ���£� " << endl;
	for (vector<computer_room>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ� " << it->m_cid << " ������������� " << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}


//���ԤԼ��¼
void admin::clean_file()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void admin::init_vector()
{
	vst.clear();
	vte.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	student s;
	while (ifs >> s.m_sid && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vst.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vst.size() << endl;
	ifs.close(); //ѧ����ʼ��

	ifs.open(TEACHER_FILE, ios::in);
	teacher t;
	while (ifs >> t.m_tid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vte.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vte.size() << endl;
	ifs.close(); //��ʦ��ʼ��
}

//����ظ�    id�ţ�����
bool admin::check_repeat(int id,int type)
{
	if (type == 1)
	{//���ѧ��
		for (vector<student>::iterator it = vst.begin(); it != vst.end(); it++)
		{
			if (id == it->m_sid)
			{
				return true;
			}
		}
	}
	else
	{//����ʦ
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