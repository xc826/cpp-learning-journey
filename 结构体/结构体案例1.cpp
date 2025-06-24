#include <iostream>
#include <ctime>
using namespace std;

struct student
{
    string sname;
    int score;
};

struct teacher
{
    string tname;
    student stu[5];
};


void assign(teacher tarr[], int len)
{
    string nameseed = "ABCDE";
    for (int i = 0; i < 3; i++)
    {
        tarr[i].tname = "teacher_";
        tarr[i].tname += nameseed[i];
        for (int j = 0; j < 5; j++)
        {
            tarr[i].stu[j].sname = "student_";
            tarr[i].stu[j].sname += nameseed[j];
            tarr[i].stu[j].score = rand() % 61 + 40;

        }
    }

}

void print(teacher tarr[],int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << tarr[i].tname << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名：" << tarr[i].stu[j].sname << "学生成绩：" << tarr[i].stu[j].score << endl;
        }
    }

}

int main()
{
    srand((unsigned int)time(NULL));
    teacher tarr[3];
    int len = sizeof(tarr) / sizeof(tarr[0]);
    assign(tarr,len);
    print(tarr, len);

    system("pause");
    return 0;
}