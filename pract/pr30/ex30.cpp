#include <iostream>
#include <cstring>

using namespace std;
bool lexema(char ch, const char* arr, int len);
char* strtok1(char* string, const char* delim);
int main() {
	char* str_temp = new char[100];
	char* delim_temp = new char[100];
	cin.getline(str_temp, 100);
	cin.getline(delim_temp, 100);

	char* temp = strtok1(str_temp, delim_temp);
	int words = 0;
	while (temp != nullptr) {
		cout << temp << endl;
		temp = strtok1(nullptr, delim_temp);
		words++;
	}
	cout << "words: " << words << endl;
	delete[] str_temp;
	delete[] delim_temp;
	return 0;
}
bool lexema(char ch, const char* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (ch == arr[i]) return true;
	}
	return(false);
}

char* strtok1(char* string, const char* delim) {
	static int begin = 0;
	static int end = 0;
	static char* str = string;
	static int leng = 0;

	if (string != nullptr) {
		begin = 0;
		end = 0;
		str = string;
		int i = 0;
		while (string[i] != '\0') {
			i++;
			leng++;
		}
	}
	while (lexema(str[begin], delim, strlen(delim)) && begin < leng) {
		begin++;
		end++;
	}
	if (begin >= leng) {
		return(nullptr);
	}
	else {
		while (!lexema(str[end], delim, strlen(delim)) && end < leng) {
			end++;
		}
		int len = end - begin;
		char* res = new char[len + 1];
		for (int i = 0; i < len; i++) {
			res[i] = str[i + begin];
		}
		res[len] = '\0';
		end++;
		begin = end;
		return(res);
	}
}