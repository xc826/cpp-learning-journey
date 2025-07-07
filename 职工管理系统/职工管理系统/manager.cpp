#include"manager.h"

manager::manager(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//显示信息
void manager::showinfo()
{
	cout << "职工编号：" << m_id << "\t" << "职工姓名：" << m_name << "\t" << "岗位：" << departmentname() << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;

}

//获取职位信息
string manager::departmentname()
{
	return string("经理");
}