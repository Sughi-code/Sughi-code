/*#include <iostream>
#include <string>
using namespace std;

void func(string& str) {
	int len = size(str);
	int fr = str.find(",");
	for (int i = fr; i < len; i++) {
		str[i] = str[i] + 3;
	}
}

int main() {
	string str;
	getline(cin, str);
	cout << size(str);
	func(str);
	cout << str;
	
	return 0;
} */