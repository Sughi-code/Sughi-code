#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Pack { // ���������� ����� �������
	// ���� �����
	string number;
	double weight;
	double cost;
	short delivDate[3];
	string delivPlace;
	// ����� ������
	Pack* next;
};

