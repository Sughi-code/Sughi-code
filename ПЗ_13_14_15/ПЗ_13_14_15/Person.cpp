#include "Person.h"


// Конструктор
Person::Person(string n, int a) : name(n), age(a) {}
// Деструктор
Person::~Person() = default;
// Свойства
void Person::setName() {
	setlocale(LC_ALL, "Ru");
	cout << "Введите имя персоны: ";
	getline(cin, this->name);
	cin.clear(); cin.ignore(99999, '\n');
}
void Person::setAge() {
	setlocale(LC_ALL, "Ru");
	cout << "Введите возраст персоны " << this->getName() << ": ";
	while (!(cin >> this->age) || this->age <= 0 || this->age > 122) {
		cout << "Неверный возраст! Попробуйте снова: ";
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
}
string Person::getName() {
	return this->name;
}
int Person::getAge() {
	return this->age;
}
// Метод для вывода информации об объекте
void Person::displayInfo() {
	cout << "Имя: " << this->getName() << "| Возраст: " << this->getAge() << "| ";
}
