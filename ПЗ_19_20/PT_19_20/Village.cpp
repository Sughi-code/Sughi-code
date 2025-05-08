#include "Village.h"
// ����������� �� ���������
Village::Village() 
	: country(""), name(""), year(0), vilagers(0) {}
// ����������� � �����������
Village::Village(string country, string name, int year, int vilagers) 
	: country(country), name(name), year(year), vilagers(vilagers) { }
// ����������� �����������
Village::Village(const Village& other) : country(other.country), name(other.name), year(other.year), vilagers(other.vilagers) { }
// ����� ��� �������������� ������ � �������
void Village::edit() {
	string newCountry, newName;
	int newYear, newVilagers;
	// �������� ����� ������ ��� ������������
	cout << "������� ����� ������ �������: ";
	cin >> newCountry;
	setCountry(newCountry);
	cout << "������� ����� ��� �������: ";
	cin >> newName;
	setName(newName);
	cout << "������� ����� ��� ���������: ";
	while (!(cin >> newVilagers) || newVilagers < 0 || newVilagers > 2025) {
		cout << "�������� ���! ������� ��� �� 0 �� ��������: ";
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	setYear(newVilagers);
	cout << "������� ����� ���������� �������: ";
	while (!(cin >> newVilagers) || newVilagers < 0) {
		cout << "���������� ������� ������ ���� ������������! ������� ����� : ";
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	setVilagers(newVilagers);
}
// �������
string Village::getCountry() { return country; }
string Village::getName() { return name; }
int Village::getYear() { return year; }
int Village::getVilagers() { return vilagers; }
// �������
void Village::setCountry(string newCountry) { country = newCountry; }
void Village::setName(string newname) { name = newname; }
void Village::setYear(int newYear) { year = newYear; }
void Village::setVilagers(int newVilagers) { vilagers =newVilagers; }
// ���������� ��������� ������
ostream& operator<<(ostream& os, Village Village) {
	os << "������: " << Village.country << ", ���: " << Village.name << ", ��� ���������: " << Village.year << ", ���������� �������: " <<	Village.vilagers;
	return os;
}
// ���������� ��������� �����
istream& operator>>(istream& is, Village& Village) {
	string country, name;
	int year, vilagers;
	cout << "������� ������ �������: ";
	is >> country;
	cout << "������� ��� �������: ";
	is >> name;
	cout << "������� ��� ���������: ";
	while (!(is >> year) || year < 0 || year > 2025) {
		cout << "������������ ����. ������� ��� �� 0 �� 2025: ";
		is.clear(); is.ignore(10000, '\n');
	}
	cout << "������� ���������� �������: ";
	while (!(is >> vilagers) || vilagers < 0) {
		cout << "������������ ����. ������� ������������ ��������: ";
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
// ���������� ��������� < ��� ����������
bool Village::operator<(Village other) {
	return vilagers < other.vilagers;
}
// ���������� ��������� > ��� ����������
bool Village::operator>(Village other) {
	return vilagers > other.vilagers;
}
// ���������� ��������� == ��� �������� �� ���������
bool Village::operator==(Village other) {
	return country == other.country && name == other.name && year == other.year && vilagers == other.vilagers;
}