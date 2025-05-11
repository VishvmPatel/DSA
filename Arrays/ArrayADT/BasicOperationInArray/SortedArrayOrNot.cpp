#include <iostream>
using namespace std;

//Function to check if the array is sorted or not.
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // If previous element is greater, it's not sorted
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, n))
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    return 0;
}
