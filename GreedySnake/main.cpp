#include<iostream>
#include <conio.h>
#include "Scene.h"

int main()
{
	std::cout << "\n\n\n\t\t\t 欢迎进入贪吃蛇游戏!" << std:: endl;
	std::cout << "\n\n\n\t\t\t 按任意键马上开始!" <<std:: endl;
	std::cout << "\n\n\n\t\t\t请按 w，s，a，d 来控制方向"<< std::endl;


	_getch();
	system("cls");
	Snake snake;
	map.Init_Map();
	snake.Init();
	food.Set_Food();
	map.Show_Map();
	int score=0;
	while (1)
	{
		char dir = _getch();
		if (snake.is_Direction(dir))
		{
			system("cls");
			snake.move(dir);
			snake.Show();
			if (snake.is_EatFood())
			{
				food.Set_Food();
				map.ShowScore(++score);
			}
			map.Show_Map();
		}
		if (snake.is_EatSelf())
		{
			std::cout << "\n\n\n\t\t\t 你吃掉了自己,游戏结束!" << std::endl;
			exit(0);
		}
		if (snake.is_HitGround())
		{
			std::cout << "\n\n\n\t\t\t 撞墙了,游戏结束!" << std::endl;
			exit(0);
		}
	}
	return 0;
}

