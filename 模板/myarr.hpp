#pragma once
#include<iostream>
using namespace std;


template<class T>
class myarray
{
public:

	//有参构造
	myarray(int capacity)
	{
		m_capacity = capacity;
		m_size = 0;
		paddress = new T[m_capacity];//开辟到堆区
	}

	//拷贝构造
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


	//"="重载
	myarray& operator=(const myarray& arr)
	{

		//先判断数组是否为空，如果不为空要先清空再赋值
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




	//析构函数
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

	//尾插法
	void tailinsert(const T& val)
	{
		if (m_size == m_capacity)
		{
			return;
		}
		paddress[m_size] = val;
		m_size++;
	}

	//尾删法
	void taildelete()
	{
		if (m_size == 0)
		{
			return;
		}
		m_size--;

	}

	//获得数组中当前元素个数
	int getsize()
	{
		return m_size;
	}

	//获得数组容量
	int getcapacity()
	{
		return m_capacity;
	}

	//通过下标方式访问数组元素
	T& operator[](int index)
	{
		return paddress[index];
	}


private:
	T* paddress;
	int m_capacity;
	int m_size;
};