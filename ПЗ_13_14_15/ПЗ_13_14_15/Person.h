#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person // абстрактный класс
{
private:
	string name;
	int age;
public:
	// Конструктор
	Person(string n, int a);
	// Деструктор
	virtual ~Person();
	// Виртуальные методы
	virtual void work() = 0;
	virtual void search_task() = 0;
	// Метод для вывода информации об объекте
	virtual void displayInfo();
	// Свойства для изменения и отображения полей
	void setName();
	void setAge();
	string getName();
	int getAge();
};
