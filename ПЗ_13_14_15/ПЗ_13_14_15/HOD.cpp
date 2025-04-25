#include "HOD.h"


HOD::HOD(string n, int a, string mjr, bool phd, string dep) : Professor(n, a, mjr, phd), depname(dep) {}
// ��������������� ����������� �������
void HOD::work() {
	cout << this->getName() << " ���������� ������� ����." << endl;
}
void HOD::search_task() {
	cout << this->getName() << " ��������� ������������ ���������." << endl;
}
void HOD::displayInfo() {
	Professor::displayInfo();
	cout << "�������� �������� ''" << depname << "''" << "|";
}
// ��������
void HOD::setDepName() {
	setlocale(LC_ALL, "Ru");
	cout << "������� ���������� ������ ������������ �������� " << this->getName() << ": ";
	getline(cin, depname); cin.clear(); cin.ignore(99999, '\n');
}
string HOD::getDepName() {
	return depname;
}
