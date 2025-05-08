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
		cout << "\n--- ���� ---\n";
		cout << "1. �������� �������\n";
		cout << "2. ������������� �������\n";
		cout << "3. ������� �������\n";
		cout << "4. �������� ��� �������\n";
		cout << "5. ����� ������ �� �������\n";
		cout << "6. ���������� �� ��������\n";
		cout << "0. �����\n";
		cout << "��� �����: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			Village Village;
			cout << "������� ������ ������� (������, ��������, ��� �������������, ����� ���������): \n";
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
			cout << "�������� ���.�� ��������! \n";
			return 0;
			break;
		default:
			cout << "�������� �����! ���������� �����.\n";
		}
	}
}