
#include <iostream>
#include "game_foo.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru"); int sum = 0;
	char pChar;
	do {
		cout << "Выберите Х или 0: ";
		cin >> pChar;
	} while (pChar != 'X' && pChar != '0');
	Game mainGame = initGame(pChar);
	while (!updateGame(&mainGame))
	{
		if (mainGame.isUserTurn)userTurn(&mainGame);
		else botTurn(&mainGame);
		updateDisplay(mainGame);
	}
	if (mainGame.status == USER_WIN)std::cout << "Вы победили!";
	else if (mainGame.status == BOT_WIN)std::cout << "Вы проиграли!";
	else std::cout << "Ничья!";
}

