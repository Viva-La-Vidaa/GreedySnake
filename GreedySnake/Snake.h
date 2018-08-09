#ifndef _Snake_H_
#define _Snake_H_

const int N = 25,M =50;
const int length =300;
class Snake
{
public:
	int m_x[length];
	int m_y[length];
	int m_length;
	void Init();
	bool is_EatSelf();//是否吃掉自己
	bool is_HitGround();//是否撞墙
	bool is_EatFood();//是否吃掉食物
	void ChangeDirection();
	void move();
   private:
	   char direction;//默认方向
};
extern Snake snake;//全局变量声明
#endif