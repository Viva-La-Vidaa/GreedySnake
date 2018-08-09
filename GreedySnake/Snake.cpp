#include <conio.h>
#include "Scene.h"
Map map;//全局变量定义
Food food;
Snake snake;
void Snake::Init()
{
	direction = 'w';//默认方向
	m_x[0] = 7; m_y[0] = 7;
	m_x[1] = 8; m_y[1] = 7;
	m_length = 2;
	map.Set_Map(m_x[0], m_y[0], '@');
	map.Set_Map(m_x[1], m_y[1], '*');
}

void Snake::move()
{
	int temp_x, temp_y;
	temp_x = m_x[m_length - 1];
	temp_y = m_y[m_length - 1];

	int i;
	for (i = m_length - 1; i > 0; i--)   //对蛇身进行移动
	{
		m_x[i] = m_x[i - 1];
		m_y[i] = m_y[i - 1];
	}

	switch (direction)  //对蛇头进行移动
	{
	case 'w':
		m_x[0]--;
		break;
	case 's':
		m_x[0]++;
		break;
	case 'a':
		m_y[0]--;
		break;
	case 'd':
		m_y[0]++;
		break;
	}
	if (is_EatFood())
	{
		m_x[m_length] = temp_x;
		m_y[m_length] = temp_y;
		m_length++;
	}
	else
	{
		// 前移之后，尾部清空
		map.Set_Map(temp_x, temp_y, ' ');
	}

	//移动之后,对蛇进行重绘
	map.Set_Map(m_x[0], m_y[0], '@');
	int j;
	for (j= 1; j < m_length; j++)
		map.Set_Map(m_x[j], m_y[j], '*');
	return;
}

bool Snake::is_EatFood()
{
	if (m_x[0] == food.m_x&&m_y[0] == food.m_y)
		return 1;
	else
		return 0;
}

bool Snake::is_EatSelf()
{

	if (m_length < 3)
		return 0;
	int i;
	for (i = 3; i <=m_length; i++)
	{
		if (m_x[0] == m_x[i] && m_y[0] == m_y[i])
			return 1;
	}
	return 0;
}

bool Snake::is_HitGround()
{
	if (m_x[0] ==0|| m_x[0] == N-1|| m_y[0] == 0 || m_y[0] ==M-1)
		return 1;
	else
		return 0;
}

void Snake::ChangeDirection()
{
	char ch;
	ch = _getch();
	switch (ch)
	{
	case 'w':
		if (direction != 's')   //如果方向与当前运动方向相反，则无效
			direction='w';
		break;
	case 's':
		if (direction != 'w')
			direction = 's';
		break;
	case 'a':
		if (direction != 'd')
			direction = 'a';
		break;
	case 'd':
		if (direction != 'a')
			direction = 'd';
		break;
	default:
		break;
	}
}


