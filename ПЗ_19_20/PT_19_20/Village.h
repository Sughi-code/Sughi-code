#pragma once
#ifndef Village_H
#define Village_H
#include <iostream>
#include <string>
using namespace std;

class Village {
private:
	string country; // Страна деревни
	string name; // Название деревни
	int year; // Год постройки
	int vilagers; // Объем населения
public:
	// Конструктор по умолчанию
	Village();
	// Конструктор с параметрами
	Village(string country, string name, int year, int vilagers);
	// Конструктор копирования
	Village(const Village& other);
	// Методы для редактирования данных
	void edit();
	// Геттеры
	string getCountry();
	string getName();
	int getYear();
	int getVilagers();
	// Сеттеры
	void setCountry(string country);
	void setName(string name);
	void setYear(int year);
	void setVilagers(int vilagers);
	// Перегрузка операторов ввода/вывода
	friend ostream& operator<<(ostream& os, Village Village);
	friend istream& operator>>(istream& is, Village& Village);
	// Перегрузка оператора < и > для сравнения
	bool operator<(Village other);
	bool operator>(Village other);
	// Перегрузка оператора == для сравнения
	bool operator==(Village other);
};
#endif