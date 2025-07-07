#pragma once
#include<iostream>
using namespace std;


class worker
{
public:
	//显示个人信息
	virtual void showinfo() = 0;

	//获取岗位名称
	virtual string departmentname() = 0;



	int m_id;
	string m_name;
	int m_did;
};