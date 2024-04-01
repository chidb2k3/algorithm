#include <iostream>

using namespace std;

// Function to add two matrices
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Function to multiply two matrices
void multiplyMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}

// Function to divide a matrix into 4 submatrices
void divideMatrix(int** A, int** A11, int** A12, int** A21, int** A22, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n];
            A21[i][j] = A[i + n][j];
            A22[i][j] = A[i + n][j + n];
        }
}

// Function to combine 4 submatrices into a matrix
void combineMatrix(int** C, int** C11, int** C12, int** C21, int** C22, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
}

// Strassen Algorithm
void strassen(int** A, int** B, int** C, int n) {
    if (n <= 32) {
        // Use a simple matrix multiplication algorithm for small matrices
        multiplyMatrix(A, B, C, n);
        return;
    }

    int newSize = n / 2;

    // Create submatrices
    int** A11 = new int*[newSize];
    int** A12 = new int*[newSize];
    int** A21 = new int*[newSize];
    int** A22 = new int*[newSize];
    int** B11 = new int*[newSize];
    int** B12 = new int*[newSize];
    int** B21 = new int*[newSize];
    int** B22 = new int*[newSize];
    int** C11 = new int*[newSize];
    int** C12 = new int*[newSize];
    int** C21 = new int*[newSize];
    int** C22 = new int*[newSize];

    for (int i = 0; i < newSize; i++) {
        A11[i] = new int[newSize];
        A12[i] = new int[newSize];
        A21[i] = new int[newSize];
        A22[i] = new int[newSize];
        B11[i] = new int[newSize];
        B12[i] = new int[newSize];
        B21[i] = new int[newSize];
        B22[i] = new int[newSize];
        C11[i] = new int[newSize];
        C12[i] = new int[newSize];
        C21[i] = new int[newSize];
        C22[i] = new int[newSize];
    }

    // Divide matrices into submatrices
    divideMatrix(A, A11, A12, A21, A22, newSize);
    divideMatrix(B, B11, B12, B21, B22, newSize);

    // Recursive calls
    int** P1 = new int*[newSize];
    int** P2 = new int*[newSize];
    int** P3 = new int*[newSize];
    int** P4 = new int*[newSize];
    int** P5 = new int*[newSize];
    int** P6 = new int*[newSize];
    int** P7 = new int*[newSize];

    for (int i = 0; i < newSize; i++) {
        P1[i] = new int[newSize];
        P2[i] = new int[newSize];
        P3[i] = new int[newSize];
        P4[i] = new int[newSize];
        P5[i] = new int[newSize];
        P6[i] = new int[newSize];
        P7[i] = new int[newSize];
    }

    subtractMatrix(B12, B22, P1, newSize);
    addMatrix(A11, A12, P2, newSize);
    addMatrix(A21, A22, P3, newSize);
    subtractMatrix(B21, B11, P4, newSize);
    addMatrix(A11, A22, P5, newSize);
    addMatrix(B11, B22, P6, newSize);
    subtractMatrix(A12, A22, P7, newSize);

    // Recursive steps
    strassen(A11, P1, C11, newSize);
    strassen(P2, B22, C12, newSize);
    strassen(P3, B11, C21, newSize);
    strassen(A22, P4, C22, newSize);
    strassen(P5, P6, C11, newSize);
    strassen(P7, A21, C12, newSize);

    // Combine submatrices into the result matrix
    combineMatrix(C, C11, C12, C21, C22, newSize);

    // Free memory
    for (int i = 0; i < newSize; i++) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
}


int main() {
    // Matrix size (a power of 2)
    int n = 4;

    // Initialize matrices A and B
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Fill matrices A and B with values
    int count = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = count++;
            B[i][j] = count++;
        }
    // Print the result matrix
    
    // Print the result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }
    // Perform matrix multiplication
    strassen(A, B, C, n);

    // Print the result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
