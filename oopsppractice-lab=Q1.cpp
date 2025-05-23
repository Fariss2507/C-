#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols));
    }

    // Input function
    void input() {
        cout << "Enter matrix values:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    // Overload + operator to add two matrices
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix sizes do not match for addition!");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Friend function to display the matrix
    friend void display(const Matrix<T>& m) {
        cout << "Matrix:\n";
        for (const auto& row : m.data) {
            for (T val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    // Sort each row of the matrix
    void sortRows() {
        for (auto& row : data) {
            sort(row.begin(), row.end());
        }
    }
};

int main() {
    try {
        Matrix<double> m1(2, 2), m2(2, 2);
        m1.input();
        m2.input();

        Matrix<double> sum = m1 + m2;

        cout << "\nSorted Matrix 1:\n";
        m1.sortRows();
        display(m1);

        cout << "\nSorted Matrix 2:\n";
        m2.sortRows();
        display(m2);

        cout << "\nSum of Matrices:\n";
        display(sum);
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
