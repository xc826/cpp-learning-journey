#include"speechmanager.h"

//���캯��
speechmanager::speechmanager()
{
	init_speech();

	create_speaker();

	//��ȡ��������
	read_record();
}


//�˵�����
void speechmanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void speechmanager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void speechmanager::init_speech()
{
	v1.clear();
	v2.clear();
	v_victory.clear();
	m.clear();
	m_index = 1;
	m_record.clear();
}

//����ѡ��
void speechmanager::create_speaker()
{
	for (int i = 0; i < 12; i++)
	{
		string nameseed = "ABCDEFGHIJKL";
		speaker sp;
		sp.m_name = "ѡ��";
		sp.m_name += nameseed[i];
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		v1.push_back(i + 10001);

		m.insert(make_pair(i + 10001, sp));
	}
}

//��ǩ
void speechmanager::speech_draw()
{
	cout << "�� << " << m_index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (m_index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
		{
			cout << *it1 << " ";
		}
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); it2++)
		{
			cout << *it2 << " ";
		}
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;

}

//����
void speechmanager::speech_contest()
{
	cout << "------------- ��" << this->m_index << "����ʽ������ʼ��------------- " << endl;
	vector<int> v_con;
	multimap<double, int, greater<double>> mm;//��ʱ���������ڴ洢���ƽ���ֺ�����ݣ��Լ�ȡǰ6��
	int num = 0;
	if (m_index == 1)
	{
		v_con = v1;
	}
	else
	{
		v_con = v2;
	}

	for (vector<int>::iterator it = v_con.begin(); it != v_con.end(); it++)
	{
		num++;
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);

		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());

		d.pop_back();
		d.pop_front();

		double ave = (accumulate(d.begin(), d.end(), 0.0f)) / d.size();
		//cout << ave<<" ";

		m[*it].score[m_index - 1] = ave;//��ƽ���ִ���map����

		mm.insert(make_pair(ave, *it));

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = mm.begin(); it != mm.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << m[it->second].m_name << " �ɼ���" << m[it->second].score[m_index - 1] << endl;
			}

			//ȡǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = mm.begin(); it != mm.end() && count < 3; it++, count++)
			{
				if (m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v_victory.push_back(it->second);
				}
			}

			mm.clear();
			//cout << endl;

		}

	}
	cout << "------------- ��" << this->m_index << "�ֱ������  ------------- " << endl;
	system("pause");
}

//��ʾ�������
void speechmanager::show_score()
{
	cout << "---------��" << this->m_index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int> v;
	if (m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v_victory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m[*it].m_name << " �÷֣� " << m[*it].score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	show_menu();
}

//��¼��������
void speechmanager::save_record()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++)
	{
		ofs << *it << "," << m[*it].score[1] << ",";
	}

	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;

	file_is_empty = false;
}

//��ʼ����
void speechmanager::start_game()
{
	//��һ��
	//��ǩ
	speech_draw();

	//����
	speech_contest();

	//��ʾ�������
	show_score();


	//�ڶ���
	m_index++;
	//��ǩ
	speech_draw();


	//����
	speech_contest();


	//��ʾ�������
	show_score();


	//���汾��������ս��
	save_record();

	//���ñ�������ȡ��¼
	init_speech();

	create_speaker();

	read_record();//��ʾ��ʱ����һ������Ҫ����ȡ֮��ѡ��2�������Ż���ʾ


	cout << "��������ѽ���" << endl;
	system("pause");
	system("cls");
}

//��ȡ�����¼
void speechmanager::read_record()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		this->file_is_empty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->file_is_empty = true;
		//cout << "�ļ�Ϊ�գ�" << endl;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	file_is_empty = false;
	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	int index = 0;
	string data;
	while (ifs >> data)
	{
		vector<string> v;
		int start = 0;
		int pos = -1;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		m_record.insert(make_pair(index, v));
		index++;

	}
	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_record.begin(); it != m_record.end(); it++)
	//{
	//	cout << it->second[0] << " " << it->second[1];
	//}

}

void speechmanager::show_record()
{
	if (file_is_empty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_record[i][0] << " �÷֣�" << this->m_record[i][1] << " "
				"�Ǿ���ţ�" << this->m_record[i][2] << " �÷֣�" << this->m_record[i][3] << " "
				"������ţ�" << this->m_record[i][4] << " �÷֣�" << this->m_record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

//��ռ�¼
void speechmanager::clear_record()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		int select = 0;
		cin >> select;

		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		init_speech();

		create_speaker();

		read_record();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

//��������
speechmanager::~speechmanager()
{

}