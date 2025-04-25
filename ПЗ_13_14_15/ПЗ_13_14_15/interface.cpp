#include "PersonList.h"
#include "Student.h"
#include "Person.h"
#include "Professor.h"
#include "HOD.h"

int main() {
	setlocale(LC_ALL, "Ru");
	PersonList PersonList;
	while (true) {
		PersonList.DisplayMenu();
		int choice = PersonList.AskDoing();
		cin.clear();
		if (choice == 1) {
			PersonList.addPerson();
		}
		else if (choice == 2) {
			PersonList.removePerson();
		}
		else if (choice == 3) {
			PersonList.editPerson();
		}
		else if (choice == 4) {
			PersonList.displayPersons();
		}
		else if (choice == 5) {
			PersonList.searchByName();
		}
		else if (choice == 6) {
			cout << "Выполняется выход" << endl;
			return 0;
		}
		cout << endl << endl;
	}
}
