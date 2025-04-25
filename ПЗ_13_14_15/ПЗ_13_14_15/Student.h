#pragma once
#include "Person.h"

class Student : public Person {
private:
	string major;

public:
	Student(string n, int a, string major);

	// ��������������� ����������� �������
	void work() override;
	void search_task() override;
	void displayInfo() override;

	// ��������
	void setMajor();
	string getMajor();
};
