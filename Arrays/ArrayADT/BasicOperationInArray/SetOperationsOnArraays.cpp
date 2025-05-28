#include <iostream>
using namespace std;

class Array {
public:
    int A[20];     // Array with enough space for union
    int size;
    int length;

    // Default constructor
    Array() {
        size = 20;
        length = 0;
    }

    // Parameterized constructor to initialize with external data
    Array(int arr[], int len) {
        size = 20;
        length = len;
        for (int i = 0; i < len; i++) {
            A[i] = arr[i];
        }
    }

    // Function to display the elements of the array
    void display() const {
        cout << "Elements are: ";
        for (int i = 0; i < length; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // Static function to perform union of two sorted arrays
    static Array Union(const Array& arr1, const Array& arr2) {
        int i = 0, j = 0, k = 0;
        Array arr3;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j])
                arr3.A[k++] = arr1.A[i++];
            else if (arr2.A[j] < arr1.A[i])
                arr3.A[k++] = arr2.A[j++];
            else {
                arr3.A[k++] = arr1.A[i++];
                j++;
            }
        }

        while (i < arr1.length)
            arr3.A[k++] = arr1.A[i++];
        while (j < arr2.length)
            arr3.A[k++] = arr2.A[j++];

        arr3.length = k;
        return arr3;
    }

    // Static function to perform intersection of two sorted arrays
    static Array Intersection(const Array& arr1, const Array& arr2) {
        int i = 0, j = 0, k = 0;
        Array arr3;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j])
                i++;
            else if (arr2.A[j] < arr1.A[i])
                j++;
            else {
                arr3.A[k++] = arr1.A[i++];
                j++;
            }
        }

        arr3.length = k;
        return arr3;
    }

    // Static function to perform difference (arr1 - arr2)
    static Array Difference(const Array& arr1, const Array& arr2) {
        int i = 0, j = 0, k = 0;
        Array arr3;

        while (i < arr1.length && j < arr2.length) {
            if (arr1.A[i] < arr2.A[j])
                arr3.A[k++] = arr1.A[i++];
            else if (arr2.A[j] < arr1.A[i])
                j++;
            else {
                i++;
                j++;
            }
        }

        while (i < arr1.length)
            arr3.A[k++] = arr1.A[i++];

        arr3.length = k;
        return arr3;
    }
};

int main() {
    int data1[] = {2, 9, 21, 28, 35};
    int data2[] = {2, 3, 9, 18, 28};

    Array arr1(data1, 5);
    Array arr2(data2, 5);

    cout << "--- Union ---" << endl;
    Array unionArr = Array::Union(arr1, arr2);
    unionArr.display();

    cout << "--- Intersection ---" << endl;
    Array interArr = Array::Intersection(arr1, arr2);
    interArr.display();

    cout << "--- Difference (arr1 - arr2) ---" << endl;
    Array diffArr = Array::Difference(arr1, arr2);
    diffArr.display();

    return 0;
}
