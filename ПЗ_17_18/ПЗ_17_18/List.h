#include "Stack.h"
#pragma once

// функции для меню интерфейса
short getCount(Pack* endQ);
short getCountp(Stack* placesCost);
short AskDoing();
void DisplayMenu();
void addPackage(Pack*& endQ, Pack*& begQ);
void removePackage(Pack*& endQ, Pack*& begQ);
void editPackage(Pack*& endQ);
void displayPackages(Pack* endQ);
void delivList(Pack* endQ);
void delivCost(Pack* endQ, Pack* begQ);