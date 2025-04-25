#pragma once
#include "Person.h"
#include "HOD.h"
const int MAX_PERSONS = 10;

class PersonList {

private:
	int count;
	Person* persons[MAX_PERSONS];
public:

	// �����������
	PersonList();

	// ����������
	~PersonList();

	// ����� ��� ������� ������ �������� � ����
	int AskDoing();

	// ����� ��� ������ ���� ������
	void DisplayMenu();

	//����� ��� ��������� ���������� ������
	int getCount();

	// ����� ��� ���������� �������
	void addPerson();

	// ����� ��� �������� �������
	void removePerson();

	// ����� ��� �������������� �������
	void editPerson();

	// ����� ��� ����������� ���� ������
	void displayPersons();

	// ����� ��� ������ ������� �� �����
	void searchByName();

	//���������
	// ����� ��� ������� ������ ������� � �������� �������
	int getNumber();

	// ����� ��� ������� ������ ���� �������
	int getType();
};
