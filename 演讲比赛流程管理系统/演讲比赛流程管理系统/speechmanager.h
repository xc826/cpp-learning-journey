#pragma once//��ֹͷ�ļ��ظ�����
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
	//���캯��
	speechmanager();

	//�˵�����
	void show_menu();

	//�˳�ϵͳ
	void exit_system();

	//��ʼ������
	void init_speech();

	//����ѡ��
	void create_speaker();

	//��ǩ
	void speech_draw();

	//����
	void speech_contest();


	//��ʼ����
	void start_game();

	//��ʾ�������
	void show_score();

	//��¼��������
	void save_record();

	//��ȡ�����¼
	void read_record();

	//��ʾ��������
	void show_record();

	//��ռ�¼
	void clear_record();




	//��������
	~speechmanager();

	//��Ա����
	//��һ�ֱ���ѡ��
	vector<int> v1;

	//�ڶ��ֱ���ѡ��
	vector<int> v2;

	//ǰ����ѡ�ֱ��
	vector<int> v_victory;

	//ǰ����ѡ�ֱ�ź�ѡ��
	map<int, speaker> m;

	int m_index;

	bool file_is_empty;

	//�����¼
	map<int, vector<string>> m_record;
};
