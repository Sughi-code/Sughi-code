#include "HOD.h"


HOD::HOD(string n, int a, string mjr, bool phd, string dep) : Professor(n, a, mjr, phd), depname(dep) {}
// Переопределение виртуальных методов
void HOD::work() {
	cout << this->getName() << " составляет учебный план." << endl;
}
void HOD::search_task() {
	cout << this->getName() << " проверяет актуальность программы." << endl;
}
void HOD::displayInfo() {
	Professor::displayInfo();
	cout << "Заведует кафедрой ''" << depname << "''" << "|";
}
// Свойства
void HOD::setDepName() {
	setlocale(LC_ALL, "Ru");
	cout << "Введите заведующим какого департамента является " << this->getName() << ": ";
	getline(cin, depname); cin.clear(); cin.ignore(99999, '\n');
}
string HOD::getDepName() {
	return depname;
}
