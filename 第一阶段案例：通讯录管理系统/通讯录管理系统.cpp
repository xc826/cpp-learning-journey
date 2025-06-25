#include <iostream>
using namespace std;
#define max 1000

//�˵�����
void menu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

}
//��ϵ�˽ṹ��
struct person
{
	string p_name;
	int p_gender;
	int p_age;
	string p_phone;
	string p_address;
};

//ͨѶ¼�ṹ��
struct addressbook
{
	person parr[max];
	int p_size;

};

//�����ϵ�˺���
void addperson(addressbook* adr)
{
	if (adr->p_size == max)
	{
		cout << "ͨѶ¼���������������" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		adr->parr[adr->p_size].p_name = name;
		int gender;
		cout << "�������Ա�" << endl;
		cout << "1����" << endl;
		cout << "2��Ů" << endl;
		cin >> gender;
		while (true)
		{
			if (gender == 1 || gender == 2)
			{
				adr->parr[adr->p_size].p_gender = gender;
				break;
			}
			cout << "������������������" << endl;
		}
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		adr->parr[adr->p_size].p_age = age;
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		adr->parr[adr->p_size].p_phone = phone;
		string address;
		cout << "�������ͥ��ַ��" << endl;
		cin >> address;
		adr->parr[adr->p_size].p_address = address;

		adr->p_size++;//����ͨѶ¼����

		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����

	}
}
//��ʾ��ϵ��
void showbook(addressbook* adr)
{
	if (adr->p_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < adr->p_size; i++)
		{
			cout << "������" << adr->parr[i].p_name << "\t";
			cout << "�Ա�" << (adr->parr[i].p_gender == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << adr->parr[i].p_age << "\t";
			cout << "��ϵ�绰��" << adr->parr[i].p_phone << "\t";
			cout << "������" << adr->parr[i].p_address << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
int isexist(addressbook* adr, string name)
{
	for (int i = 0; i < adr->p_size; i++)
	{
		if (adr->parr[i].p_name == name)
		{
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void delete_person(addressbook* adr)
{
	string name;
	cout << "��������Ҫѡ���������ϵ��������" << endl;
	cin >> name;
	//����ע��һ�£�������������棬��������adr����ָ�룬���Կ���ֱ�Ӵ���isexist������Ҫ�ټ�ȡַ��&��
	int re = isexist(adr, name);
	if (re != -1)
	{
		for (int i = re; i < adr->p_size; i++)
		{
			adr->parr[i] = adr->parr[i + 1];
		}
		adr->p_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "��Ҫɾ������ϵ�˲�����" << endl;
	}
	system("pause");
	system("cls");
}
	
//������ϵ��
void find_person(addressbook* adr)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int re = isexist(adr, name);
	if (re != -1)
	{
		cout << "������" << adr->parr[re].p_name << "\t";
		cout << "�Ա�" << (adr->parr[re].p_gender == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << adr->parr[re].p_age << "\t";
		cout << "��ϵ�绰��" << adr->parr[re].p_phone << "\t";
		cout << "������" << adr->parr[re].p_address << endl;
	}
	else
	{
		cout << "��Ҫ���ҵ���ϵ�˲�����" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modify_person(addressbook* adr)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int re = isexist(adr, name);
	if (re != -1)
	{
		cout << "��������Ҫ�޸ĵĲ��֣�" << endl;
		cout << "1���޸�����" << endl;
		cout << "2���޸��Ա�" << endl;
		cout << "3���޸�����" << endl;
		cout << "4���޸���ϵ�绰" << endl;
		cout << "5���޸ļ�ͥסַ" << endl;
		int part;
		cin >> part;
		switch (part)
		{
		case 1:
		{
			string m_name;
			cout << "�������޸ĺ��������" << endl;
			cin >> m_name;
			adr->parr[re].p_name = m_name;
			break;
		}
		case 2:
		{
			int m_gender;
			cout << "�������޸ĺ���Ա�" << endl;
			cout << "1 -- ��" << endl;
			cout << "2 -- Ů" << endl;
			while (true)
			{
				cin >> m_gender;
				if (m_gender == 1 || m_gender == 2)
				{
					adr->parr[re].p_gender = m_gender;
					break;
				}
				cout << "������������������";
			}
			break;
		}
		case 3:
		{
			int m_age;
			cout << "�������޸ĺ�����䣺" << endl;
			cin >> m_age;
			adr->parr[re].p_age = m_age;
			break;
		}
		case 4:
		{
			string m_phone;
			cout << "�������޸ĺ����ϵ��ʽ��" << endl;
			cin >> m_phone;
			adr->parr[re].p_phone = m_phone;
			break;
		}
		case 5:
		{
			string m_address;
			cout << "�������޸ĺ�ļ�ͥ��ַ��" << endl;
			cin >> m_address;
			adr->parr[re].p_address = m_address;
			break;
		}
		default:break;
		}

	}
	else
	{
		cout << "��Ҫ�޸ĵ���ϵ�˲�����" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��

void clear_person(addressbook* adr)
{
	adr->p_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


int main()
{

	addressbook adr;
	adr.p_size = 0;


	while (true)
	{
		menu();
		int select;
		cout << "��ѡ����Ҫִ�еĹ��ܣ�" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&adr);
			break;
		case 2:
			showbook(&adr);
			break;
		case 3:
			delete_person(&adr);
			break;
		case 4:
			find_person(&adr);
			break;
		case 5:
			modify_person(&adr);
			break;
		case 6:
			clear_person(&adr);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:break;
		}
	}


	system("pause");
	return 0;
}