#include <iostream>
using namespace std;

// Define the structure to store row, column, and value for each non-zero element
struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows;
    int cols;
    int numNonZero;
    Element *elements;

public:
    // Constructor to initialize the sparse matrix
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        numNonZero = n;
        elements = new Element[numNonZero];  // Dynamically allocate memory for non-zero elements
    }

    // Function to take input for non-zero elements
    void inputElements() {
        cout << "Enter the non-zero elements (row, col, value):\n";
        for (int i = 0; i < numNonZero; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }

    // Function to display the sparse matrix
    void displayMatrix() {
        cout << "Sparse Matrix Representation:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                bool found = false;
                for (int k = 0; k < numNonZero; k++) {
                    if (elements[k].row == i && elements[k].col == j) {
                        cout << elements[k].value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Destructor to free up memory
    ~SparseMatrix() {
        delete[] elements;
    }
};

int main() {
    int rows, cols, numNonZero;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    
    cout << "Enter number of non-zero elements: ";
    cin >> numNonZero;

    SparseMatrix sparse(rows, cols, numNonZero);
    sparse.inputElements();
    sparse.displayMatrix();

    return 0;
}