#pragma once
#include"identity.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"
#include"globalfile.h"
#include<fstream>
#include"order_file.h"

class student:public identity
{
public:
	//Ĭ�Ϲ��캯��
	student();

	//�вι��죺ѧ�š�����������
	student(int id, string name, string pwd);

	//��¼����
	void per_menu();

	//����ԤԼ
	void apply_order();

	//�鿴�ҵ�ԤԼ
	void show_myorder();

	//�鿴����ԤԼ
	void show_allorder();
	
	//ȡ��ԤԼ
	void cancel_order();

	//ѧ��ѧ��
	int m_sid;

	//��������
	vector<computer_room> vcom;

};