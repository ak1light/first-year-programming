#include <iostream>
#include <ctime>

using namespace std;
enum ItemName {
	SWORD,
	BOW,
	SPELL
};
enum Element {
	Fire,
	Eatrh,
	Water,
	Air
};
struct Sword {
	int damage;
};
struct Bow {
	int  damage;
	int charge_time;
	double distance;
};
struct Spell {
	int damage;
	Element element;
	double distance;
};
struct  Item {
	ItemName item_name;
	union {
		Sword sword;
		Spell spell;
		Bow bow;
	};
};

Item getRandomItem();
void printItem(Item loot);

int main() {
	srand(time(0));
	struct Item mas[5];
	for (int i = 0; i < 5; ++i) mas[i] = getRandomItem();
	for (int i = 0; i < 5; ++i) {
		printItem(mas[i]);
		cout << "\n";
	}
	return 0;
}

Item getRandomItem() {
	Item res;

	res.item_name = (ItemName) (rand() % 3);

	switch (res.item_name) {
	case SWORD:
		res.sword.damage = rand() % 100;
		break;

	case BOW:
		res.bow.damage = rand() % 100;
		res.bow.charge_time = rand() % 100;
		res.bow.distance = rand() % 100;
		break;

	case SPELL:
		res.spell.damage = rand() % 100;
		res.spell.element = (Element) (rand() % 4);
		res.spell.distance = rand() % 100;
		break;
	}
	return res;
}

void printItem(Item loot) {
	switch (loot.item_name) {
	case SWORD:
		cout << "---SWORD---" << endl;
		cout << "DAMAGE: " << loot.sword.damage << endl;
		break;
	case BOW:
		cout << "---BOW---" << endl;
		cout << "DAMAGE: " << loot.bow.damage << endl;
		cout << "CHARGE TIME: " << loot.bow.charge_time << endl;
		cout << "DISTANCE: " << loot.bow.distance << endl;
		break;
	case SPELL:
		cout << "---SPELL---" << endl;
		cout << "DAMAGE: " << loot.spell.damage << endl;
		cout << "DISTANCE: " << loot.spell.distance << endl;
		cout << "ELEMENT: ";
		switch (loot.spell.element) {
		case Air:
			cout << "AIR";
			break;
		case Eatrh:
			cout << "EATRH";
			break;
		case Water:
			cout << "WATER";
			break;
		case Fire:
			cout << "FIRE";
			break;
		}
		cout << endl;
		break;
	}
}