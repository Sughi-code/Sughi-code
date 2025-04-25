#include "List.h"

int main() {
	setlocale(LC_ALL, "Ru");
	Pack* endQ = NULL;
	Pack* begQ = NULL;
	while (true) {
		// Получение и запись выбора пользователя
		DisplayMenu();
		short choice = AskDoing();
		cin.clear();
		if (choice == 1) {
			addPackage(endQ, begQ);
		}
		else if (choice == 2) {
			removePackage(endQ, begQ);
		}
		else if (choice == 3) {
			editPackage(endQ);
		}
		else if (choice == 4) {
			displayPackages(endQ);
		}
		else if (choice == 5) {
			delivList(endQ);
		}
		else if (choice == 6) {
			delivCost(endQ, begQ);
		}
		else if (choice == 7) {
			cout << "Выполняется выход";
			return 0;
		}
		cout << endl;
	}
	while (begQ != NULL) {
		Pack* flag = begQ;
		begQ = begQ->next;
		delete flag;
	}
}