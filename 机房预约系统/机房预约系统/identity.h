#pragma once
#include<iostream>
using namespace std;

//��ݳ������
class identity
{
public:
	//�����˵������麯��
	virtual void per_menu() = 0;


	string m_name;
	string m_pwd;
};