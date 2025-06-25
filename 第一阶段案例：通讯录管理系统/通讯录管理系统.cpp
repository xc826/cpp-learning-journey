#include <iostream>
using namespace std;
#define max 1000

//菜单函数
void menu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}
//联系人结构体
struct person
{
	string p_name;
	int p_gender;
	int p_age;
	string p_phone;
	string p_address;
};

//通讯录结构体
struct addressbook
{
	person parr[max];
	int p_size;

};

//添加联系人函数
void addperson(addressbook* adr)
{
	if (adr->p_size == max)
	{
		cout << "通讯录已满，不可在添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		adr->parr[adr->p_size].p_name = name;
		int gender;
		cout << "请输入性别：" << endl;
		cout << "1：男" << endl;
		cout << "2：女" << endl;
		cin >> gender;
		while (true)
		{
			if (gender == 1 || gender == 2)
			{
				adr->parr[adr->p_size].p_gender = gender;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		adr->parr[adr->p_size].p_age = age;
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		adr->parr[adr->p_size].p_phone = phone;
		string address;
		cout << "请输入家庭地址：" << endl;
		cin >> address;
		adr->parr[adr->p_size].p_address = address;

		adr->p_size++;//更新通讯录人数

		cout << "添加成功" << endl;
		system("pause");//请按任意键结束
		system("cls");//清屏

	}
}
//显示联系人
void showbook(addressbook* adr)
{
	if (adr->p_size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < adr->p_size; i++)
		{
			cout << "姓名：" << adr->parr[i].p_name << "\t";
			cout << "性别：" << (adr->parr[i].p_gender == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << adr->parr[i].p_age << "\t";
			cout << "联系电话：" << adr->parr[i].p_phone << "\t";
			cout << "姓名：" << adr->parr[i].p_address << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isexist(addressbook* adr, string name)
{
	for (int i = 0; i < adr->p_size; i++)
	{
		if (adr->parr[i].p_name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void delete_person(addressbook* adr)
{
	string name;
	cout << "请输入您要选择操作的联系人姓名：" << endl;
	cin >> name;
	//这里注意一下，在这个函数里面，传进来的adr就是指针，所以可以直接传入isexist，不需要再加取址符&了
	int re = isexist(adr, name);
	if (re != -1)
	{
		for (int i = re; i < adr->p_size; i++)
		{
			adr->parr[i] = adr->parr[i + 1];
		}
		adr->p_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "您要删除的联系人不存在" << endl;
	}
	system("pause");
	system("cls");
}
	
//查找联系人
void find_person(addressbook* adr)
{
	cout << "请输入您要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int re = isexist(adr, name);
	if (re != -1)
	{
		cout << "姓名：" << adr->parr[re].p_name << "\t";
		cout << "性别：" << (adr->parr[re].p_gender == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << adr->parr[re].p_age << "\t";
		cout << "联系电话：" << adr->parr[re].p_phone << "\t";
		cout << "姓名：" << adr->parr[re].p_address << endl;
	}
	else
	{
		cout << "您要查找的联系人不存在" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modify_person(addressbook* adr)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int re = isexist(adr, name);
	if (re != -1)
	{
		cout << "请输入你要修改的部分：" << endl;
		cout << "1、修改姓名" << endl;
		cout << "2、修改性别" << endl;
		cout << "3、修改年龄" << endl;
		cout << "4、修改联系电话" << endl;
		cout << "5、修改家庭住址" << endl;
		int part;
		cin >> part;
		switch (part)
		{
		case 1:
		{
			string m_name;
			cout << "请输入修改后的姓名：" << endl;
			cin >> m_name;
			adr->parr[re].p_name = m_name;
			break;
		}
		case 2:
		{
			int m_gender;
			cout << "请输入修改后的性别：" << endl;
			cout << "1 -- 男" << endl;
			cout << "2 -- 女" << endl;
			while (true)
			{
				cin >> m_gender;
				if (m_gender == 1 || m_gender == 2)
				{
					adr->parr[re].p_gender = m_gender;
					break;
				}
				cout << "输入有误，请重新输入";
			}
			break;
		}
		case 3:
		{
			int m_age;
			cout << "请输入修改后的年龄：" << endl;
			cin >> m_age;
			adr->parr[re].p_age = m_age;
			break;
		}
		case 4:
		{
			string m_phone;
			cout << "请输入修改后的联系方式：" << endl;
			cin >> m_phone;
			adr->parr[re].p_phone = m_phone;
			break;
		}
		case 5:
		{
			string m_address;
			cout << "请输入修改后的家庭地址：" << endl;
			cin >> m_address;
			adr->parr[re].p_address = m_address;
			break;
		}
		default:break;
		}

	}
	else
	{
		cout << "您要修改的联系人不存在" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人

void clear_person(addressbook* adr)
{
	adr->p_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


int main()
{

	addressbook adr;
	adr.p_size = 0;


	while (true)
	{
		menu();
		int select;
		cout << "请选择你要执行的功能：" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&adr);
			break;
		case 2:
			showbook(&adr);
			break;
		case 3:
			delete_person(&adr);
			break;
		case 4:
			find_person(&adr);
			break;
		case 5:
			modify_person(&adr);
			break;
		case 6:
			clear_person(&adr);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:break;
		}
	}


	system("pause");
	return 0;
}