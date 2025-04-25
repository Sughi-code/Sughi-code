#include "Person.h"


// �����������
Person::Person(string n, int a) : name(n), age(a) {}
// ����������
Person::~Person() = default;
// ��������
void Person::setName() {
	setlocale(LC_ALL, "Ru");
	cout << "������� ��� �������: ";
	getline(cin, this->name);
	cin.clear(); cin.ignore(99999, '\n');
}
void Person::setAge() {
	setlocale(LC_ALL, "Ru");
	cout << "������� ������� ������� " << this->getName() << ": ";
	while (!(cin >> this->age) || this->age <= 0 || this->age > 122) {
		cout << "�������� �������! ���������� �����: ";
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
// ����� ��� ������ ���������� �� �������
void Person::displayInfo() {
	cout << "���: " << this->getName() << "| �������: " << this->getAge() << "| ";
}
