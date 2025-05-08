#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
template <typename T>

class Container {
private:
	vector <T> data;
public:
	// Вставка элемента в контейнер
	void insert(T& item) {
		data.push_back(item);
	}
	// Удаление элемента из контейнера
	void remove() {
		if (!data.empty()) {
			cout << "Удалена деревня: " << data.back() << endl; // Выводим удаляемый элемент
			data.pop_back();
		}	
		else {
			cout << "Очередь пуста. Удаление невозможно.\n";
		}
	}
	// Редактирование элемента по индексу
	void edit() {
		if (!(data.empty())) {
			int index;
			cout << "Введите номер деревни для редактирования: ";
			while (!(cin >> index) || index < 1 || index > data.size()) {
				cout << "Введено неверное значение. Впишите индекс от 1 до " << data.size() << ". \n";
				cin.clear();
				cin.ignore(99999, '\n');
			}
			data[index - 1].edit();
		}
		else cout << "Редактирование невозможно. Список пуст. \n";
	}
	// Вывод всех элементов на экран
	void print() {
		if (!(data.empty())) {
			short u = 1;
			for (auto i : data) {
				cout << u++ << ": " << i << endl;
			}
		}
		else cout << "Показывать нечего. Список пуст. \n";
	}
	// Метод поиска по году с пользовательским вводом и сообщением, если не найден
	void findByYear() {
		if (!(data.empty())) {
			int targetYear;
			cout << "Введите год строительства для поиска: ";
			while (!(cin >> targetYear) || targetYear < 0 || targetYear > 2025) {
				cout << "Некорректный ввод. Введите год от 0 до 2025: ";
				cin.clear(); cin.ignore(99999, '\n');
			}
			cin.clear(); cin.ignore(99999, '\n');
			bool found = false;
			for (auto i : data) {
				if (i.getYear() == targetYear) {
					cout << "Найдена деревня: " << i << "\n";
					found = true;
				}
			}
			if (!found) {
				cout << "Деревни с годом строительства " << targetYear << " не найдены.\n";
			}
		}
		else cout << "Поиск невозможен. Список пуст. \n";
	}
	// Сортировка элементов контейнера по возрастанию
	void sortDescending() {
		if (data.size() >= 2) {
			sort(data.begin(), data.end(), [](T& a, T& b) { return a > b; });
			cout << "Сортировка по убыванию выполнена успешно\n";
		}
		else cout << "Сортировка невозможна. В списке недостаточно элементов. \n";
	}		
};
#endif