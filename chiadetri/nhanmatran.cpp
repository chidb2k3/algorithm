#include <iostream>
using namespace std;

int** matrixProduct(int A[4][4], int B[4][4], int n) {
    int** C = new int*[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;  
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int n = 4;
    int A[4][4] = {{1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23} ,{25, 27, 29, 31}};
    int B[4][4] = {{2, 4, 6, 8}, {10, 12, 14, 16}, {18,20,22,24}, {26,28,30,32}};
    cout << "Ma tran A\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
     cout << "Ma tran B\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int** result = matrixProduct(A, B, n);


    cout << "Ma tran C\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 2; i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}