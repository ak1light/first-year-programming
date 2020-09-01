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
