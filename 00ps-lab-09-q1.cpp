#include <iostream>
using namespace std;


class ArrayMultiplier {
public:
    virtual void calculate() = 0; 
    virtual ~ArrayMultiplier() {}
};


class ArrayMultiplier1D : public ArrayMultiplier {
private:
    int* array1;
    int* array2;
    int* result;
    int size;

public:
    ArrayMultiplier1D(int* a1, int* a2, int s)
        : array1(a1), array2(a2), size(s) {
        result = new int[size];
    }

    void calculate() override {
        for (int i = 0; i < size; ++i) {
            result[i] = array1[i] * array2[i];
        }

       
        for (int i = 0; i < size; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    ~ArrayMultiplier1D() {
        delete[] result;
    }
};


class ArrayMultiplier2D : public ArrayMultiplier {
private:
    int (*matrix1)[2];
    int (*matrix2)[2];
    int result[2][2];
    int rows, cols;

public:
    ArrayMultiplier2D(int m1[2][2], int m2[2][2])
        : matrix1(m1), matrix2(m2), rows(2), cols(2) {}

    void calculate() override {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = matrix1[i][j] * matrix2[i][j];
            }
        }

        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 1D Example
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    ArrayMultiplier* mult1D = new ArrayMultiplier1D(arr1, arr2, 3);
    mult1D->calculate();
    delete mult1D;

  
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};
    ArrayMultiplier* mult2D = new ArrayMultiplier2D(mat1, mat2);
    mult2D->calculate();
    delete mult2D;

    return 0;
}
