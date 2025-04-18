#include <iostream>
using namespace std;

//THE CODE IS TO CREATE GET,SET,AVG,MAX functions on ARRAYS

class Array {
private:
    int A[100];   // You can change this to dynamic if needed
    int length;

public:
    Array(int arr[], int len) {
        length = len;
        for (int i = 0; i < len; i++) {
            A[i] = arr[i];
        }
    }

    // Get value at index
    int get(int index) {
        if (index >= 0 && index < length)
            return A[index];
        else
            return -1;  // Invalid index
    }

    // Set value at index
    void set(int index, int value) {
        if (index >= 0 && index < length)
            A[index] = value;
    }

    // Find max value
    int max() {
        int maxVal = A[0]; //For min just change all to min
        for (int i = 1; i < length; i++) {
            if (A[i] > maxVal)
                maxVal = A[i];
        }
        return maxVal;
    }

    // Find sum of all elements
    int sum() {
        int total = 0;
        for (int i = 0; i < length; i++) {
            total += A[i];
        }
        return total;
    }

    // Find average
    double avg() {
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += A[i];
        }
        return (double)sum / length;
    }

    // Display all elements
    void display() {
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int initial[] = {10, 20, 30, 40, 50};
    Array arr(initial, 5);

    cout << "Original array: ";
    arr.display();

    cout << "Get element at index 2: " << arr.get(2) << endl;

    arr.set(2, 99);
    cout << "After setting index 2 to 99: ";
    arr.display();

    cout << "Maximum value: " << arr.max() << endl;
    cout << "Sum of elements: " << arr.sum() << endl;
    cout << "Average value: " << arr.avg() << endl;

    return 0;
}