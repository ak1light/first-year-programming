#include <iostream>
#include <cstring>
#include <cmath>
bool checkpal(char string[]);

int main() {
	char string1[21];
		std::cout << "Vvedite slovo: ";
		std::cin.getline(string1, 21); // getline для пробелов
			if (checkpal(string1)) {
				std::cout << "Palindrom";
			}
			else std::cout << "ne palindrom";
		
	return(0);
}

bool checkpal(char string1[]) {
	int symbsortstring = 0;
	int ascii = 0;
	int len = strlen(string1);

	char *sortstring = new char[len + 1];
		for (int i = 0; i < len; ++i) {
			ascii = (int)string1[i];
			if ((ascii >= '0' && ascii <= '9') || (ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
				sortstring[symbsortstring] = string1[i];
				++symbsortstring;

			}
		}


		for (int i = 0; i < symbsortstring/2; i++) {
			if ((sortstring[i] != sortstring[symbsortstring -1-i]) && ((abs((int)sortstring[i] - 65) != abs( (int)sortstring[symbsortstring - 1 -i] - 97)) && (abs((int)sortstring[symbsortstring - 1 - i] - 65) != abs((int)sortstring[i] - 97)))) { // 65 и 97 для равенства регистров ASCII
				delete[] sortstring;
				return false;
			}

		}
		delete[] sortstring;
		return true;		
}