#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class boss :public worker
{
public:
	//���캯��
	boss(int age, string name, int did);

	//��ʾ��Ϣ
	void showinfo();

	//��ȡְλ��Ϣ
	string departmentname();
};