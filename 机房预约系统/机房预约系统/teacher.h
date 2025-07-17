#pragma once
#include"identity.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"
#include"globalfile.h"
#include<fstream>
#include"order_file.h"


class teacher :public identity
{
public:
	//默认构造
	teacher();

	//有参构造 (职工编号，姓名，密码)
	teacher(int tid, string name, string pwd);

	//菜单界面
	virtual void per_menu();

	//查看所有预约
	void show_allorder();

	//审核预约
	void valid_order();

	int m_tid; //教师编号
};