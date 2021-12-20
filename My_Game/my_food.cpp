#include "my_food.h"
#include "my_tool.h"
#include <cstdlib>
#include <time.h>
#include <iostream>


void my_food::my_rand_food()
{
	srand((int)time(NULL));
	while (1)
	{
		this->x = rand() % 27 + 2;
		this->y = rand() % 27 + 2;
		if (!(x % 2))
			break;
	}
	My_SetConsoleOutputPos(this->x, this->y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	std::cout << "бя";
}

my_food::my_food()
{
	my_rand_food();
}

int my_food::get_x()
{
	return this->x;
}

int my_food::get_y()
{
	return this->y;
}
