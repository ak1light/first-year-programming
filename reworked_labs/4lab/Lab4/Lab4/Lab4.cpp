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