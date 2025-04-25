#pragma once
#include "Person.h"

class Student : public Person {
private:
	string major;

public:
	Student(string n, int a, string major);

	// Переопределение виртуальных методов
	void work() override;
	void search_task() override;
	void displayInfo() override;

	// Свойства
	void setMajor();
	string getMajor();
};
