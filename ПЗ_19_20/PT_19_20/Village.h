#pragma once
#ifndef Village_H
#define Village_H
#include <iostream>
#include <string>
using namespace std;

class Village {
private:
	string country; // ������ �������
	string name; // �������� �������
	int year; // ��� ���������
	int vilagers; // ����� ���������
public:
	// ����������� �� ���������
	Village();
	// ����������� � �����������
	Village(string country, string name, int year, int vilagers);
	// ����������� �����������
	Village(const Village& other);
	// ������ ��� �������������� ������
	void edit();
	// �������
	string getCountry();
	string getName();
	int getYear();
	int getVilagers();
	// �������
	void setCountry(string country);
	void setName(string name);
	void setYear(int year);
	void setVilagers(int vilagers);
	// ���������� ���������� �����/������
	friend ostream& operator<<(ostream& os, Village Village);
	friend istream& operator>>(istream& is, Village& Village);
	// ���������� ��������� < � > ��� ���������
	bool operator<(Village other);
	bool operator>(Village other);
	// ���������� ��������� == ��� ���������
	bool operator==(Village other);
};
#endif