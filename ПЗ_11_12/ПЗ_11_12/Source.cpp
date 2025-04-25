#include <iostream>
#include <string>
using namespace std;

string find(string s1, string s2) {
	int poin1 = s1.find(".");
	int poin2 = s2.find(".");
	if ( s1.find(".") != string::npos ) {
		if (s2.find(".") != string::npos) {
			if (s1.find(".") < s2.find(".")) return "<";
			else if (s1.find(".") > s2.find(".")) return "<";
			else if (s1.find(".") == s2.find(".")) {
				for (long double i = 0; i < s1.size(); i++) {
					if (s1[i] > s2[i]) return ">";
					else if (s1[i] < s2[i]) return "<";
					else if (s1[i] == s2[i] && i == s1.size()) return "=";
				}
			}
		}
		else {
			if (s1.find(".") < s2.size()) return "<";
			else if (s1.find(".") > s2.size()) return ">";
			else return ">";
		}
	}
	else if (s2.find(".") != string::npos) {
		if (s1.size() > s2.find(".")) return ">";
		else if (s1.size() < s2.find(".")) return "<";
		else return "<";
	}
	else {
		if (s1.size() < s2.size()) {
			return "<";
		}
		else if (s1.size() > s2.size()) {
			return ">";
		}
		else {
			for (long double i = 0; i < s1.size(); i++) {
				if (s1[i] > s2[i]) return ">";
				else if (s1[i] < s2[i]) return "<";
				else if (s1[i] == s2[i] && i == s1.size()) return "=";
			}
		}
	}

}

int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	cout << find(str1, str2);
}