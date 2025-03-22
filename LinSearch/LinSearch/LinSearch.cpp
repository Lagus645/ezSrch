#include <iostream>
#include <clocale>
#include <ctime>
#include <stdlib.h>
using namespace std;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int linSearch(int arr[], int size, int k) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == k) {
			return i+1;
		}
	}
	return -1;
}

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(0));
	int k;
	const int n = 100;
	int m[n];
	for (int i = 0; i < n; i++) {
		m[i] = rand() % 100;
	}
	cout << "Массив данных: ";
	printArray(m, n);
	cout << "Введите искомое число: ";
	cin >> k;
	cout << linSearch(m, n, k);
	return 0;
}