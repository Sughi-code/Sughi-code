#include "Village.h"
// Конструктор по умолчанию
Village::Village() 
	: country(""), name(""), year(0), vilagers(0) {}
// Конструктор с параметрами
Village::Village(string country, string name, int year, int vilagers) 
	: country(country), name(name), year(year), vilagers(vilagers) { }
// Конструктор копирования
Village::Village(const Village& other) : country(other.country), name(other.name), year(other.year), vilagers(other.vilagers) { }
// Метод для редактирования данных о деревне
void Village::edit() {
	string newCountry, newName;
	int newYear, newVilagers;
	// Проверка ввода данных для корректности
	cout << "Введите новую страну деревни: ";
	cin >> newCountry;
	setCountry(newCountry);
	cout << "Введите новое имя деревни: ";
	cin >> newName;
	setName(newName);
	cout << "Введите новый год постройки: ";
	while (!(cin >> newVilagers) || newVilagers < 0 || newVilagers > 2025) {
		cout << "Неверный год! Введите год от 0 до текущего: ";
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	setYear(newVilagers);
	cout << "Введите новое количество жителей: ";
	while (!(cin >> newVilagers) || newVilagers < 0) {
		cout << "Количество жителей должно быть реалистичным! Введите снова : ";
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	setVilagers(newVilagers);
}
// Геттеры
string Village::getCountry() { return country; }
string Village::getName() { return name; }
int Village::getYear() { return year; }
int Village::getVilagers() { return vilagers; }
// Сеттеры
void Village::setCountry(string newCountry) { country = newCountry; }
void Village::setName(string newname) { name = newname; }
void Village::setYear(int newYear) { year = newYear; }
void Village::setVilagers(int newVilagers) { vilagers =newVilagers; }
// Перегрузка оператора вывода
ostream& operator<<(ostream& os, Village Village) {
	os << "Страна: " << Village.country << ", Тип: " << Village.name << ", Год постройки: " << Village.year << ", Количество жителей: " <<	Village.vilagers;
	return os;
}
// Перегрузка оператора ввода
istream& operator>>(istream& is, Village& Village) {
	string country, name;
	int year, vilagers;
	cout << "Введите страну деревни: ";
	is >> country;
	cout << "Введите тип деревни: ";
	is >> name;
	cout << "Введите год пострйоки: ";
	while (!(is >> year) || year < 0 || year > 2025) {
		cout << "Некорректный ввод. Введите год от 0 до 2025: ";
		is.clear(); is.ignore(10000, '\n');
	}
	cout << "Введите количество жителей: ";
	while (!(is >> vilagers) || vilagers < 0) {
		cout << "Некорректный ввод. Введите реалистичное значение: ";
		is.clear();
		is.ignore(10000, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	Village.setCountry(country);
	Village.setName(name);
	Village.setYear(year);
	Village.setVilagers(vilagers);
	return is;
}
// Перегрузка оператора < для сортировки
bool Village::operator<(Village other) {
	return vilagers < other.vilagers;
}
// Перегрузка оператора > для сортировки
bool Village::operator>(Village other) {
	return vilagers > other.vilagers;
}
// Перегрузка оператора == для проверки на равенство
bool Village::operator==(Village other) {
	return country == other.country && name == other.name && year == other.year && vilagers == other.vilagers;
}