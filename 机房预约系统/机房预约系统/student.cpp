#include"student.h"

//Ĭ�Ϲ��캯��
student::student()
{

}

//�вι��죺ѧ�š�����������
student::student(int id, string name, string pwd)
{
	m_sid = id;
	m_name = name;
	m_pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computer_room c;
	while (ifs >> c.m_cid && ifs >> c.m_maxnum)
	{
		vcom.push_back(c);
	}

	ifs.close();
}

//��¼����
void student::per_menu()
{
	cout << "��ӭѧ������" << this->m_name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void student::apply_order()
{
	int date=0;
	int interval=0;
	int room = 0;

	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;

	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_cid << "�Ż���������Ϊ��" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

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

//�鿴�ҵ�ԤԼ
void student::show_myorder()
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
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == m_sid)
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderdata[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
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
	}
	system("pause");
	system("cls");


}

//�鿴����ԤԼ
void student::show_allorder()
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

//ȡ��ԤԼ
void student::cancel_order()
{
	order_file of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderdata[i]["stuid"].c_str()) == m_sid)
		{
			if (of.m_orderdata[i]["status"]== "1" || of.m_orderdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderdata[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderdata[i]["roomid"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼,0������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}