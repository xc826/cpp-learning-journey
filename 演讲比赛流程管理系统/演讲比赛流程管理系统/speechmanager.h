#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

class speechmanager
{
public:
	//构造函数
	speechmanager();

	//菜单函数
	void show_menu();

	//退出系统
	void exit_system();

	//初始化属性
	void init_speech();

	//创建选手
	void create_speaker();

	//抽签
	void speech_draw();

	//比赛
	void speech_contest();


	//开始比赛
	void start_game();

	//显示比赛结果
	void show_score();

	//记录最终数据
	void save_record();

	//读取往届记录
	void read_record();

	//显示往届数据
	void show_record();

	//清空记录
	void clear_record();




	//析构函数
	~speechmanager();

	//成员属性
	//第一轮比赛选手
	vector<int> v1;

	//第二轮比赛选手
	vector<int> v2;

	//前三名选手编号
	vector<int> v_victory;

	//前三名选手编号和选手
	map<int, speaker> m;

	int m_index;

	bool file_is_empty;

	//往届记录
	map<int, vector<string>> m_record;
};
