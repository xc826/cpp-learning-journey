#include "workermanager.h"

workermanager::workermanager()
{

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		m_workernum = 0;
		m_workerarr = NULL;
		m_fileisempty = true;

		ifs.close();
		return;//��ֹ��ǰ���캯����ִ�У������أ�����ִ�к������ܵ��´���Ĵ���
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		m_workernum = 0;
		m_workerarr = NULL;
		m_fileisempty = true;

		ifs.close();
		return;
	}

	//��ȡְ������
	int num = get_workernum();
	//cout << "ְ�������ǣ�" << num << endl;
	m_workernum = num;

	//��ʼ��ְ������
	m_workerarr = new worker * [m_workernum];
	init_workerarr();

	//���Դ���
	//for (int i = 0; i < m_workernum; i++)
	//{
	//	cout << "ְ���ţ� " << this->m_workerarr[i]->m_id
	//		<< " ְ�������� " << this->m_workerarr[i]->m_name
	//		<< " ���ű�ţ� " << this->m_workerarr[i]->m_did << endl;
	//}
}



workermanager::~workermanager()
{
	//Ҫ�Ȱ�ÿһ�������е�Ԫ�����ͷŵ�����Ϊ����Ҳ��new�ڶ������ٵģ�Ȼ�����ͷŵ�����
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


//չʾ�˵�
void workermanager::showmenu()
{
	cout << "***********************************************************" << endl;
	cout << "*****************   ��ӭʹ��ְ������ϵͳ!  ****************" << endl;
	cout << "********************   0.�˳�����ϵͳ   *******************" << endl;
	cout << "********************   1.����ְ����Ϣ   *******************" << endl;
	cout << "********************   2.��ʾְ����Ϣ   *******************" << endl;
	cout << "********************   3.ɾ����ְְ��   *******************" << endl;
	cout << "********************   4.�޸�ְ����Ϣ   *******************" << endl;
	cout << "********************   5.����ְ����Ϣ   *******************" << endl;
	cout << "********************   6.���ձ������   *******************" << endl;
	cout << "********************   7.��������ĵ�   *******************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void workermanager::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//������Ա��
void workermanager::add_worker()
{
	cout << "������Ҫ���ӵ�ְ��������" << endl;
	int addnum;
	cin >> addnum;

	if (addnum > 0)
	{
		//����������Ĵ�С
		int newsize = m_workernum + addnum;

		//�����¿ռ�
		worker** newspace = new worker * [newsize];

		//��ԭ������ŵ��¿ռ�
		if (m_workerarr != NULL)
		{
			for (int i = 0; i < m_workernum; i++)
			{
				newspace[i] = m_workerarr[i];
			}
		}

		//����������
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dselect;

			cout << "������Ҫ���ӵĵ� " << i + 1 << " λ��ְ����ţ�" << endl;
			while (true)
			{
				cin >> id;
				int flag = isexist(id);
				if (flag != -1)
				{
					cout << "�������ְ������Ѵ��ڣ�����������!" << endl;
				}
				else
				{
					break;
				}
			}
			cout << "������Ҫ���ӵĵ� " << i + 1 << " λ��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ��Ҫ���ӵĵ� " << i + 1 << " λ��ְ���ĸ�λ��" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
		//�ͷ�ԭ�пռ�
		delete[] m_workerarr;
		//�����¿ռ��ָ��
		m_workerarr = newspace;
		//�����µ�Ա������
		m_workernum = newsize;
		m_fileisempty = false;
		cout << "�ɹ���� " << addnum << " λ��ְ����" << endl;

		//�������ݵ��ļ���
		save();


	}
	else
	{
		cout << "�������" << endl;
	}

	system("pause");
	system("cls");
}

//�����ļ�
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

//��ʾְ��
void workermanager::showworker()
{
	if (m_fileisempty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
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

//ɾ��ְ��
void workermanager::del_worker()
{
	if (m_fileisempty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ְ����ţ�" << endl;
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

			//��ɾ���������ͬ���������ļ���
			save();
			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "Ҫɾ����Ա�������ڣ�ɾ��ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
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

//�޸�ְ��
void workermanager::modify_worker()
{
	if (m_fileisempty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ְ����ţ�" << endl;
		int id;
		cin >> id;
		int flag = isexist(id);
		if (flag != -1)
		{
			delete m_workerarr[flag];
			int new_id = 0;
			string new_name = "";
			int new_did = 0;
			cout << "�������޸ĺ��ְ����ְ�����" << endl;
			cin >> new_id;

			cout << "�������޸ĺ��ְ����ְ������" << endl;
			cin >> new_name;

			cout << "�������޸ĺ��ְ����ְ����λ" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;

			//��ɾ���������ͬ���������ļ���
			save();

		}
		else
		{
			cout << "Ҫ�޸ĵ�Ա�������ڣ��޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void workermanager::find_worker()
{
	if (m_fileisempty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			cout << "������Ҫ���ҵ�ְ����ְ����ţ�" << endl;
			int id;
			cin >> id;
			int flag = isexist(id);
			if (flag != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				m_workerarr[flag]->showinfo();
			}
			else
			{
				cout << "����ʧ�ܣ����Ҳ����ڣ�" << endl;

			}
		}
		else if (select == 2)
		{
			//�������������ˣ���˺�ǰ�水��Ų��ҷ�ʽ��������Ҫ���������и����ֵ��ˣ�Ȼ���ӡ����Ϣ
			cout << "������Ҫ�޸ĵ�ְ����ְ��������" << endl;
			string name;
			cin >> name;			
			bool issame = false;
			for (int j = 0; j < m_workernum; j++)
			{
				if (m_workerarr[j]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << m_workerarr[j]->m_id << " ��ְ����Ϣ����" << endl;
					m_workerarr[j]->showinfo();
					issame = true;
				}
	
			}
			if (issame == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else
		{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����
void workermanager::sort_worker()
{
	if (m_fileisempty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_workernum; i++)
		{
			int minormax = i;//�������ֵ������Сֵ�±�
			for (int j = i + 1; j < m_workernum; j++)
			{
				if (select == 1)//����
				{
					if (m_workerarr[minormax]->m_id > m_workerarr[j]->m_id)
					{
						minormax = j;
					}
				}
				else//����
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
		cout << "����ɹ����������Ϊ��" << endl;
		save();//�ɼӿɲ��ӣ�����֮���ļ���Ҳ�ź�����
		showworker();
		

	}
}

//����ļ�
void workermanager::clean_file()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs;
		ofs.open(filename, ios::trunc);//���ַ�ʽ����ɾ���ļ����ݣ������´���
		ofs.close();

		if (m_workerarr != NULL)
		{
			//ɾ������ÿ��ְ������
			for (int i = 0; i < m_workernum; i++)
			{
				if (m_workerarr[i] != NULL)
				{
					delete m_workerarr[i];
				}
			}
			//ɾ����������ָ��
			delete[] m_workerarr;
			m_workerarr = NULL;
			m_workernum = 0;
			m_fileisempty = true;
		}
		cout << "��ճɹ�" << endl;
		
	}
	system("pause");
	system("cls");

}

