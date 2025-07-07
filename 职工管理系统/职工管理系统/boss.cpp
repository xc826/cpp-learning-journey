#include"boss.h"

boss::boss(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//显示信息
void boss::showinfo()
{
	cout << "职工编号：" << m_id << "\t" << "职工姓名：" << m_name << "\t" << "岗位：" << departmentname() << "\t岗位职责：管理公司所有事务" << endl;

}

//获取职位信息
string boss::departmentname()
{
	return string("老板");
}