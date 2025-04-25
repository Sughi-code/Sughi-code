#pragma once
#include "Person.h"
#include "Student.h"

class Professor : public Student {
private:
	bool PHD;
public:
	Professor(string n, int a, string mjr, bool PHD);

	// Переопределение виртуальных методов
	void work() override;
	void search_task() override;
	void displayInfo() override;

	// Свойства
	void setPHD();
	bool getPHD();

};
