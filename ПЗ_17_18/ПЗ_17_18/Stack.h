#pragma once
#include <iostream>
#include "Package.h"
#include <string>
using namespace std;

struct Stack {
	// ���� �����
	double cost;
	string place;
	// ����� ������
	Stack* next;
};