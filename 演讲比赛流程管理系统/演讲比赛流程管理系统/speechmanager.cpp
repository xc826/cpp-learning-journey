#include"speechmanager.h"

//构造函数
speechmanager::speechmanager()
{
	init_speech();

	create_speaker();

	//读取往届数据
	read_record();
}


//菜单函数
void speechmanager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void speechmanager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//初始化属性
void speechmanager::init_speech()
{
	v1.clear();
	v2.clear();
	v_victory.clear();
	m.clear();
	m_index = 1;
	m_record.clear();
}

//创建选手
void speechmanager::create_speaker()
{
	for (int i = 0; i < 12; i++)
	{
		string nameseed = "ABCDEFGHIJKL";
		speaker sp;
		sp.m_name = "选手";
		sp.m_name += nameseed[i];
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		v1.push_back(i + 10001);

		m.insert(make_pair(i + 10001, sp));
	}
}

//抽签
void speechmanager::speech_draw()
{
	cout << "第 << " << m_index << " >> 轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

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

//比赛
void speechmanager::speech_contest()
{
	cout << "------------- 第" << this->m_index << "轮正式比赛开始：------------- " << endl;
	vector<int> v_con;
	multimap<double, int, greater<double>> mm;//临时容器，用于存储求得平均分后的数据，以及取前6名
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

		m[*it].score[m_index - 1] = ave;//将平均分存入map容器

		mm.insert(make_pair(ave, *it));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = mm.begin(); it != mm.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << m[it->second].m_name << " 成绩：" << m[it->second].score[m_index - 1] << endl;
			}

			//取前三名
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
	cout << "------------- 第" << this->m_index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}

//显示比赛结果
void speechmanager::show_score()
{
	cout << "---------第" << this->m_index << "轮晋级选手信息如下：-----------" << endl;
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
		cout << "选手编号：" << *it << " 姓名： " << m[*it].m_name << " 得分： " << m[*it].score[this->m_index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	show_menu();
}

//记录最终数据
void speechmanager::save_record()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++)
	{
		ofs << *it << "," << m[*it].score[1] << ",";
	}

	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已经保存" << endl;

	file_is_empty = false;
}

//开始比赛
void speechmanager::start_game()
{
	//第一轮
	//抽签
	speech_draw();

	//比赛
	speech_contest();

	//显示晋级结果
	show_score();


	//第二轮
	m_index++;
	//抽签
	speech_draw();


	//比赛
	speech_contest();


	//显示晋级结果
	show_score();


	//保存本届比赛最终结果
	save_record();

	//重置比赛，获取记录
	init_speech();

	create_speaker();

	read_record();//显示的时候，这一行最重要，读取之后，选择2，这样才会显示


	cout << "本届比赛已结束" << endl;
	system("pause");
	system("cls");
}

//读取往届记录
void speechmanager::read_record()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		this->file_is_empty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->file_is_empty = true;
		//cout << "文件为空！" << endl;
		ifs.close();
		return;
	}

	//文件不为空
	file_is_empty = false;
	ifs.putback(ch);//读取的单个字符放回去

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
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_record[i][0] << " 得分：" << this->m_record[i][1] << " "
				"亚军编号：" << this->m_record[i][2] << " 得分：" << this->m_record[i][3] << " "
				"季军编号：" << this->m_record[i][4] << " 得分：" << this->m_record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

//清空记录
void speechmanager::clear_record()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
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

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

//析构函数
speechmanager::~speechmanager()
{

}