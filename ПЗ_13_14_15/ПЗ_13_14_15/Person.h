#pragma once
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person // ����������� �����
{
private:
	string name;
	int age;
public:
	// �����������
	Person(string n, int a);
	// ����������
	virtual ~Person();
	// ����������� ������
	virtual void work() = 0;
	virtual void search_task() = 0;
	// ����� ��� ������ ���������� �� �������
	virtual void displayInfo();
	// �������� ��� ��������� � ����������� �����
	void setName();
	void setAge();
	string getName();
	int getAge();
};
