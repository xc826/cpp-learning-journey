#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define filename "workerfile.txt"

class workermanager
{
public:
	workermanager();

	~workermanager();

	//��ʾ�˵�
	void showmenu();

	//�˳�ϵͳ
	void exitsystem();

	//���ְ��
	void add_worker();

	//�����ļ�
	void save();

	//��ȡ�ļ���ְ����Ŀ
	int get_workernum();

	//��ʼ��ְ��
	void init_workerarr();

	//ɾ��ְ��
	void del_worker();

	//�ж�ְ���Ƿ����
	int isexist(int id);

	//�޸�ְ��
	void modify_worker();

	//����ְ��
	void find_worker();

	//����
	void sort_worker();

	//����ļ�
	void clean_file();

	//��ʾְ��
	void showworker();

	bool m_fileisempty;
	int m_workernum;
	worker** m_workerarr;//�Ա����new�ڶ������ٵĲ��������鲢ά��


};