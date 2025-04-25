#include "Student.h"

Student::Student(string n = "", int a = 0, string mjr = "") : Person(n, a), major(mjr) {}

// ��������������� ����������� �������
void Student::work() {
	cout << this->getName() << " ��������� �������� �������." << endl;
}
void Student::search_task() {
	cout << this->getName() << " ���� �������� ���������� " << this->getMajor() << " ����." << endl;
}
void Student::displayInfo() {
	Person::displayInfo();
	cout << "��� ����: " << this->major << "| ";
}
// ��������
void Student::setMajor() {
	setlocale(LC_ALL, "Ru");
	string core;
	cout << "������� �� ����� ����������� ������� " << this->getName() << ": ";
	cin >> core;
	major = core;
	cin.clear(); cin.ignore(99999, '\n');
}
string Student::getMajor() {
	return major;
}
