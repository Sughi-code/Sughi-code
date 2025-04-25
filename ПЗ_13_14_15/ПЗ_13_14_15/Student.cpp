#include "Student.h"

Student::Student(string n = "", int a = 0, string mjr = "") : Person(n, a), major(mjr) {}

// Переопределение виртуальных методов
void Student::work() {
	cout << this->getName() << " выполняет домашнее задание." << endl;
}
void Student::search_task() {
	cout << this->getName() << " ищет полезную лиетратуру " << this->getMajor() << " ядра." << endl;
}
void Student::displayInfo() {
	Person::displayInfo();
	cout << "Вид ядра: " << this->major << "| ";
}
// Свойства
void Student::setMajor() {
	setlocale(LC_ALL, "Ru");
	string core;
	cout << "Введите на каком направлении состоит " << this->getName() << ": ";
	cin >> core;
	major = core;
	cin.clear(); cin.ignore(99999, '\n');
}
string Student::getMajor() {
	return major;
}
