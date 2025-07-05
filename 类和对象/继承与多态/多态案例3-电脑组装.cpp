#include<iostream>
using namespace std;
//三大组件的抽象类
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

//电脑类,提供一个工作函数,接收到具体三大组件后使其开始工作
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

//具体厂商
//Intel
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class Intelvediocard :public vediocard
{
public:
	void display()
	{
		cout << "Intel的显卡开始显示了" << endl;
	}
};

class Intelmemory :public memory
{
public:
	void storage()
	{
		cout << "Intel的内存条开始存储了" << endl;
	}
};

//Lenovo

class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo的CPU开始计算了" << endl;
	}
};

class Lenovovediocard :public vediocard
{
public:
	void display()
	{
		cout << "Lenovo的显卡开始显示了" << endl;
	}
};

class Lenovomemory :public memory
{
public:
	void storage()
	{
		cout << "Lenovo的内存条开始存储了" << endl;
	}
};

void test()
{
	cout << "第一台电脑工作" << endl;
	CPU* intelcpu = new IntelCPU;
	vediocard* intelvc = new Intelvediocard;
	memory* intelmem = new Intelmemory;


	computer* pc1 = new computer(intelcpu, intelvc, intelmem);
	pc1->work();
	delete pc1;

	cout << "第二台电脑工作" << endl;
	CPU* lenovocpu = new LenovoCPU;
	vediocard* lenovovc = new Lenovovediocard;
	memory* lenovomem = new Lenovomemory;


	computer* pc2 = new computer(lenovocpu, lenovovc, lenovomem);
	pc2->work();
	delete pc2;

	cout << "第三台电脑工作" << endl;
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