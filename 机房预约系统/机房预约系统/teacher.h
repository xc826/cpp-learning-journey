#pragma once
#include"identity.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"
#include"globalfile.h"
#include<fstream>
#include"order_file.h"


class teacher :public identity
{
public:
	//Ĭ�Ϲ���
	teacher();

	//�вι��� (ְ����ţ�����������)
	teacher(int tid, string name, string pwd);

	//�˵�����
	virtual void per_menu();

	//�鿴����ԤԼ
	void show_allorder();

	//���ԤԼ
	void valid_order();

	int m_tid; //��ʦ���
};