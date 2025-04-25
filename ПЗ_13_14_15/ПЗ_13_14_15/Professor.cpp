#include "Professor.h"

Professor::Professor(string n, int a, string mjr, bool  mind) : Student(n, a, mjr), PHD(mind) {}
// Переопределение виртуальных методов
void Professor::work() {
	cout << this->getName() << " разрабатывает учебное пособие." << endl;
}
void Professor::search_task() {
	cout << this->getName() << " читает новейшие научные исследования своей области." << endl;
}
void Professor::displayInfo() {
	Student::displayInfo();
	cout << (PHD ? "Имеет докторскую степень" : "Не имеет докторскую степень") << "| ";
}
// Свойства
void Professor::setPHD() {
	string flag;
	cout << "Есть ли докторская степень у " << this->getName() << "? " << endl << "Есть - 1, нет - любой другой ввод" << endl;
	getline(cin, flag);
	cin.clear(); cin.ignore(99999, '\n');
	PHD = (flag == "1") ? true : false;
}
bool Professor::getPHD() {
	return PHD;
}
