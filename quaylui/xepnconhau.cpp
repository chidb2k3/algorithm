#include <iostream>
#include <vector>

using namespace std;

// Kiểm tra xem việc đặt hậu vào vị trí (row, col) có hợp lệ không
bool isValid(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        // Kiểm tra xem hậu đã được đặt trên cùng cột hoặc đường chéo chưa
        if (board[i] == col || abs(i - row) == abs(board[i] - col))
            return false;
    }
    return true;
}

// Hàm quay lui để xếp n con hậu vào bàn cờ
void solveNQueens(int n, vector<int>& board, int row, vector<vector<string>>& solutions) {
    // Nếu đã đặt được hậu vào hàng cuối cùng
    if (row == n) {
        // Tạo một bàn cờ mới dựa trên vị trí các hậu
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            solution[i][board[i]] = 'Q';
        }
        // Thêm bàn cờ này vào danh sách các giải pháp
        solutions.push_back(solution);
        return;
    }

    // Duyệt qua các cột để đặt hậu vào hàng hiện tại
    for (int col = 0; col < n; ++col) {
        if (isValid(board, row, col)) {
            // Đặt hậu vào vị trí (row, col)
            cout << "Dat hau vao [" << row << "][" << col << "]";
            board[row] = col;
            // Xử lý hàng tiếp theo
            solveNQueens(n, board, row + 1, solutions);
            // Quay lui và thử vị trí đặt hậu khác
            board[row] = -1;
        }
    }
}

// Hàm giải bài toán xếp n con hậu trên bàn cờ kích thước n x n
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1); // Mảng lưu vị trí của các hậu

    // Gọi hàm quay lui để tìm các giải pháp
    solveNQueens(n, board, 0, solutions);

    return solutions;
}

int main() {
    int n;
    cout << "Nhap kich thuoc cua ban co (n x n): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Cac giai phap cua bai toan xep " << n << " con hau:\n";
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Giai phap #" << i + 1 << ":\n";
        for (int j = 0; j < n; ++j) {
            cout << solutions[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
