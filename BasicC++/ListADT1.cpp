#include <iostream>
using namespace std;

//USING ARRAYS

class ArrayList {
    private:
        int* arr;
        int capacity;
        int length;

    public:
        ArrayList(int size) {
            capacity = size;
            arr = new int[capacity];
            length = 0;
        }

        void insert(int index, int value) {
            if (length == capacity || index < 0 || index > length) {
                cout << "Insertion failed!" << endl;
                return;
            }
            for (int i = length; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = value;
            length++;
        }

        void remove(int index) {
            if (index < 0 || index >= length) {
                cout << "Deletion failed!" << endl;
                return;
            }
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }

        void display() {
            for (int i = 0; i < length; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        ~ArrayList() {
            delete[] arr;
        }
};

int main() {
    ArrayList list(5);
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.display();
    list.remove(1);
    list.display();
    return 0;
}
