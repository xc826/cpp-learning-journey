#include"employee.h"

employee::employee(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//显示信息
void employee::showinfo()
{
	cout << "职工编号：" << m_id << "\t" << "职工姓名：" << m_name << "\t" << "岗位：" << departmentname() <<"\t岗位职责：完成经理交给的任务" << endl;

}

//获取职位信息
string employee::departmentname()
{
	return string("员工");
}