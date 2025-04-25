#include "List.h"

// промежуточные функции
// вывод размерности стэка Pack
short getCount(Pack* endQ) { 
	short count = 0;
	while (endQ) {
		count++;
		endQ = endQ->next;
	}
	return count;
}
// вывод размерности очереди Stack
short getCountp(Stack* placesCost) { 
	short count = 0;
	while (placesCost) {
		count++;
		placesCost = placesCost->next;
	}
	return count;
}
// функции меню
short AskDoing() {
	short choice;
	cout << "Введите номер действия от 1 до 7: ";
	while (!(cin >> choice) || choice < 1 || choice > 7) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return choice;
}
// вывод информации
void DisplayMenu() { 
	cout << "1. Добавить поссылку\n";
	cout << "2. Удалить поссылку\n";
	cout << "3. Редактировать поссылку\n";
	cout << "4. Вывести список на экран\n";
	cout << "5. Вывести список пунктов назначения и номеров посылок, второго кваритля прошлого года\n";
	cout << "6. Вывести стоимость отправленных посылок\n";
	cout << "7. Выход\n";
}
// добавление посылки
void addPackage(Pack*& endQ, Pack*& begQ) {
	Pack* Fedro = new Pack;
	// получение значений полей поссылки
	cout << "Введите номер поссылки: ";
	getline(cin, Fedro->number);
	cout << "Введите вес поссылки в килограммах: ";
	while (!(cin >> Fedro->weight) || Fedro->weight < 0) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "Введите стоимость поссылки в рублях: ";
	while (!(cin >> Fedro->cost) || Fedro->cost < 0) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "Введите день отправления поссылки: ";
	while (!(cin >> Fedro->delivDate[0]) || Fedro->delivDate[0] < 0 || Fedro->delivDate[0] > 31) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "Введите месяц отправления поссылки: ";
	while (!(cin >> Fedro->delivDate[1]) || Fedro->delivDate[1] < 0 || Fedro->delivDate[1] > 31) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "Введите год отправления поссылки: ";
	while (!(cin >> Fedro->delivDate[2]) || Fedro->delivDate[2] < 0) {
		cout << "Неверный ввод! Поробуйте снова." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "Введите место доставки поссылки:";
	getline(cin, Fedro->delivPlace); 
	cin.clear(); cin.ignore(9999, '\n');
	// перезапись вершины и начала при создании первой посылки
	if ( endQ == NULL && begQ == NULL) {
		Fedro->next = begQ;
		begQ = Fedro;
		endQ = Fedro;
	}
	// создание не первой посылки
	else {
		Fedro->next = endQ;
		endQ = Fedro;
	}
}
// удаление посылки
void removePackage(Pack*& endQ, Pack*& begQ) {
	if (getCount(endQ) == 0) {
		cout << "Список пуст.\n";
		return;
	}
	Pack* Fedro = endQ;
	// проверка верхнего элемента на удаление при 1 вхождении
	if (getCount(endQ) == 1) {
		delete Fedro;
		begQ = NULL;
		endQ = NULL;
		cout << "Объект успешно удален. \n";
		return;
	}
	// удаление первого элемента в др случае
	else {
		// поиск 2 элемента
		Pack* flag = endQ;
		while (flag->next->next != NULL) {
			flag = flag->next;
		}
		begQ = flag;
		begQ->next = NULL;
		flag = flag->next;
		delete flag;
		cout << "Объект успешно удален. \n";
	}
}
// редакция посылки
void editPackage(Pack*& endQ) { 
	if (getCount(endQ) == 0) {
		cout << "Список пуст.\n";
		return;
	}
	else {
		Pack* Fedro = endQ;
		// выбор поля редакции
		short choice;
		cout << "Введите что вы хотите изменить (1-номер поссылки; 2- вес посылки; 3- цену посылки; 4- дату отправления; 5- место назначения;): ";
		while (!(cin >> choice) || choice < 0 || choice > 5) {
			cout << "Неверный ввод! Поробуйте снова." << endl; 
			cin.clear(); cin.ignore(99999, '\n');
		}
		cin.clear(); cin.ignore(99999, '\n');
		// редакция номера
		if (choice == 1) { 
			string num;
			cout << "Введите новый номер поссылки: ";
			getline(cin, num);
			cin.clear(); cin.ignore(99999, '\n');
			Fedro->number = num;
		}
		// редакция веса
		else if (choice == 2) { 
			cout << "Введите новый вес поссылки в килограммах: ";
			while (!(cin >> Fedro->weight) || Fedro->weight < 0) {
				cout << "Неверный ввод! Поробуйте снова." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// редакция стоимости
		else if (choice == 3) { 
			cout << "Введите новую стоимость поссылки в рублях: ";
			while (!(cin >> Fedro->cost) || Fedro->cost < 0) {
				cout << "Неверный ввод! Поробуйте снова." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// редакция даты
		else if (choice == 4) {
			cout << "Введите новый день отправления поссылки: ";
			while (!(cin >> Fedro->delivDate[0]) || Fedro->delivDate[0] < 0 || Fedro->delivDate[0] > 31) {
				cout << "Неверный ввод! Поробуйте снова." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
			cout << "Введите новый месяц отправления поссылки: ";
			while (!(cin >> Fedro->delivDate[1]) || Fedro->delivDate[1] < 0 || Fedro->delivDate[1] > 12) {
				cout << "Неверный ввод! Поробуйте снова." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
			cout << "Введите новый год отправления поссылки: ";
			while (!(cin >> Fedro->delivDate[2]) || Fedro->delivDate[2] < 0) {
				cout << "Неверный ввод! Поробуйте снова." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// редакция места
		else if (choice == 5) { 
			string place;
			cout << "Введите новое место доставки поссылки:";
			getline(cin, place); 
			cin.clear(); cin.ignore(9999, '\n');
			Fedro->delivPlace = place;
		}
	}
}
// вывод информации о посылках
void displayPackages(Pack* endQ) {
	if (getCount(endQ) == 0) {
		cout << "Список пуст.\n";
		return;
	}
	else {
		// вывод информации всего списка
		short al = getCount(endQ);
		short i = 1;
		Pack* Fedro = endQ;
		while (Fedro) {
			cout << "\nОчередь поссылки: " << al - i++ + 1;
			cout << "\nНомер поссылки: " << Fedro->number;
			cout << "\nВес поссылки: " << Fedro->weight;
			cout << "\nСтоимость поссылки: " << Fedro->cost;
			cout << "\nДата отправления поссылки: " << Fedro->delivDate[0] << "." << Fedro->delivDate[1] << "." << Fedro->delivDate[2] << ".";
			cout << "\nМесто назначения поссылки: " << Fedro->delivPlace;
			Fedro = Fedro->next;
			cout << "\n--------------------------\n";
		}
	}
}
// вывод посылок, отправленных во втором квартиле прошлого года
void delivList(Pack* endQ) {
	if (getCount(endQ) == 0) {
		cout << "Список пуст.\n";
		return;
	}
	else {
		Pack* Fedro = endQ;
		bool flag = false;
		while (Fedro) {
			// поиск подходящей даты
			if (Fedro->delivDate[1] <= 6 && Fedro->delivDate[1] >= 4 && Fedro->delivDate[2] == 2024) { 
				cout << "\nНомер поссылки: " << Fedro->number;
				cout << "\nМесто назначения поссылки: " << Fedro->delivPlace;
				flag = true;
			}
			Fedro = Fedro->next;
		}
		if (!flag) cout << "Во втором квартиле прошлого года посылок не отправлено.  \n";
	}
}
// вывод суммы цен посылок для каждого места назначения по актуальному составу посылок
void delivCost(Pack* endQ, Pack* begQ) {
	if (getCount(endQ) == 0) {
		cout << "Список пуст.\n";
		return;
	}
	else {
		Stack* placesCost = NULL; // вершина стэка стоимостей посылок для каждого места
		Pack* Fedro = endQ;
		// ищем место для каждого элемента
		while (Fedro != NULL) { 
			string place = Fedro->delivPlace;
			bool flag = false;
			// когда в стэке уже есть места
			Stack* CurPlace = placesCost;
			while (CurPlace != NULL) {
				// когда место стэка совпадает с местом отправки
				if (CurPlace->place == Fedro->delivPlace) {
					CurPlace->cost += Fedro->cost;
					flag = true;
				}
				// переход
				CurPlace = CurPlace->next;
			}
			//добавление нового места 
			if (!flag) { // если элемент никуда не прибавился
				Stack* newPlace = new Stack;
				newPlace->place = Fedro->delivPlace;
				newPlace->cost = Fedro->cost;
				newPlace->next = placesCost;
				placesCost = newPlace;
			}
			Fedro = Fedro->next;
		}
		// вывод собранных значений
		while (placesCost != NULL) {
			cout << "На место " << placesCost->place;
			cout << " отправлено посылок на сумму- " << placesCost->cost << endl;
			Stack* flag = placesCost;
			placesCost = placesCost->next;
			delete flag;
		}
	}
}