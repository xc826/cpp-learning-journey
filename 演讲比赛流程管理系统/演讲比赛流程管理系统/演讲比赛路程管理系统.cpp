#include"speechmanager.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	speechmanager sm;

	int choice = 0;

	while (true)
	{

		//����
		//for (map<int, speaker>::iterator it = sm.m.begin(); it != sm.m.end(); it++)
		//{
		//	cout << "���: " << it->first << "name: " << it->second.m_name << "score: " << it->second.score[0] << endl;
		//}

		sm.show_menu();
		cout << "����������ѡ�� " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			sm.start_game();//��ʼ�ݽ�����
			break;
		case 2:
			sm.show_record();//�鿴�����¼
			break;
		case 3:
			sm.clear_record();//��ձ�����¼
			break;
		case 0:
			sm.exit_system();//�˳���������
			break;
		default:
			system("cls");
			break;
		}
		
	}
	//��ʾ�˵�
	sm.show_menu();



	system("pause");
	return 0;
}