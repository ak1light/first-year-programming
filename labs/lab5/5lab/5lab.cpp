#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct entry {
	string data[12];
	//0 - id; 1 - survived, 2 - Pclass, 3 - name, 4 - sex, 5 - age, 6 - sibsp, 7 - parch, 8 - ticket, 9 - fare, 10 - cabin, 11 - embarke
};

vector<entry> entries;

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream fin("train.csv");

	if (!fin.is_open()) {
		cout << "Ошибка при открытии файла!" << endl;
		fin.close();
	}
	else {
		while (fin.good()) {
			string line;
			int start = 0;
			entry e;
			getline(fin, line, '\r');
			bool inQuotes = false;
			int col = 0;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '"') inQuotes = !inQuotes;
				if (!inQuotes) {
					if (line[i] == ',') {
						e.data[col] = line.substr(start, i - start);
						col++;
						start = i + 1;
					}
					else if (i == line.length() - 1) {
						e.data[11] = line.substr(start, 1);
					}
				}
			}
			entries.push_back(e);

		}
		fin.close();

		int survivors = 0;
		int firstClassSurvivors = 0;
		int secondClassSurvivors = 0;
		int thirdClassSurvivors = 0;
		int femaleSurvivors = 0;
		int maleSurvivors = 0;

		double avgAge = 0;
		int avgDivider = 1;
		double avgFemaleAge = 0;
		int avgFemaleDivider = 1;
		double avgMaleAge = 0;
		int avgMaleDivider = 1;

		int C = 0;
		int Q = 0;
		int S = 0;
		char maxEmbarke = ' ';

		string underAge = "";

		for (int i = 1; i < entries.size(); i++) {
			if (entries[i].data[1] == "1") survivors++;
			if (entries[i].data[1] == "1" && entries[i].data[2] == "1") firstClassSurvivors++;
			if (entries[i].data[1] == "1" && entries[i].data[2] == "2") secondClassSurvivors++;
			if (entries[i].data[1] == "1" && entries[i].data[2] == "3") thirdClassSurvivors++;
			if (entries[i].data[1] == "1" && entries[i].data[4] == "female") femaleSurvivors++;
			if (entries[i].data[1] == "1" && entries[i].data[4] == "male") maleSurvivors++;
			if (!entries[i].data[5].empty()) {
				avgAge += stod(entries[i].data[5]);
				avgDivider++;
			}
			if (entries[i].data[4] == "female" && !entries[i].data[5].empty()) {
				avgFemaleAge += stod(entries[i].data[5]);
				avgFemaleDivider++;
			}
			if (entries[i].data[4] == "male" && !entries[i].data[5].empty()) {
				avgMaleAge += stod(entries[i].data[5]);
				avgMaleDivider++;
			}
			if (entries[i].data[11] == "C") C++;
			if (entries[i].data[11] == "Q") Q++;
			if (entries[i].data[11] == "S") S++;

			if (!entries[i].data[5].empty()) {
				if (stod(entries[i].data[5]) < 18) underAge += (to_string(i) + ", ");
			}
		}
		avgAge /= avgDivider;
		avgFemaleAge /= avgFemaleDivider;
		avgMaleAge /= avgMaleDivider;
		if (C > Q && C > S) maxEmbarke = 'C';
		if (Q > C && Q > S) maxEmbarke = 'Q';
		if (S > C && S > Q) maxEmbarke = 'S';

		underAge = underAge.substr(0, underAge.length() - 2);

		ofstream fout;
		fout.open("output.txt");
		if (fout.is_open()) {
			fout << "Общее число выживших: " << survivors << endl;
			fout << "Число выживших из 1 класса: " << firstClassSurvivors << endl;
			fout << "Число выживших из 2 класса: " << secondClassSurvivors << endl;
			fout << "Число выживших из 3 класса: " << thirdClassSurvivors << endl;
			fout << "Число выживших женщин: " << femaleSurvivors << endl;
			fout << "Число выживших мужчин: " << maleSurvivors << endl;
			fout << "Средний возраст пассажиров: " << avgAge << endl;
			fout << "Средний возраст пассажиров женского пола: " << avgFemaleAge << endl;
			fout << "Средний возраст пассажиров мужского пола: " << avgMaleAge << endl;
			fout << "Штат, в котором село больше всего пассажиров: " << maxEmbarke << endl;
			fout << "Список несовершеннолетних: " << underAge << endl;
		}
		fout.close();

	}
	return 0;
}