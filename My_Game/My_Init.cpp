#include "My_Init.h"
#include "my_snake.h"
#include "my_food.h"
#include <iostream>
void my_init()
{
	My_SetWindowSize("Ã∞≥‘…ﬂ", 100, 34);
	My_HideCursor();
	for (size_t i = 0; i < 35; i++)
	{
		for (size_t j = 0; j < 35; j++)
		{
			if (i == 0 || i == 34 || j == 0 || j == 34)
				My_WriteChar("°ˆ", i, j, 0x7F);
		}
	}
	my_snake snake;
	my_food food;
	My_SetConsoleOutputPos(80, 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	std::cout << "score:" << snake.score;
	My_HideCursor();
	while(1)
	{
		auto eflag = snake.my_move(food);
		if (!eflag)
			break;
		My_SetConsoleOutputPos(80, 15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
		std::cout << "score:" << snake.score;
	}
	My_SetConsoleOutputPos(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	std::cout << "Game Over!\n";
	
}