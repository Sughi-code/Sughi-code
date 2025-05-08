#include <iostream>
#include <fstream>
#include "Village.h"
#include "Container.h"
#include <windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Container<Village> Villages;
	int choice;
	while (true) {
		cout << "\n--- МЕНЮ ---\n";
		cout << "1. Добавить деревню\n";
		cout << "2. Редактировать деревню\n";
		cout << "3. Удалить деревню\n";
		cout << "4. Показать все деревни\n";
		cout << "5. Поиск данных по условию\n";
		cout << "6. Сортировка по убыванию\n";
		cout << "0. Выход\n";
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			Village Village;
			cout << "Введите данные деревни (страна, название, год строительства, объем населения): \n";
			cin >> Village;
			Villages.insert(Village);
			break;
		}
		case 2: {
			Villages.edit();
			break;
		}
		case 3:
			Villages.remove();
			break;
		case 4:
			Villages.print();
			break;
		case 5:
			Villages.findByYear();
			break;
		case 6:
			Villages.sortDescending();
			break;
		case 0:
			cout << "Хорошего дня.До свидания! \n";
			return 0;
			break;
		default:
			cout << "Неверный выбор! Попробуйте снова.\n";
		}
	}
}