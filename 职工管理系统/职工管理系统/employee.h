#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class employee :public worker
{
public:
	//���캯��
	employee(int age,string name,int did );

	//��ʾ��Ϣ
	void showinfo();
	
	//��ȡְλ��Ϣ
	string departmentname();
};