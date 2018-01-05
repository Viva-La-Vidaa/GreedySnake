#include<iostream>
#include <conio.h>
#include<Windows.h>
#include<time.h>
#include "Scene.h"
char dir = 'w';//默认方向,未输入时
int score = 0;
double speed;
void gotoXY(int x, int y)
{
	HANDLE hout;
	COORD coord;
	coord.X = y;             //x与y是颠倒的.网上查不到,这儿没想通....
	coord.Y = x;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	return;
}

void Welcome()
{
	gotoXY(5, 30);
	std::cout << "欢迎进入贪吃蛇游戏!" << std::endl;
	gotoXY(8, 28);
	std::cout << "请按 W，A，S，D 来控制方向." << std::endl;
	gotoXY(11, 30);
	std::cout << " 按空格键暂停游戏." << std::endl;
	gotoXY(14, 29);
	std::cout << " 按任意键开始选择难度." << std::endl;
	_getch();
	system("cls");
} 

bool is_Dead()
{
	if (snake.is_EatSelf())
	{
		gotoXY(27, 0);
		std::cout << "\n\n\n\t\t\t 你吃掉了自己,游戏结束!" << std::endl;
		return 1;
	}
	else  if (snake.is_HitGround())
	{
		gotoXY(27, 0);
		std::cout << "\n\n\n\t\t\t 撞墙了,游戏结束!" << std::endl;
		return 1;
	}
	else
		return 0;

}

void Go()
{
	system("cls");
	snake.move();
	if (snake.is_EatFood())
	{
		score++;
		food.Set_Food();
	}
	map.Show_Map();
	gotoXY(5, 63);
	std::cout << "得分:" << score << std::endl;
}

void Init()//初始化函数
{
	_getch();
	system("cls");
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
}

void Select()
{
	std::cout << "\n\n\n\t\t\t请输入序号开始游戏:" << std::endl;
	std::cout << "\n\n\n\t\t\t1.简单模式" << std::endl;
	std::cout << "\n\n\n\t\t\t2.正常模式" << std::endl;
	std::cout << "\n\n\n\t\t\t3.困难模式" << std::endl;
	std::cout << "\n\n\n\t\t\t4.作死模式" << std::endl;
	int hard;
	int flag = 1;
	while (flag)
	{
		std::cin >> hard; //输入序号回车后,不知道为啥还得输入任意键才能进入游戏(BUG1处)
		switch (hard)
		{
		case 1:
			speed = 0.25;
			flag = 0;
			break;
		case 2:
			speed = 0.15;
			flag = 0;
			break;
		case 3:
			speed = 0.02;
			flag = 0;
			break;
		case 4:
			speed = 0.0001;
			flag = 0;
			break;
		default:
			std::cout << "序号输入错误,请重新输入." << std::endl;
				flag = 1;
				break;
		}
	}
}

int main()
{
	Welcome();
	Select();
	Init();
	while (1)
	{
		double start = (double)clock() / CLOCKS_PER_SEC;
		while (1)                                                                                        //用来控制难度
		{
		    double end = (double)clock() / CLOCKS_PER_SEC;
		    if (end - start >=speed) break;                                  
		}
		if (!_kbhit())
			Go();
		else
		{
		   snake.ChangeDirection();
		  Go();
		}
		if (is_Dead())
			exit(0);
	}
	return 0;
}

