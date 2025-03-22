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

bool interpolationSearch(int arr[], int st, int end, int size, int k) {
        int mid = st+((k-arr[st])*(end - st)/arr[end]-arr[st]);
        while (arr[mid] != k && mid > 1) {
            mid = st + ((k - arr[st]) * (end - st) / arr[end] - arr[st]);
            if (mid > k) {
                st = mid;
            }
            else {
                end = mid;
            }
            if (arr[mid] == k) {
                return true;
            }
        }
        return false;

    }

int main() {
    setlocale(LC_ALL, "russian");
    srand(time(0));
    const int n = 100;
    int k, st = 0, end = n - 1;
    int m[n];
    for (int i = 0; i < n; i++) {
        m[i] = rand() % 100;
    }
    cout << "Введите искомое число: ";
    cin >> k;
    shellSort(m, n);
    cout << "Массив данных: ";
    printArray(m, n);
    cout << interpolationSearch(m, st, end, n, k);
    return 0;
}