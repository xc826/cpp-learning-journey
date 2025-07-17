#include"teacher.h"


//Ĭ�Ϲ���
teacher::teacher()
{

}

//�вι��� (ְ����ţ�����������)
teacher::teacher(int tid, string name, string pwd)
{
	m_tid = tid;
	m_name = name;
	m_pwd = pwd;
}

//�˵�����
void teacher::per_menu()
{
	cout << "��ӭ��ʦ��" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void teacher::show_allorder()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ� ��" << of.m_orderdata[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderdata[i]["stuid"];
		cout << " ������" << of.m_orderdata[i]["stuname"];
		cout << " ������" << of.m_orderdata[i]["roomid"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "��ԤԼ";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else if (of.m_orderdata[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
}

//���ԤԼ
void teacher::valid_order()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�����ԤԼ��¼���£�" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderdata[i]["status"] == "1" )
		{
			v.push_back(i);
			cout << index++ << "�� ";
			cout << "ԤԼ���ڣ� ��" << of.m_orderdata[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ�ţ�" << of.m_orderdata[i]["stuid"];
			cout << " ������" << of.m_orderdata[i]["stuname"];
			cout << " ������" << of.m_orderdata[i]["roomid"];
			string status = " ״̬������� ";  
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼,0������" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderdata[v[select - 1]]["status"] = "-1";
				}
				of.update_order();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}