#include"employee.h"

employee::employee(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}

//��ʾ��Ϣ
void employee::showinfo()
{
	cout << "ְ����ţ�" << m_id << "\t" << "ְ��������" << m_name << "\t" << "��λ��" << departmentname() <<"\t��λְ����ɾ�����������" << endl;

}

//��ȡְλ��Ϣ
string employee::departmentname()
{
	return string("Ա��");
}