#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

public:
   
    DynamicArray(int initialSize) : size(0), capacity(initialSize) {
        array = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            array[i] = 0;
        }
    }

   
    ~DynamicArray() {
        delete[] array;
    }

   
    void push(int value) {
        if (size == capacity) {
            // Resize the array if it's full
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = value;
    }

   
    int getSize() const {
        return size;
    }
};

int main() {
    DynamicArray arr(5);

    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);
    arr.push(60); 

    cout << "Array size: " << arr.getSize() << endl;

    return 0;
}