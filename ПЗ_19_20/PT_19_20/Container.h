#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
template <typename T>

class Container {
private:
	vector <T> data;
public:
	// ������� �������� � ���������
	void insert(T& item) {
		data.push_back(item);
	}
	// �������� �������� �� ����������
	void remove() {
		if (!data.empty()) {
			cout << "������� �������: " << data.back() << endl; // ������� ��������� �������
			data.pop_back();
		}	
		else {
			cout << "������� �����. �������� ����������.\n";
		}
	}
	// �������������� �������� �� �������
	void edit() {
		if (!(data.empty())) {
			int index;
			cout << "������� ����� ������� ��� ��������������: ";
			while (!(cin >> index) || index < 1 || index > data.size()) {
				cout << "������� �������� ��������. ������� ������ �� 1 �� " << data.size() << ". \n";
				cin.clear();
				cin.ignore(99999, '\n');
			}
			data[index - 1].edit();
		}
		else cout << "�������������� ����������. ������ ����. \n";
	}
	// ����� ���� ��������� �� �����
	void print() {
		if (!(data.empty())) {
			short u = 1;
			for (auto i : data) {
				cout << u++ << ": " << i << endl;
			}
		}
		else cout << "���������� ������. ������ ����. \n";
	}
	// ����� ������ �� ���� � ���������������� ������ � ����������, ���� �� ������
	void findByYear() {
		if (!(data.empty())) {
			int targetYear;
			cout << "������� ��� ������������� ��� ������: ";
			while (!(cin >> targetYear) || targetYear < 0 || targetYear > 2025) {
				cout << "������������ ����. ������� ��� �� 0 �� 2025: ";
				cin.clear(); cin.ignore(99999, '\n');
			}
			cin.clear(); cin.ignore(99999, '\n');
			bool found = false;
			for (auto i : data) {
				if (i.getYear() == targetYear) {
					cout << "������� �������: " << i << "\n";
					found = true;
				}
			}
			if (!found) {
				cout << "������� � ����� ������������� " << targetYear << " �� �������.\n";
			}
		}
		else cout << "����� ����������. ������ ����. \n";
	}
	// ���������� ��������� ���������� �� �����������
	void sortDescending() {
		if (data.size() >= 2) {
			sort(data.begin(), data.end(), [](T& a, T& b) { return a > b; });
			cout << "���������� �� �������� ��������� �������\n";
		}
		else cout << "���������� ����������. � ������ ������������ ���������. \n";
	}		
};
#endif