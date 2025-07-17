#pragma once
#include"identity.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"
#include"globalfile.h"
#include<fstream>
#include"order_file.h"

class student:public identity
{
public:
	//默认构造函数
	student();

	//有参构造：学号、姓名、密码
	student(int id, string name, string pwd);

	//登录界面
	void per_menu();

	//申请预约
	void apply_order();

	//查看我的预约
	void show_myorder();

	//查看所有预约
	void show_allorder();
	
	//取消预约
	void cancel_order();

	//学生学号
	int m_sid;

	//机房容器
	vector<computer_room> vcom;

};