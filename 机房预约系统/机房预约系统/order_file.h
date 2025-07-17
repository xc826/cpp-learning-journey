#pragma once
#include<iostream>
using namespace std;
#include <map>
#include "globalfile.h"
#include<fstream>


class order_file
{
public:

	//构造函数
	order_file();

	//更新预约记录
	void update_order();

	//记录预约条数
	int m_size;

	//记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
	map<int, map<string, string>> m_orderdata;

};