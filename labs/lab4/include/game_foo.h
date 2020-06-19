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
	char board[3][3];  
	bool isUserTurn; 
	char userChar;   
	char botChar;     
	Status status;
};

Game initGame(char userChar);
/**
 1. Очищает экран
 2. Отображает содержимое игрового поля.
*/
void updateDisplay(const Game game);
void botTurn(Game* game);
void userTurn(Game* game);
/**
Функция определяет как изменилось состояние игры после последнего хода.
Функция сохраняет новое состояние игры в структуре game и передаёт ход другому игроку.
Функция возвращает true, если есть победитель или ничья, иначе false.
*/
bool updateGame(Game* game);