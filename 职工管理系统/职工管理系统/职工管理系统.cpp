#include"workermanager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	//ʵ�����������
	workermanager wm;
	int choice;

	
	while (true)
	{
		wm.showmenu();
		cout << "��ѡ����Ҫִ�еĲ�����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitsystem();//�˳�ϵͳ
			break;
		case 1:
			wm.add_worker();//����ְ��
			break;
		case 2:
			wm.showworker();//��ʾְ��
			break;
		case 3:
			wm.del_worker();//ɾ����ְְ��
			break;
		case 4:
			wm.modify_worker();//�޸�ְ��
			break;
		case 5:
			wm.find_worker();//����ְ��
			break;
		case 6:
			wm.sort_worker();//���ձ������
			break;
		case 7:
			wm.clean_file();//��������ĵ�
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}