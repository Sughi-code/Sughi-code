#pragma once
#include <iostream>
#include "Package.h"
#include <string>
using namespace std;

struct Stack {
	// поля стэка
	double cost;
	string place;
	// связь списка
	Stack* next;
};