#pragma once
#include"identity.h"
#include"globalfile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"

class admin :public identity
{
public:
	//Ĭ�Ϲ���
	admin();

	//�вι���  ����Ա����������
	admin(string name, string pwd);

	//ѡ��˵�
	virtual void per_menu();

	//����˺�  
	void add_person();

	//�鿴�˺�
	void show_person();

	//�鿴������Ϣ
	void show_computer();

	//���ԤԼ��¼
	void clean_file();

	//��ʼ������
	void init_vector();

	//����ظ�    id�ţ�����
	bool check_repeat(int id,int type);

	//ѧ������
	vector<student> vst;

	//��ʦ����
	vector<teacher> vte;

	//��������
	vector<computer_room> vcom;

};