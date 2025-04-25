#include "List.h"

// ������������� �������
// ����� ����������� ����� Pack
short getCount(Pack* endQ) { 
	short count = 0;
	while (endQ) {
		count++;
		endQ = endQ->next;
	}
	return count;
}
// ����� ����������� ������� Stack
short getCountp(Stack* placesCost) { 
	short count = 0;
	while (placesCost) {
		count++;
		placesCost = placesCost->next;
	}
	return count;
}
// ������� ����
short AskDoing() {
	short choice;
	cout << "������� ����� �������� �� 1 �� 7: ";
	while (!(cin >> choice) || choice < 1 || choice > 7) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	return choice;
}
// ����� ����������
void DisplayMenu() { 
	cout << "1. �������� ��������\n";
	cout << "2. ������� ��������\n";
	cout << "3. ������������� ��������\n";
	cout << "4. ������� ������ �� �����\n";
	cout << "5. ������� ������ ������� ���������� � ������� �������, ������� �������� �������� ����\n";
	cout << "6. ������� ��������� ������������ �������\n";
	cout << "7. �����\n";
}
// ���������� �������
void addPackage(Pack*& endQ, Pack*& begQ) {
	Pack* Fedro = new Pack;
	// ��������� �������� ����� ��������
	cout << "������� ����� ��������: ";
	getline(cin, Fedro->number);
	cout << "������� ��� �������� � �����������: ";
	while (!(cin >> Fedro->weight) || Fedro->weight < 0) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "������� ��������� �������� � ������: ";
	while (!(cin >> Fedro->cost) || Fedro->cost < 0) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "������� ���� ����������� ��������: ";
	while (!(cin >> Fedro->delivDate[0]) || Fedro->delivDate[0] < 0 || Fedro->delivDate[0] > 31) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "������� ����� ����������� ��������: ";
	while (!(cin >> Fedro->delivDate[1]) || Fedro->delivDate[1] < 0 || Fedro->delivDate[1] > 31) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "������� ��� ����������� ��������: ";
	while (!(cin >> Fedro->delivDate[2]) || Fedro->delivDate[2] < 0) {
		cout << "�������� ����! ��������� �����." << endl; 
		cin.clear(); cin.ignore(99999, '\n');
	}
	cin.clear(); cin.ignore(99999, '\n');
	cout << "������� ����� �������� ��������:";
	getline(cin, Fedro->delivPlace); 
	cin.clear(); cin.ignore(9999, '\n');
	// ���������� ������� � ������ ��� �������� ������ �������
	if ( endQ == NULL && begQ == NULL) {
		Fedro->next = begQ;
		begQ = Fedro;
		endQ = Fedro;
	}
	// �������� �� ������ �������
	else {
		Fedro->next = endQ;
		endQ = Fedro;
	}
}
// �������� �������
void removePackage(Pack*& endQ, Pack*& begQ) {
	if (getCount(endQ) == 0) {
		cout << "������ ����.\n";
		return;
	}
	Pack* Fedro = endQ;
	// �������� �������� �������� �� �������� ��� 1 ���������
	if (getCount(endQ) == 1) {
		delete Fedro;
		begQ = NULL;
		endQ = NULL;
		cout << "������ ������� ������. \n";
		return;
	}
	// �������� ������� �������� � �� ������
	else {
		// ����� 2 ��������
		Pack* flag = endQ;
		while (flag->next->next != NULL) {
			flag = flag->next;
		}
		begQ = flag;
		begQ->next = NULL;
		flag = flag->next;
		delete flag;
		cout << "������ ������� ������. \n";
	}
}
// �������� �������
void editPackage(Pack*& endQ) { 
	if (getCount(endQ) == 0) {
		cout << "������ ����.\n";
		return;
	}
	else {
		Pack* Fedro = endQ;
		// ����� ���� ��������
		short choice;
		cout << "������� ��� �� ������ �������� (1-����� ��������; 2- ��� �������; 3- ���� �������; 4- ���� �����������; 5- ����� ����������;): ";
		while (!(cin >> choice) || choice < 0 || choice > 5) {
			cout << "�������� ����! ��������� �����." << endl; 
			cin.clear(); cin.ignore(99999, '\n');
		}
		cin.clear(); cin.ignore(99999, '\n');
		// �������� ������
		if (choice == 1) { 
			string num;
			cout << "������� ����� ����� ��������: ";
			getline(cin, num);
			cin.clear(); cin.ignore(99999, '\n');
			Fedro->number = num;
		}
		// �������� ����
		else if (choice == 2) { 
			cout << "������� ����� ��� �������� � �����������: ";
			while (!(cin >> Fedro->weight) || Fedro->weight < 0) {
				cout << "�������� ����! ��������� �����." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// �������� ���������
		else if (choice == 3) { 
			cout << "������� ����� ��������� �������� � ������: ";
			while (!(cin >> Fedro->cost) || Fedro->cost < 0) {
				cout << "�������� ����! ��������� �����." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// �������� ����
		else if (choice == 4) {
			cout << "������� ����� ���� ����������� ��������: ";
			while (!(cin >> Fedro->delivDate[0]) || Fedro->delivDate[0] < 0 || Fedro->delivDate[0] > 31) {
				cout << "�������� ����! ��������� �����." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
			cout << "������� ����� ����� ����������� ��������: ";
			while (!(cin >> Fedro->delivDate[1]) || Fedro->delivDate[1] < 0 || Fedro->delivDate[1] > 12) {
				cout << "�������� ����! ��������� �����." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
			cout << "������� ����� ��� ����������� ��������: ";
			while (!(cin >> Fedro->delivDate[2]) || Fedro->delivDate[2] < 0) {
				cout << "�������� ����! ��������� �����." << endl; 
				cin.clear(); cin.ignore(99999, '\n');
			}
		}
		// �������� �����
		else if (choice == 5) { 
			string place;
			cout << "������� ����� ����� �������� ��������:";
			getline(cin, place); 
			cin.clear(); cin.ignore(9999, '\n');
			Fedro->delivPlace = place;
		}
	}
}
// ����� ���������� � ��������
void displayPackages(Pack* endQ) {
	if (getCount(endQ) == 0) {
		cout << "������ ����.\n";
		return;
	}
	else {
		// ����� ���������� ����� ������
		short al = getCount(endQ);
		short i = 1;
		Pack* Fedro = endQ;
		while (Fedro) {
			cout << "\n������� ��������: " << al - i++ + 1;
			cout << "\n����� ��������: " << Fedro->number;
			cout << "\n��� ��������: " << Fedro->weight;
			cout << "\n��������� ��������: " << Fedro->cost;
			cout << "\n���� ����������� ��������: " << Fedro->delivDate[0] << "." << Fedro->delivDate[1] << "." << Fedro->delivDate[2] << ".";
			cout << "\n����� ���������� ��������: " << Fedro->delivPlace;
			Fedro = Fedro->next;
			cout << "\n--------------------------\n";
		}
	}
}
// ����� �������, ������������ �� ������ �������� �������� ����
void delivList(Pack* endQ) {
	if (getCount(endQ) == 0) {
		cout << "������ ����.\n";
		return;
	}
	else {
		Pack* Fedro = endQ;
		bool flag = false;
		while (Fedro) {
			// ����� ���������� ����
			if (Fedro->delivDate[1] <= 6 && Fedro->delivDate[1] >= 4 && Fedro->delivDate[2] == 2024) { 
				cout << "\n����� ��������: " << Fedro->number;
				cout << "\n����� ���������� ��������: " << Fedro->delivPlace;
				flag = true;
			}
			Fedro = Fedro->next;
		}
		if (!flag) cout << "�� ������ �������� �������� ���� ������� �� ����������.  \n";
	}
}
// ����� ����� ��� ������� ��� ������� ����� ���������� �� ����������� ������� �������
void delivCost(Pack* endQ, Pack* begQ) {
	if (getCount(endQ) == 0) {
		cout << "������ ����.\n";
		return;
	}
	else {
		Stack* placesCost = NULL; // ������� ����� ���������� ������� ��� ������� �����
		Pack* Fedro = endQ;
		// ���� ����� ��� ������� ��������
		while (Fedro != NULL) { 
			string place = Fedro->delivPlace;
			bool flag = false;
			// ����� � ����� ��� ���� �����
			Stack* CurPlace = placesCost;
			while (CurPlace != NULL) {
				// ����� ����� ����� ��������� � ������ ��������
				if (CurPlace->place == Fedro->delivPlace) {
					CurPlace->cost += Fedro->cost;
					flag = true;
				}
				// �������
				CurPlace = CurPlace->next;
			}
			//���������� ������ ����� 
			if (!flag) { // ���� ������� ������ �� ����������
				Stack* newPlace = new Stack;
				newPlace->place = Fedro->delivPlace;
				newPlace->cost = Fedro->cost;
				newPlace->next = placesCost;
				placesCost = newPlace;
			}
			Fedro = Fedro->next;
		}
		// ����� ��������� ��������
		while (placesCost != NULL) {
			cout << "�� ����� " << placesCost->place;
			cout << " ���������� ������� �� �����- " << placesCost->cost << endl;
			Stack* flag = placesCost;
			placesCost = placesCost->next;
			delete flag;
		}
	}
}