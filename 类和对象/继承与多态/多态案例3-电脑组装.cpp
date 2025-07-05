#include<iostream>
using namespace std;
//��������ĳ�����
class CPU
{
public:
	virtual void calculate() = 0;
};

class vediocard
{
public:
	virtual void display() = 0;
};

class memory
{
public:
	virtual void storage() = 0;
};

//������,�ṩһ����������,���յ��������������ʹ�俪ʼ����
class computer
{
public:
	computer(CPU* cpu, vediocard* vc, memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->calculate();

		m_vc->display();

		m_mem->storage();
	}
	~computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}

		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	vediocard* m_vc;
	memory* m_mem;

};

//���峧��
//Intel
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};

class Intelvediocard :public vediocard
{
public:
	void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};

class Intelmemory :public memory
{
public:
	void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl;
	}
};

//Lenovo

class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};

class Lenovovediocard :public vediocard
{
public:
	void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
	}
};

class Lenovomemory :public memory
{
public:
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢��" << endl;
	}
};

void test()
{
	cout << "��һ̨���Թ���" << endl;
	CPU* intelcpu = new IntelCPU;
	vediocard* intelvc = new Intelvediocard;
	memory* intelmem = new Intelmemory;


	computer* pc1 = new computer(intelcpu, intelvc, intelmem);
	pc1->work();
	delete pc1;

	cout << "�ڶ�̨���Թ���" << endl;
	CPU* lenovocpu = new LenovoCPU;
	vediocard* lenovovc = new Lenovovediocard;
	memory* lenovomem = new Lenovomemory;


	computer* pc2 = new computer(lenovocpu, lenovovc, lenovomem);
	pc2->work();
	delete pc2;

	cout << "����̨���Թ���" << endl;
	CPU* intelcpu1 = new IntelCPU;
	vediocard* lenovovc1 = new Lenovovediocard;
	memory* intelmem1 = new Intelmemory;
	computer* pc3 = new computer(intelcpu1, lenovovc1, intelmem1);
	pc3->work();
	delete pc3;
}

int main()
{
	test();



	system("pause");
	return 0;
}