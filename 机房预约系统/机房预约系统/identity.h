#pragma once
#include<iostream>
using namespace std;

//身份抽象基类
class identity
{
public:
	//操作菜单，纯虚函数
	virtual void per_menu() = 0;


	string m_name;
	string m_pwd;
};