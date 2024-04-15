#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

// Hàm tính toán và trả về số lượng phép toán nhân tối thiểu cần thiết để nhân dãy ma trận
int minMatrixMultiplications(vector<int>& dims, vector<vector<int>>& bracket, vector<vector<int>>& dp) {
    int n = dims.size() - 1; // Số lượng ma trận
    

    // Duyệt qua độ dài của dãy ma trận từ 2 đến n
    for (int len = 2; len <= n; ++len) {
        // Duyệt qua từng đoạn con có độ dài len trong dãy ma trận
        for (int i = 1; i <= n - len + 1; ++i) {
            cout << "Voi d = " << len - 1 << ", ";
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            cout << "F[" << i << ", " << j << "] = min(";
            // Duyệt qua từng điểm cắt k để tìm phép nhân tối thiểu
            vector<int> tam;
            for (int k = i; k < j; ++k) {
                // Tính số phép toán nhân cho phép nhân 2 dãy con
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                tam.push_back(cost);
                cout << "F[" << i << ", " << k << "] + F[" << k + 1 << ", " << j << "] + " << dims[i - 1] << " * " << dims[k] << " * " << dims[j];
                if (k != j - 1) {
                    cout << ", " << endl;
                }

                // cout <<"  {k= " << k << "}" << endl;
                // Cập nhật số phép toán nhân tối thiểu
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k; // Lưu vị trí của phép nhân tối ưu
                }
            }
            cout << ")"  << "=min(";
            for (int i = 0; i < tam.size(); i++)
            {
                if(i==tam.size()-1){
                    cout << tam[i];
                }else{
                cout << tam[i] <<",";

                }
            }
            cout << ") =" << dp[i][j] << endl << endl;
            
        }
    }
    // Trả về số lượng phép toán nhân tối thiểu cần thiết
    return dp[1][n];
}

// Hàm in ra cách nhóm ma trận tối ưu
void printOptimalParenthesis(vector<vector<int>>& bracket, vector<int>& dims, int i, int j) {
    if (i == j) {
        cout << dims[i - 1];
    } else {
        cout << "(";
        printOptimalParenthesis(bracket, dims, i, bracket[i][j]);
        cout << ", ";
        printOptimalParenthesis(bracket, dims, bracket[i][j] + 1, j);
        cout << ")";
    }
}

// Hàm in ra mảng số lượng phép toán tối thiểu
void printMinimumOperations(vector<vector<int>>& dp) {
    int n = dp.size() - 1;
    cout << "So luong phep toan nhan toi thieu cho cac doan con:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i <= j) {
                cout << dp[i][j] << "\t";
            } else {
                cout << "0\t";
            }
        }
        cout << endl;
    }
}
void printBracketMatrix(vector<vector<int>>& bracket, int n) {
    cout << "Ma tran bracket:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << bracket[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {
    vector<int> dims = {20, 2, 30, 12, 8}; // Kích thước của các ma trận
    int n = dims.size() - 1; // Số lượng ma trận
    vector<vector<int>> bracket(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int minOperations = minMatrixMultiplications(dims, bracket, dp);
    cout << "So luong phep toan nhan toi thieu: " << minOperations << endl;

    printMinimumOperations(dp);
    printBracketMatrix(bracket, n);

    cout << "Cach nhom ma tran toi uu: ";
    printOptimalParenthesis(bracket, dims, 1, n);
    cout << endl;



    return 0;
}
