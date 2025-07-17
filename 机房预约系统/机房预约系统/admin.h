#pragma once
#include"identity.h"
#include"globalfile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include<vector>
#include<algorithm>
#include"computer_room.h"

class admin :public identity
{
public:
	//默认构造
	admin();

	//有参构造  管理员姓名，密码
	admin(string name, string pwd);

	//选择菜单
	virtual void per_menu();

	//添加账号  
	void add_person();

	//查看账号
	void show_person();

	//查看机房信息
	void show_computer();

	//清空预约记录
	void clean_file();

	//初始化容器
	void init_vector();

	//检测重复    id号，类型
	bool check_repeat(int id,int type);

	//学生容器
	vector<student> vst;

	//教师容器
	vector<teacher> vte;

	//电脑容器
	vector<computer_room> vcom;

};