#include<iostream>
#include <conio.h>
#include<Windows.h>
#include "Scene.h"

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
	std::cout << "\n\n\n\t\t\t 欢迎进入贪吃蛇游戏!" << std::endl;
	std::cout << "\n\n\n\t\t\t请按 W，A，S，D 来控制方向." << std::endl;
	std::cout << "\n\n\n\t\t\t 按空格键暂停游戏." << std::endl;
	std::cout << "\n\n\n\t\t\t 按任意键马上开始." << std::endl;
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
int main()
{
	Welcome();
	_getch();
	system("cls");
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
	int score=0;
	while (1)
	{
		char dir = _getch();
		if (dir == ' ')
		{
			gotoXY(26, 0);
			system("pause");
			std::cout << "按空格键继续游戏." << std::endl;
			if(dir == ' ')
			continue;
		}
		if (snake.is_Direction(dir))
		{
			system("cls");
			snake.move(dir);
			snake.Show();
			if (snake.is_EatFood())
			{
			    score++;
				food.Set_Food();
			}
			map.Show_Map();
			gotoXY(5, 63);
			std::cout << "得分:" << score << std::endl;
		}
		if (is_Dead())
			exit(0);
	}
	return 0;
}

