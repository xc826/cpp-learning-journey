#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class boss :public worker
{
public:
	//构造函数
	boss(int age, string name, int did);

	//显示信息
	void showinfo();

	//获取职位信息
	string departmentname();
};