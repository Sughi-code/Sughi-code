#pragma once
#include "Person.h"
#include "HOD.h"
const int MAX_PERSONS = 10;

class PersonList {

private:
	int count;
	Person* persons[MAX_PERSONS];
public:

	// Конструктор
	PersonList();

	// Деструктор
	~PersonList();

	// Метод для запроса выбора действия в меню
	int AskDoing();

	// Метод для вывода меню выбора
	void DisplayMenu();

	//Метод для получения количества персон
	int getCount();

	// Метод для добавления персоны
	void addPerson();

	// Метод для удаления персоны
	void removePerson();

	// Метод для редактирования персоны
	void editPerson();

	// Метод для отображения всех персон
	void displayPersons();

	// Метод для поиска персоны по имени
	void searchByName();

	//Интерфейс
	// Метод для запроса номера объекта в границах массива
	int getNumber();

	// Метод для запроса номера типа объекта
	int getType();
};
