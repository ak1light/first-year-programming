МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ Федеральное государственное автономное образовательное учреждение высшего образования "КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО" ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ Кафедра компьютерной инженерии и моделирования



### Отчёт по лабораторной работе № 4 по дисциплине "Программирование"



студента 1 курса группы ПИ-б-о-192(1)
Кононова Алексея Геннадьевича
направления подготовки 09.03.04 "Программная инженерия"

<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>Чабанов В.В.</td>
<td>(оценка)</td>
</table>

<br/><br/>

------

## Цель:

1. Закрепить навыки работы с перечислениями;
2. Закрепить навыки работы с структурами;
3. Освоить методы составления многофайловых программ.


Код:
<u>**Lab4.cpp**</u>

```C++
#include <iostream>
#include <ctime>
#include <windows.h>
#include "game.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char ch;
	char userChar;
	do
	{
		cout << "Выберите ваш символ" << endl;
		cout << "1. Х" << endl;
		cout << "2. О" << endl;
		cin >> ch;
		if (ch != '1' && ch != '2')
		{
			cout << "Параметр выбран неверно" << endl;
		}
		else if (ch == '1')
		{
			userChar = 'X';
		}
		else
		{
			userChar = 'O';
		}
	} while (ch != '1' && ch != '2');
	Game game = initGame(userChar);
	Sleep(2000);
	updateDisplay(game);
	while (game.status == 0)
	{
		Sleep(500);
		if (game.isUserTurn == 1)
		{
			userTurn(&game);
		}
		else
		{
			botTurn(&game);
		}
		updateDisplay(game);
		updateGame(&game);
	}
	if (game.status == 1)
	{
		cout << "ВЫ ПОБЕДИЛИ!!!!" << endl;
	}
	else if (game.status == 2)
	{
		cout << "ВЫ ПРОИГРАЛИ" << endl;
	}
	else if (game.status == 3)
	{
		cout << "НИЧЬЯ" << endl;
	}
	system("pause");
}
```
<u>**game.cpp**</u>

```c++
#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include "game.h"

using namespace std;

Game initGame(char userChar)
{
	char ch = '8';
	Game game;
	game.status = Status::PLAY;
	srand(time(0));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			game.bord[i][j] = ' ';
		}
	}

	cout << "Вы выбрали символ: " << userChar << endl;
	game.userChar = userChar;
	if (userChar == 'X')
	{
		game.botChar = 'O';
		cout << "Символ бота: " << 'O' << endl;
	}
	else
	{
		game.botChar = 'X';
		cout << "Символ бота: " << 'X' << endl;
	}
	Sleep(2000);

	game.isUserTurn = rand() % 2;
	if (game.isUserTurn == 1)
	{
		cout << "Вы ходите первый" << endl;
	}
	else
	{
		cout << "Вы ходите второй" << endl;
	}

	return game;
}

void updateDisplay(const Game game)
{
	system("cls");
	cout << "   a   b   c" << endl;
	cout << "  ___________" << endl << "1  ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << game.bord[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << i + 2 << "  ";
		}
	}

}

void botTurn(Game* game)
{
	int space_count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == ' ')
			{
				space_count++;
			}
		}
	}

	if (space_count == 9)
	{
		game->bord[1][1] = game->botChar;
	}
	else
	{
		if (game->bord[0][0] == game->bord[0][1] && game->bord[0][0] != ' ' && game->bord[0][2] == ' ')
			game->bord[0][2] = game->botChar;
		else if (game->bord[0][0] == game->bord[0][2] && game->bord[0][0] != ' ' && game->bord[0][1] == ' ')
			game->bord[0][1] = game->botChar;
		else if (game->bord[0][1] == game->bord[0][2] && game->bord[0][1] != ' ' && game->bord[0][0] == ' ')
			game->bord[0][0] = game->botChar;

		else if (game->bord[1][0] == game->bord[1][1] && game->bord[1][0] != ' ' && game->bord[1][2] == ' ')
			game->bord[1][2] = game->botChar;
		else if (game->bord[1][0] == game->bord[1][2] && game->bord[1][0] != ' ' && game->bord[1][1] == ' ')
			game->bord[1][1] = game->botChar;
		else if (game->bord[1][1] == game->bord[1][2] && game->bord[1][1] != ' ' && game->bord[1][0] == ' ')
			game->bord[1][0] = game->botChar;

		else if (game->bord[2][0] == game->bord[2][1] && game->bord[2][0] != ' ' && game->bord[2][2] == ' ')
			game->bord[2][2] = game->botChar;
		else if (game->bord[2][0] == game->bord[2][2] && game->bord[2][0] != ' ' && game->bord[2][1] == ' ')
			game->bord[2][1] = game->botChar;
		else if (game->bord[2][1] == game->bord[2][2] && game->bord[2][1] != ' ' && game->bord[2][0] == ' ')
			game->bord[2][0] = game->botChar;

		else if (game->bord[0][0] == game->bord[1][0] && game->bord[0][0] != ' ' && game->bord[2][0] == ' ')
			game->bord[2][0] = game->botChar;
		else if (game->bord[0][0] == game->bord[2][0] && game->bord[0][0] != ' ' && game->bord[1][0] == ' ')
			game->bord[1][0] = game->botChar;
		else if (game->bord[1][0] == game->bord[2][0] && game->bord[1][0] != ' ' && game->bord[0][0] == ' ')
			game->bord[0][0] = game->botChar;

		else if (game->bord[0][1] == game->bord[1][1] && game->bord[0][1] != ' ' && game->bord[2][1] == ' ')
			game->bord[2][1] = game->botChar;
		else if (game->bord[0][1] == game->bord[2][1] && game->bord[0][1] != ' ' && game->bord[1][1] == ' ')
			game->bord[1][1] = game->botChar;
		else if (game->bord[1][1] == game->bord[2][1] && game->bord[1][1] != ' ' && game->bord[0][1] == ' ')
			game->bord[0][1] = game->botChar;

		else if (game->bord[0][2] == game->bord[1][2] && game->bord[0][2] != ' ' && game->bord[2][2] == ' ')
			game->bord[2][2] = game->botChar;
		else if (game->bord[0][2] == game->bord[2][2] && game->bord[0][2] != ' ' && game->bord[1][2] == ' ')
			game->bord[1][2] = game->botChar;
		else if (game->bord[1][2] == game->bord[2][2] && game->bord[1][2] != ' ' && game->bord[0][2] == ' ')
			game->bord[0][2] = game->botChar;

		else if (game->bord[0][0] == game->bord[1][1] && game->bord[0][0] != ' ' && game->bord[2][2] == ' ')
			game->bord[2][2] = game->botChar;
		else if (game->bord[0][0] == game->bord[2][2] && game->bord[0][0] != ' ' && game->bord[1][1] == ' ')
			game->bord[1][1] = game->botChar;
		else if (game->bord[1][1] == game->bord[2][2] && game->bord[1][1] != ' ' && game->bord[0][0] == ' ')
			game->bord[0][0] = game->botChar;

		else if (game->bord[2][0] == game->bord[1][1] && game->bord[2][0] != ' ' && game->bord[0][2] == ' ')
			game->bord[0][2] = game->botChar;
		else if (game->bord[0][2] == game->bord[1][1] && game->bord[0][2] != ' ' && game->bord[2][0] == ' ')
			game->bord[2][0] = game->botChar;
		else if (game->bord[0][2] == game->bord[2][0] && game->bord[0][2] != ' ' && game->bord[1][1] == ' ')
			game->bord[1][1] = game->botChar;

		else
		{
			int a, b;
			a = rand() % 3;
			b = rand() % 3;

			while (game->bord[a][b] == 'X' || game->bord[a][b] == 'O')
			{
				a = rand() % 3;
				b = rand() % 3;
			}
			game->bord[a][b] = game->botChar;
		}
	}

	
}

void userTurn(Game* game)
{
	int a, b, k = 1;
	string in;
	while (k == 1)
	{
		do
		{
			cout << "Введите куда хотите поставить " << game->userChar << " [строка столбец]" << endl;
			cin >> in;
		} while (!(in[1] >= 'a' && in[1] <= 'c' && in[0] >= '1' && in[0] <= '3' && in.size() == 2));
		if (in[1] == 'a')
		{
			b = 0;
		}
		else if (in[1] == 'b')
		{
			b = 1;
		}
		else if (in[1] == 'c')
		{
			b = 2;
		}
		if (in[0] == '1')
		{
			a = 0;
		}
		else if (in[0] == '2')
		{
			a = 1;
		}
		else if (in[0] == '3')
		{
			a = 2;
		}
		if (game->bord[a][b] == 'X' || game->bord[a][b] == 'O')
		{
			cout << "Ячейка занята, введите другую" << endl;
		}
		else
		{
			k = 0;
		}

	}
	game->bord[a][b] = game->userChar;
}

void updateGame(Game* game)
{
	int a = 0;
	bool k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == 'X' || game->bord[i][j] == 'O')
			{
				a++;
			}
		}
	}
	if (game->bord[0][0] == 'X' && game->bord[1][1] == 'X' && game->bord[2][2] == 'X'
		|| game->bord[2][0] == 'X' && game->bord[1][1] == 'X' && game->bord[0][2] == 'X'
		|| game->bord[0][0] == 'X' && game->bord[0][1] == 'X' && game->bord[0][2] == 'X'
		|| game->bord[1][0] == 'X' && game->bord[1][1] == 'X' && game->bord[1][2] == 'X'
		|| game->bord[2][0] == 'X' && game->bord[2][1] == 'X' && game->bord[2][2] == 'X'
		|| game->bord[0][0] == 'X' && game->bord[1][0] == 'X' && game->bord[2][0] == 'X'
		|| game->bord[0][1] == 'X' && game->bord[1][1] == 'X' && game->bord[2][1] == 'X'
		|| game->bord[0][2] == 'X' && game->bord[1][2] == 'X' && game->bord[2][2] == 'X'
		|| game->bord[0][0] == 'O' && game->bord[1][1] == 'O' && game->bord[2][2] == 'O'
		|| game->bord[2][0] == 'O' && game->bord[1][1] == 'O' && game->bord[0][2] == 'O'
		|| game->bord[0][0] == 'O' && game->bord[0][1] == 'O' && game->bord[0][2] == 'O'
		|| game->bord[1][0] == 'O' && game->bord[1][1] == 'O' && game->bord[1][2] == 'O'
		|| game->bord[2][0] == 'O' && game->bord[2][1] == 'O' && game->bord[2][2] == 'O'
		|| game->bord[0][0] == 'O' && game->bord[1][0] == 'O' && game->bord[2][0] == 'O'
		|| game->bord[0][1] == 'O' && game->bord[1][1] == 'O' && game->bord[2][1] == 'O'
		|| game->bord[0][2] == 'O' && game->bord[1][2] == 'O' && game->bord[2][2] == 'O')
	{
		k = 1;
	}
	if (a == 9 && k != 1)
	{
		game->status = NOT_WIN;
	}
	else if (k == 1)
	{
		if (game->isUserTurn == 1)
		{
			game->status = USER_WIN;
		}
		else
		{
			game->status = BOT_WIN;
		}
	}
	else
	{
		game->status = PLAY;
	}
	game->isUserTurn = !game->isUserTurn;
}

```
**<u>game.h</u>**

```c++
#pragma once


enum Status
{
	PLAY,
	USER_WIN,
	BOT_WIN,
	NOT_WIN
};

struct Game
{
	char bord[3][3];
	bool isUserTurn;
	char userChar;
	char botChar;
	Status status;
};

Game initGame(char userChar);
void updateDisplay(const Game game);
void botTurn(Game* game);
void userTurn(Game* game);
void updateGame(Game* game);
```

Выбор символа показан на рисунке 1.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/4lab/images/1.jpg)	 
Рис. 1 - Выбор символа 

Процесс игры с ботом показан на рисунке 2.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/4lab/images/2.jpg)
Рис. 2 - Процесс игры с ботом

Результат игры показан на рисунке 3.
![](https://raw.githubusercontent.com/ak1light/first-year-programming/master/reworked_labs/4lab/images/3.jpg)
Рис. 3. - Результат игры

------

## Вывод

Закрепил навыки работы с перечислениями, закрепил навыки работы с структурами, освоил методы составления многофайловых программ.

