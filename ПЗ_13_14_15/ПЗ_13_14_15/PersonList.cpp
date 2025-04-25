#include "PersonList.h"

int PersonList::AskDoing() {
	int choice;
	cout << "������� ����� �������� �� 1 �� 6: ";
	while (!(cin >> choice) || choice < 1 || choice > 6) {
		cout << "�������� ����! ��������� �����." << endl; cin.clear(); cin.ignore(99999, '\n');
	}
	return choice;
}
void PersonList::DisplayMenu() {
	cout << "1. �������� �������\n";
	cout << "2. ������� �������\n";
	cout << "3. ������������� �������\n";
	cout << "4. ������� ������ �� �����\n";
	cout << "5. ����� ������� �� �����\n";
	cout << "6. �����\n";
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
		cout << " ������ �������� ���������, ������� ���� �� ��������, ����� �������� �����. " << endl;
	}
	else {
		int tpe = getType(); // ����� ���������
		if (tpe == 1) {
			// �������� ��������� �������� �����
			HOD person{ "", 0, "", false, "" };
			person.setName();
			person.setAge();
			person.setMajor();
			person.setPHD();
			person.setDepName();
			// ������� ������ � ������
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
		cout << "� ������� ��� ������\n";
	}
	else {
		int index = getNumber();
		for (int i = index; i < count - 1; i++) {
			persons[i] = persons[++i];
		}
		cout << "������� �������.\n";
		persons[count - 1] = nullptr;
		PersonList::count--;
	}
}
void PersonList::editPerson() {
	if (getCount() == 0) {
		cout << "� ������� ��� ������\n";
	}
	else {
		while (true) {
			int index = getNumber();
			int sw = 0;
			cout << "-------------------------------" << endl;
			cout << "������� ����� ����, ��� �� ������ ��������: 1-���, 2- �������" << endl;
			cin >> sw; cin.clear(); cin.ignore(99999, '\n');
			if (sw == 1) {
				persons[index]->setName();
				break;
			}
			else if (sw == 2) {
				persons[index]->setAge();
				break;
			}
			else cout << "�������� ��������, ��������� �������" << endl; cin.clear();
		}
	}
}
void PersonList::displayPersons() {
	if (getCount() == 0) {
		cout << "� ������� ��� ������\n";
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
		cout << "� ������� ��� ������\n";
	}
	else {
		cin.clear(); cin.ignore(99999, '\n');
		string s_name;
		cout << "������� ��� ������� ��� ������: ";
		getline(cin, s_name);
		cin.clear(); cin.ignore(99999, '\n');
		for (int i = 0; i < count; i++) {
			if (persons[i]->getName() == s_name) {
				cout << "���������� � " << s_name << ":" << endl;
				persons[i]->displayInfo();
				cout << endl;
				coun++;
			}
		}
	}
	if (coun == 0) cout << "� ������� ��� ������ � ����� ������." << endl;
}
int PersonList::getNumber() {
	int number;
	cout << "������� ����� ������� (1-" << count << "): ";
	while (!(cin >> number) || number <= 0 || number > count) {
		cout << "�������� �����! ���������� �����: " << endl;
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return number - 1;
}
int PersonList::getType() {
	cout << "������� ��� ������� (1: ���������� ��������, 2: ���������, 3: �������): ";
	int pos;
	cin >> pos;
	while (pos <= 0 || pos > 3) {
		cout << "�������� �����! ���������� �����: ";
		cin >> pos;
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return pos;
}
