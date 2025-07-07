#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define filename "workerfile.txt"

class workermanager
{
public:
	workermanager();

	~workermanager();

	//显示菜单
	void showmenu();

	//退出系统
	void exitsystem();

	//添加职工
	void add_worker();

	//保存文件
	void save();

	//获取文件内职工数目
	int get_workernum();

	//初始化职工
	void init_workerarr();

	//删除职工
	void del_worker();

	//判断职工是否存在
	int isexist(int id);

	//修改职工
	void modify_worker();

	//查找职工
	void find_worker();

	//排序
	void sort_worker();

	//清空文件
	void clean_file();

	//显示职工
	void showworker();

	bool m_fileisempty;
	int m_workernum;
	worker** m_workerarr;//以便接收new在堆区开辟的不定长数组并维护


};