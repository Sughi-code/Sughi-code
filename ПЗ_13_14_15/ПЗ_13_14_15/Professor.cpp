#include "Professor.h"

Professor::Professor(string n, int a, string mjr, bool  mind) : Student(n, a, mjr), PHD(mind) {}
// ��������������� ����������� �������
void Professor::work() {
	cout << this->getName() << " ������������� ������� �������." << endl;
}
void Professor::search_task() {
	cout << this->getName() << " ������ �������� ������� ������������ ����� �������." << endl;
}
void Professor::displayInfo() {
	Student::displayInfo();
	cout << (PHD ? "����� ���������� �������" : "�� ����� ���������� �������") << "| ";
}
// ��������
void Professor::setPHD() {
	string flag;
	cout << "���� �� ���������� ������� � " << this->getName() << "? " << endl << "���� - 1, ��� - ����� ������ ����" << endl;
	getline(cin, flag);
	cin.clear(); cin.ignore(99999, '\n');
	PHD = (flag == "1") ? true : false;
}
bool Professor::getPHD() {
	return PHD;
}
