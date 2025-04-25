#include "PersonList.h"

int PersonList::AskDoing() {
	int choice;
	cout << "Введите номер действия от 1 до 6: ";
	while (!(cin >> choice) || choice < 1 || choice > 6) {
		cout << "Неверный ввод! Поробуйте снова." << endl; cin.clear(); cin.ignore(99999, '\n');
	}
	return choice;
}
void PersonList::DisplayMenu() {
	cout << "1. Добавить персону\n";
	cout << "2. Удалить персону\n";
	cout << "3. Редактировать персону\n";
	cout << "4. Вывести список на экран\n";
	cout << "5. Поиск персоны по имени\n";
	cout << "6. Выход\n";
}
PersonList::PersonList() {
	Person* persons[MAX_PERSONS] = { nullptr };
	count = 0;
}
PersonList::~PersonList() {
	for (int i = 0; i < count; i++) {
		delete persons[i];
	}
}
int PersonList::getCount() {
	return count;
}
void PersonList::addPerson() {
	setlocale(LC_ALL, "Ru");
	if (count == 10) {
		cout << " Массив заполнен полностью, удалите один из объектов, чтобы добавить новый. " << endl;
	}
	else {
		int tpe = getType(); // выбор положения
		if (tpe == 1) {
			// Создание хранилища значения полей
			HOD person{ "", 0, "", false, "" };
			person.setName();
			person.setAge();
			person.setMajor();
			person.setPHD();
			person.setDepName();
			// Перевод данных в ссылку
			Person* n_person = new HOD(person.getName(), person.getAge(), person.getMajor(), person.getPHD(), person.getDepName());
			persons[count] = n_person;
			person.search_task();
			person.work();
			PersonList::count++;
		}

		else if (tpe == 2) {
			Professor person{ "", 0, "", false };
			person.setName();
			person.setAge();
			person.setMajor();
			person.setPHD();

			Person* n_person = new Professor(person.getName(), person.getAge(), person.getMajor(), person.getPHD());
			persons[count] = n_person;
			PersonList::count++;
			person.search_task();
			person.work();
		}
		else if (tpe == 3) {
			Student person{ "", 0, "" };
			person.setName();
			//person.setName();
			person.setAge();
			person.setMajor();

			Person* n_person = new Student(person.getName(), person.getAge(), person.getMajor());
			persons[count] = n_person;
			PersonList::count++;
			person.search_task();
			person.work();
		}
	}
}
void PersonList::removePerson() {
	if (getCount() == 0) {
		cout << "В массиве нет персон\n";
	}
	else {
		int index = getNumber();
		for (int i = index; i < count - 1; i++) {
			persons[i] = persons[++i];
		}
		cout << "персона удалена.\n";
		persons[count - 1] = nullptr;
		PersonList::count--;
	}
}
void PersonList::editPerson() {
	if (getCount() == 0) {
		cout << "В массиве нет персон\n";
	}
	else {
		while (true) {
			int index = getNumber();
			int sw = 0;
			cout << "-------------------------------" << endl;
			cout << "Введите номер того, что вы хотите заменить: 1-имя, 2- возраст" << endl;
			cin >> sw; cin.clear(); cin.ignore(99999, '\n');
			if (sw == 1) {
				persons[index]->setName();
				break;
			}
			else if (sw == 2) {
				persons[index]->setAge();
				break;
			}
			else cout << "Неверное значение, повторите попытку" << endl; cin.clear();
		}
	}
}
void PersonList::displayPersons() {
	if (getCount() == 0) {
		cout << "В массиве нет персон\n";
	}
	else {
		for (int i = 0; i < count; i++) {
			cout << 1 + i << ". ";
			persons[i]->displayInfo();
			cout << endl;
		}
	}
}
void PersonList::searchByName() {
	setlocale(LC_ALL, "Ru");
	int coun = 0;
	if (getCount() == 0) {
		cout << "В массиве нет персон\n";
	}
	else {
		cin.clear(); cin.ignore(99999, '\n');
		string s_name;
		cout << "Введите имя персоны для поиска: ";
		getline(cin, s_name);
		cin.clear(); cin.ignore(99999, '\n');
		for (int i = 0; i < count; i++) {
			if (persons[i]->getName() == s_name) {
				cout << "Информация о " << s_name << ":" << endl;
				persons[i]->displayInfo();
				cout << endl;
				coun++;
			}
		}
	}
	if (coun == 0) cout << "В массиве нет персон с таким именем." << endl;
}
int PersonList::getNumber() {
	int number;
	cout << "Введите номер персоны (1-" << count << "): ";
	while (!(cin >> number) || number <= 0 || number > count) {
		cout << "Неверный номер! Попробуйте снова: " << endl;
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return number - 1;
}
int PersonList::getType() {
	cout << "Введите тип персоны (1: Заведующий кафедрой, 2: Профессор, 3: Студент): ";
	int pos;
	cin >> pos;
	while (pos <= 0 || pos > 3) {
		cout << "Неверный номер! Попробуйте снова: ";
		cin >> pos;
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return pos;
}
