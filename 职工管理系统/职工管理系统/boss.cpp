#include"boss.h"

boss::boss(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//��ʾ��Ϣ
void boss::showinfo()
{
	cout << "ְ����ţ�" << m_id << "\t" << "ְ��������" << m_name << "\t" << "��λ��" << departmentname() << "\t��λְ�𣺹���˾��������" << endl;

}

//��ȡְλ��Ϣ
string boss::departmentname()
{
	return string("�ϰ�");
}