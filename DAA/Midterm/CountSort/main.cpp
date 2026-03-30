#include <iostream>
using namespace std;

int max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int min(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int* countSort(int arr[], int size) {
    int maxVal = max(arr, size);
    int minVal = min(arr, size);

    int countSize = maxVal - minVal + 1;
    int* count = (int*)calloc(countSize, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i] - minVal]++;
    }

    cout << "FREQUENCY = ";
    for(int i = 0; i < countSize; i++){
        cout << count[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < countSize; i++) {
        count[i] += count[i - 1];
    }

    cout << "CUMU FREQ = ";
    for(int i = 0; i < countSize; i++){
        cout << count[i] << " ";
    }
    cout << endl;

    int* res = new int[size];
    for (int i = size - 1; i >= 0; i--) {
        res[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    return res;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        cin >> arr[i];
    }

    int* sorted = countSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << sorted[i] << " ";
    }

    return 0;
}