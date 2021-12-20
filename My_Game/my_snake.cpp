#include "my_snake.h"
#include "my_tool.h"
#include <iostream>
#include <conio.h>

my_cell::my_cell()
{
	this->x = 0;
	this->y = 0;
}
my_cell::my_cell(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}


my_snake::my_snake()
{
	this->key = 'd';
	for (size_t i = 5; i > 0; i--)
	{
		my_cell cell(16 + (i << 1), 8);
		data.push_back(cell);
	}
	my_draw();
	
}

my_snake::~my_snake()
{
	My_SetConsoleOutputPos(0, 35);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

bool my_snake::my_move(my_food& food)
{
	
	auto flags = my_dir();
	if (flags)
	{	
		auto checks = my_check();
		if (!checks)
		{
			my_clear();
			return false;
		}
		my_eat(food);
		My_SetConsoleOutputPos(this->data.back().x, this->data.back().y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
		std::cout << " ";
		this->data.pop_back();
		my_draw();
	}

	return true;
}

void my_snake::my_draw()
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		if (i == 0)
		{
			My_SetConsoleOutputPos(this->data.at(i).x, this->data.at(i).y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
			std::cout << "¡ñ";
		}
		else
		{
			My_SetConsoleOutputPos(this->data.at(i).x, this->data.at(i).y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
			std::cout << "¡ö";
		}
	}
}

bool my_snake::my_dir()
{
	if (_kbhit())
	{
		char temp = _getch();
		switch (temp)
		{
		case 'a':
		case 's':
		case 'd':
		case 'w':
			if ((this->key == 'w' && temp != 's') || (this->key == 's' && temp != 'w') || \
				(this->key == 'a' && temp != 'd') || (this->key == 'd' && temp != 'a'))
				this->key = temp;
		}
		switch (this->key)
		{
		case 'D':
		case 'd':
			this->data.push_front(my_cell(data.front().x + 2, data.front().y));
			break;
		case 'A':
		case 'a':
			this->data.push_front(my_cell(data.front().x - 2, data.front().y));
			break;
		case 'W':
		case 'w':
			this->data.push_front(my_cell(data.front().x, data.front().y - 1));
			break;
		case 'S':
		case 's':
			this->data.push_front(my_cell(data.front().x, data.front().y + 1));
			break;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool my_snake::my_check()
{
	for (size_t i = 1; i < this->data.size(); i++)
	{
		if (this->data.front().x == this->data.at(i).x && this->data.front().y == this->data.at(i).y)
			return false;
	}
	if (this->data.front().x < 68 && this->data.front().x > 0 && this->data.front().y > 0 && this->data.front().y < 34)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void my_snake::my_clear()
{
	system("cls");
}

void my_snake::my_eat(my_food& food)
{
	if (this->data.front().x == food.get_x() && this->data.front().y == food.get_y())
	{
		switch (this->key)
		{
		case 'd':
		case 'D':
			data.push_back(my_cell(data.back().x - 2, data.back().y));
			break;
		case 'a':
		case 'A':
			data.push_back(my_cell(data.back().x + 2, data.back().y));
			break;
		case 'w':
		case 'W':
			data.push_back(my_cell(data.back().x, data.back().y + 1));
			break;
		case 's':
		case 'S':
			data.push_back(my_cell(data.back().x, data.back().y - 1));
			break;
		}
		this->score++;
		while (1)
		{
			food.my_rand_food();
			bool flag = true;
			for (auto i : this->data)
			{
				if (i.x == food.get_x() && i.y == food.get_y())
					flag = false;
			}
			if (flag)
				break;
		}
	}
}
