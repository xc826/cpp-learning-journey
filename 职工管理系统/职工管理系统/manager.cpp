#include"manager.h"

manager::manager(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//��ʾ��Ϣ
void manager::showinfo()
{
	cout << "ְ����ţ�" << m_id << "\t" << "ְ��������" << m_name << "\t" << "��λ��" << departmentname() << "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;

}

//��ȡְλ��Ϣ
string manager::departmentname()
{
	return string("����");
}