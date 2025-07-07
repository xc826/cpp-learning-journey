#include"workermanager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	//实例化管理对象
	workermanager wm;
	int choice;

	
	while (true)
	{
		wm.showmenu();
		cout << "请选择您要执行的操作：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitsystem();//退出系统
			break;
		case 1:
			wm.add_worker();//增加职工
			break;
		case 2:
			wm.showworker();//显示职工
			break;
		case 3:
			wm.del_worker();//删除离职职工
			break;
		case 4:
			wm.modify_worker();//修改职工
			break;
		case 5:
			wm.find_worker();//查找职工
			break;
		case 6:
			wm.sort_worker();//按照编号排序
			break;
		case 7:
			wm.clean_file();//清空所有文档
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}