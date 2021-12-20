#pragma once
#include <deque>
#include "my_food.h"



class my_cell
{
public:
	my_cell();
	my_cell(const int& x, const int& y);
	int x;
	int y;
};

class my_snake
{
public:
	my_snake();
	~my_snake();
	bool my_move(my_food& food);
	int score;
private:
	std::deque<my_cell>data;
	char key;
	void my_draw();
	bool my_dir();
	bool my_check();
	void my_clear();
	void my_eat(my_food& food);
};
