#ifndef _Scene_H_
#define _Scene_H_
#include "Snake.h"
class  Map
{
public:
	void Show_Map();
	void Init_Map();
	void Set_Map(int x, int y, char s);
	void ShowScore(int score);
	char game[N][N];
};

class Food
{
public:
	void Set_Food();
	int m_x;
	int m_y;
};
extern Map map;
extern Food food;
#endif