#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Pack { // объявление стэка посылок
	// поля стэка
	string number;
	double weight;
	double cost;
	short delivDate[3];
	string delivPlace;
	// связь списка
	Pack* next;
};

