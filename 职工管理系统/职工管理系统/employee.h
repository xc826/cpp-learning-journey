#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class employee :public worker
{
public:
	//构造函数
	employee(int age,string name,int did );

	//显示信息
	void showinfo();
	
	//获取职位信息
	string departmentname();
};