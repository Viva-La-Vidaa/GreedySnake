#include<iostream>
#include <stdlib.h>
#include <ctime>
#include "Scene.h"
Map map;
Food food;
void Map::Init_Map()
{
	int i, j;
	for (i = 0; i < 20; i++)
	for (j = 0; j < 30; j++)
	{
		if (i == 0 || i == 19)
			game[i][j] = '-';
		else if (j == 0 || j == 29)
			game[i][j] = '|';
		else
			game[i][j] = ' ';
	}
}

void Map::Show_Map()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
			std::cout << game[i][j];
		std::cout << std::endl;
	}
}

void Map::Set_Map(int x, int y, char s)
{
	game[x][y] = s;
}

void Map::ShowScore(int score)
{
	std::cout << "\n\n\n\n\n\n\t\t\t\t得分：" << score << "分";
}

void Food::Set_Food()
{
	srand((unsigned)time(NULL));/*随机数播种子*/
	m_x = (rand() % 15); m_y = (rand() % 16);
	map.Set_Map(m_x, m_y, '$');
}