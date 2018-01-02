#ifndef _Snake_H_
#define _Snake_H_
#include "Scene.h"
#define N 100
class Snake
{
public:
	Snake();
	void Init();
	bool is_EatSelf();//是否吃掉自己
	bool is_HitGround();//是否撞墙
	bool is_EatFood();//是否吃掉食物
	bool is_Direction(char dir);
	void move(char direction);
	void Show();
private:
	int m_x[N];
	int m_y[N];
	int m_length;
};

#endif