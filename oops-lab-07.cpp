# include<iostream>
using namespace std;

class Dynamic2DArray {
private:
    int** array;
    int rows;
    int cols;
    public:
    Dynamic2DArray(int r, int c) : rows(r), cols(c) {
        array = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new int[cols];
        }
    }
    ~Dynamic2DArray() {
        for (int i = 0; i < rows; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }
};
int main() {
    int rows = 3, cols = 4;
    Dynamic2DArray arr(rows, cols);
    cout << "Dynamic 2D array created with " << rows << " rows and " << cols << " columns." << endl;
    return 0;
}