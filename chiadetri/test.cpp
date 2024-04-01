#include <iostream>
#include <vector>

using namespace std;
// Hàm in ma trận
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm cộng hai ma trận
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Hàm trừ hai ma trận
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Hàm nhân hai ma trận bằng thuật toán Strassen
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n < 4) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    int halfSize = n / 2;
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));

    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }
    

    vector<vector<int>> m1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> m2 = strassenMultiply(addMatrix(A21, A22), B11);
    vector<vector<int>> m3 = strassenMultiply(A11, subtractMatrix(B12, B22));
    vector<vector<int>> m4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    vector<vector<int>> m5 = strassenMultiply(addMatrix(A11, A12), B22);
    vector<vector<int>> m6 = strassenMultiply(subtractMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> m7 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));

    vector<vector<int>> r = subtractMatrix(addMatrix(m1, m4), subtractMatrix(m5, m7));
    vector<vector<int>> s = addMatrix(m3, m5);
    vector<vector<int>> t = addMatrix(m2, m4);
    vector<vector<int>> u = subtractMatrix(addMatrix(m1, m3), subtractMatrix(m2, m6));

    // Kết hợp các phần kết quả thành ma trận tổng
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            result[i][j] = r[i][j];
            result[i][j + halfSize] = s[i][j];
            result[i + halfSize][j] = t[i][j];
            result[i + halfSize][j + halfSize] = u[i][j];
        }
    }
    cout << "Ma tran thanh phan\n";
    printMatrix(r);
    printMatrix(s);
    printMatrix(t);
    printMatrix(u);
    return result;
}



int main() {
    // Khởi tạo và nhập liệu cho hai ma trận cấp 4
    int n = 4; // Kích thước của ma trận
    vector<vector<int>> A = {
        {1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23} ,{25, 27, 29, 31}
    };

    vector<vector<int>> B = {
        {2, 4, 6, 8}, {10, 12, 14, 16}, {18,20,22,24}, {26,28,30,32}
    };

    // Thực hiện nhân hai ma trận sử dụng thuật toán Strassen
    vector<vector<int>> result = strassenMultiply(A, B);

    // In ma trận kết quả
    cout << "Ma tran A:" << endl;
    printMatrix(A);

    cout << "Ma tran B:" << endl;
    printMatrix(B);

    cout << "Ma tran ket qua:" << endl;
    printMatrix(result);

    return 0;
}
