#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class manager :public worker
{
public:
	//���캯��
	manager(int age, string name, int did);

	//��ʾ��Ϣ
	void showinfo();

	//��ȡְλ��Ϣ
	string departmentname();
}; 
