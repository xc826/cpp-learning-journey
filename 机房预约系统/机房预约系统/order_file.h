#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalfile.h"
#include<fstream>


class order_file
{
public:

	//���캯��
	order_file();

	//����ԤԼ��¼
	void update_order();

	//��¼ԤԼ����
	int m_size;

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderdata;

};