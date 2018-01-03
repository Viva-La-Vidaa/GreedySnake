#include "Scene.h"
Snake snake;
void Snake::Init()
{
	m_x[0] = 7; m_y[0] = 7;
	m_x[1] = 8; m_y[1] = 7;
	m_length = 2;
	map.Set_Map(m_x[0], m_y[0], '@');
	map.Set_Map(m_x[1], m_y[1], '*');
}

void Snake::move(char direction)
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

bool Snake::is_Direction(char dir)
{
	if (dir != 's'&&dir != 'w'&&dir != 'a'&&dir != 'd')
		return 0;
	else
		return 1;
}

void Snake::Show()
{
	map.Set_Map(m_x[0], m_y[0], '@');
	int i;
	for (i = 1; i < m_length; i++)
			map.Set_Map(m_x[i], m_y[i], '*');
	return;
}
