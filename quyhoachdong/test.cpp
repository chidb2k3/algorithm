#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Hàm tính số lượng phép nhân ít nhất cần thiết
int minMatrixMultiplications(const vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Số lượng ma trận
    vector<vector<int>> dp(n, vector<int>(n, 0)); // Mảng lưu số lượng phép nhân ít nhất

    // Tính toán số lượng phép nhân ít nhất cần thiết
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n - 1];
}

// Hàm xây dựng biểu thức kết hợp tối ưu
string optimalParenthesization(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0)); // Mảng lưu số lượng phép nhân ít nhất
    vector<vector<int>> split(n, vector<int>(n, 0)); // Mảng lưu chỉ số k tối ưu

    // Tính toán số lượng phép nhân ít nhất cần thiết và chỉ số k tối ưu
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    // Xây dựng biểu thức kết hợp tối ưu
    string expression = buildExpression(split, 0, n - 1);
    return expression;
}

// Hàm đệ quy để xây dựng biểu thức kết hợp tối ưu
string buildExpression(const vector<vector<int>>& split, int i, int j) {
    if (i == j)
        return "M" + to_string(i + 1);
    else
        return "(" + buildExpression(split, i, split[i][j]) + buildExpression(split, split[i][j] + 1, j) + ")";
}

int main() {
    vector<int> dimensions = {10, 20, 50, 1, 100}; // Kích thước các ma trận

    // Tính số lượng phép nhân ít nhất cần thiết
    int minMultiplications = minMatrixMultiplications(dimensions);
    cout << "Số lượng phép nhân ít nhất: " << minMultiplications << endl;

    // Xây dựng biểu thức kết hợp tối ưu
    string expression = optimalParenthesization(dimensions);
    cout << "Biểu thức kết hợp tối ưu: " << expression << endl;

    return 0;
}
