#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int maxCount = 0;
    int candidate = -1;

    // for (int i = 0; i < size; i++){
    //     if (count == 0){
    //         candidate = arr[i];
    //         count = 1;
    //     }else if (arr[i] == candidate){
    //         count++;
    //     }else {
    //         count--;
    //     }
    // }

    // count = 0;
    // for (int i = 0; i < size; i++){
    //     if (arr[i] == candidate){
    //         count++;
    //     }
    // }

    for (int i = 0; i < size; i++){
        int count = 0;
        for (int j = 0; j < size; j++){
            if (arr[i] == arr[j]){
                count++;
            }
        }
        if (count > maxCount){
            maxCount = count;
            candidate = arr[i];
        }
    }
    
    if (maxCount > size / 2){
        cout << "Majority element is: " << candidate << endl;
    } else {
        cout << "No majority element found." << endl;
    }
}