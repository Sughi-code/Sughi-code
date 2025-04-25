#pragma once
#include "Person.h"
#include "Student.h"
#include "Professor.h"

class HOD : public Professor {

private:
	string depname;
public:
	HOD(string n, int a, string mjr, bool phd, string dep);

	// ��������������� ����������� �������
	void work()  override;
	void search_task()  override;
	void displayInfo()  override;
	// ��������
	void setDepName();
	string getDepName();
};
