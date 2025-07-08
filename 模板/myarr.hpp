#pragma once
#include<iostream>
using namespace std;


template<class T>
class myarray
{
public:

	//�вι���
	myarray(int capacity)
	{
		m_capacity = capacity;
		m_size = 0;
		paddress = new T[m_capacity];//���ٵ�����
	}

	//��������
	myarray(const myarray& arr)
	{
		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		paddress = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			paddress[i] = arr.paddress[i];
		}
	}


	//"="����
	myarray& operator=(const myarray& arr)
	{

		//���ж������Ƿ�Ϊ�գ������Ϊ��Ҫ������ٸ�ֵ
		if (paddress != NULL)
		{
			delete[] paddress;
			m_size = 0;
			m_capacity = 0;
		}

		m_capacity = arr.m_capacity;
		m_size = arr.m_size;
		paddress = new T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			paddress[i] = arr.m_paddress[i];
		}
		return *this;
	}




	//��������
	~myarray()
	{
		if (paddress != NULL)
		{
			delete[] paddress;
			paddress = NULL;
			m_capacity = 0;
			m_size = 0;
		}
	}

	//β�巨
	void tailinsert(const T& val)
	{
		if (m_size == m_capacity)
		{
			return;
		}
		paddress[m_size] = val;
		m_size++;
	}

	//βɾ��
	void taildelete()
	{
		if (m_size == 0)
		{
			return;
		}
		m_size--;

	}

	//��������е�ǰԪ�ظ���
	int getsize()
	{
		return m_size;
	}

	//�����������
	int getcapacity()
	{
		return m_capacity;
	}

	//ͨ���±귽ʽ��������Ԫ��
	T& operator[](int index)
	{
		return paddress[index];
	}


private:
	T* paddress;
	int m_capacity;
	int m_size;
};