#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void cacDayCon(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int i, int j, vector<int>& current_sequence, vector<vector<int>>& all_sequences) {
    // Nếu chúng ta đã duyệt qua một trong hai mảng
    if (i == 0 || j == 0) {
        // Nếu dãy con chung hiện tại không rỗng, chúng ta lưu nó vào mảng chứa tất cả các dãy con chung
        if (!current_sequence.empty()) {
            all_sequences.push_back(current_sequence);
        }
        return;
    }

    // Nếu phần tử ở vị trí i và j giống nhau, chúng ta lưu phần tử này vào dãy con chung hiện tại
    if (nums1[i - 1] == nums2[j - 1]) {
        current_sequence.push_back(nums1[i - 1]);
        cacDayCon(nums1, nums2, dp, i - 1, j - 1, current_sequence, all_sequences);
        current_sequence.pop_back(); // Trả lại trạng thái trước đó
    } 
    // Nếu không giống nhau, chúng ta xem xét các trường hợp mà ta đã tính toán trước đó
    else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            cacDayCon(nums1, nums2, dp, i - 1, j, current_sequence, all_sequences);
        }
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            cacDayCon(nums1, nums2, dp, i, j - 1, current_sequence, all_sequences);
        }
    }
}
void dayConDaiNhat(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<int> current_sequence;
    vector<vector<int>> all_sequences;
    
    // Tạo một bảng 2D để lưu trữ kết quả của các dãy con chung
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                // Nếu phần tử ở vị trí i và j giống nhau, tăng độ dài của dãy con chung lên 1
                cout << endl << nums1[i-1] << "==" << nums2[j-1] << endl;
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << "Tang " << dp[i-1][j-1] << " len 1 don vi = " << dp[i][j] <<endl;
            } else {
                // Nếu không giống nhau, lấy giá trị lớn nhất giữa các trường hợp đã tính được trước đó
                cout << endl << nums1[i-1] << "!=" << nums2[j-1] << endl;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                 cout << "Lay Max cua " << dp[i - 1][j] << " va " << dp[i][j - 1] << " = "<< dp[i][j] <<endl;

            }
        }
    }
    
    // In ra mảng quy hoạch
    cout << "Mang quy hoach:" << endl;
    cout << "  ";
    for (int i= 0; i<=n ;i++){
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i <= m; ++i) {
         cout << i << " ";
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Do dai day con chung dai nhat: " << dp[m][n] << endl;
    cacDayCon(nums1, nums2, dp, m, n, current_sequence, all_sequences);

    cout << "Cac day con chung dai nhat:" << endl;
    for (const auto& sequence : all_sequences) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Trả về độ dài của dãy con chung dài nhất
   
}


int main() {
    vector<int> nums1 = {3,5,3,5,3,1,5};
    vector<int> nums2 = {5,5,3,3,1};
    cout << "Mang 1: ";
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    cout << "Mang 2: ";
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;
    
    
    dayConDaiNhat(nums1, nums2);
    
    // cout << "Do dai day con chung dai nhat: " << dayConDaiNhat(nums1, nums2) << endl;
    
    return 0;
}
