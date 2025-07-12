#include"speechmanager.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	speechmanager sm;

	int choice = 0;

	while (true)
	{

		//测试
		//for (map<int, speaker>::iterator it = sm.m.begin(); it != sm.m.end(); it++)
		//{
		//	cout << "编号: " << it->first << "name: " << it->second.m_name << "score: " << it->second.score[0] << endl;
		//}

		sm.show_menu();
		cout << "请输入您的选择： " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.start_game();//开始演讲比赛
			break;
		case 2:
			sm.show_record();//查看往届记录
			break;
		case 3:
			sm.clear_record();//清空比赛记录
			break;
		case 0:
			sm.exit_system();//退出比赛程序
			break;
		default:
			system("cls");
			break;
		}
		
	}
	//显示菜单
	sm.show_menu();



	system("pause");
	return 0;
}