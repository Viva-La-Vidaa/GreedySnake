#include "Scene.h"
#include<iostream>
#include <stdlib.h>
#include <ctime>
#include<Windows.h>


void Map::Init_Map()
{
	int i, j;
	for (i = 0; i <N; i++)
	for (j = 0; j <M; j++)
	{
		if (i == 0|| i ==N-1)
			game[i][j] = '-';
		else if (j == 0 || j == M-1)
			game[i][j] = '|';
		else
			game[i][j] = ' ';
	}
}

void Map::Show_Map()
{
	int i, j;
	for (i = 0; i <N; i++)
	{
		for (j = 0; j <M; j++)
			std::cout << game[i][j];
		std::cout << std::endl;
	}
	
}

void Map::Set_Map(int x, int y, char s)
{
	game[x][y] = s;
}

void Food::Set_Food()
{
	while (true)
	{
		srand((unsigned)time(NULL));//随机数播种子
		/*利用rand函数获得坐标，并将其范围限制在地图内，如果获得的坐标与蛇身重叠，则重新获取。*/
		m_x = rand() % (N - 2) + 1;//m_x范围为N-2到1
		m_y = rand() % (M - 2) + 1; // m_y范围为M - 2到1
		int flag = 1;
		int i;
		for (i = 0; i < snake.m_length; i++)
		{
			if (m_x == snake.m_x[i] && m_y == snake.m_y[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			map.Set_Map(m_x, m_y, '$');
			return;
		}
		else
			continue;
	}
}