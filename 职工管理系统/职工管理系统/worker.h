#pragma once
#include<iostream>
using namespace std;


class worker
{
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;

	//��ȡ��λ����
	virtual string departmentname() = 0;



	int m_id;
	string m_name;
	int m_did;
};