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

// Функция сортировки Шелла
void shellSort(int arr[], int size) {
    int gap = size / 2;  // Начальный шаг

    // Пока шаг больше 0
    while (gap > 0) {
        // Применяем сортировку вставками для текущего шага
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            // Сдвигаем элементы, пока не найдем правильное место для arr[i]
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        gap /= 2;  // Уменьшаем шаг
    }
}

bool BinSearch(int arr[], int st, int end, int size, int k) {
    int mid = ((st+end)/2);
    while (st <= end) {
        mid = (st + end) / 2;
        if (arr[mid] < k) {
            st = mid+1;
        }
        else {
            end = mid-1;
        }
        if (arr[mid] == k) {
            return true;
        }
    }
    return false;
    
}


int main(){
	setlocale(LC_ALL, "russian");
	srand(time(0));
	const int n = 100;
    int k, st = 0, end = n;
	int m[n];
	for (int i = 0; i < n; i++) {
		m[i] = rand() % 100;
	}
    cout << "Какое число искать???" << endl;
    cin >> k;
    shellSort(m, n);
	cout << "Массив данных: ";
	printArray(m, n);
    cout << BinSearch(m, st, end, n, k);
    return 0;
}