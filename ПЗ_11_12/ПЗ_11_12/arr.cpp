/*#include <iostream>
void func(int** a, int n, int m) {
	int seed;
	std:: cin >> seed;
	for (int i = 0; i < n; i++) {
		for (int* el = a[i]; el < a[i] + m; el++) {
			*el = seed + i;
		}
	}
}
int main() {
	int n, m;
	std::cin >> n >> m;
	int** arr = new int* [n];
	for (short i = 0; i < n; i++) {
		*(arr + i) = new int[m];
	}
	func(arr, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << *(*(arr + i) +j) << " ";
		}
		std::cout << std::endl;
	}
}*/