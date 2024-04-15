// lab
#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    cout << "\nPivot: " << pivot;
    int left = low;
    // cout << "| Left = " << left;
    int right = high - 1;
    // cout << "| Right = " << right;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
        {
            left++;
        }
        while (right >= left && arr[right] > pivot)
        {
            right--;
        }
        if (left >= right)
        {
            break;
        }
        cout << "\nleft=" << left << " right = " << right << "; ";
        cout << "Swap(A[" << left << "], A[" << right << "]) ";
        cout << "Swap(A[" << arr[left] << "],A[" << arr[right] << "])" << endl;
        swap(arr[left], arr[right]);
        // cout << "\n|Hoan doi: "<< arr[left] << " vs " << arr[right] << " -> ";
        for (int i = low; i <= high; i++)
        {
            cout << arr[i] << " ";
        }
        left++;
        right--;
    }
    cout << "\nleft=" << left << " right = " << right << "; ";
    cout << "Swap(A[" << left << "], A[" << right << "]";
    cout << "Swap(A[" << arr[left] << "],A[" << arr[right] << "]" << endl;
    swap(arr[left], arr[high]);
    // cout << "\n|Hoan doi: " << arr[left] << " vs " << arr[right] << " -> ";
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    return left;
}

/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
        cout << "\n\nPhan cach: " << arr[pi] << endl;

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        cout << "Doan 1: ";
        for (int i = low; i <= pi - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\nDoan 2: ";
        for (int i = pi + 1; i <= high; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// Hàm in ma trận
void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm cộng hai ma trận
vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Hàm trừ hai ma trận
vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}
// Nhan ma tran su dung thuat toan vetcan
int **matrixProduct(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    int **C = new int *[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Hàm nhân hai ma trận bằng thuật toán Strassen
vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();

    if (n < 4)
    {
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
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

    for (int i = 0; i < halfSize; ++i)
    {
        for (int j = 0; j < halfSize; ++j)
        {
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
    for (int i = 0; i < halfSize; ++i)
    {
        for (int j = 0; j < halfSize; ++j)
        {
            result[i][j] = r[i][j];
            result[i][j + halfSize] = s[i][j];
            result[i + halfSize][j] = t[i][j];
            result[i + halfSize][j + halfSize] = u[i][j];
        }
    }
    cout << "Ma tran thanh phan\n";
    cout << "r:\n";
    printMatrix(r);
    cout << "s:\n";
    printMatrix(s);
    cout << "t:\n";
    printMatrix(t);
    cout << "u:\n";
    printMatrix(u);
    return result;
}
// tichnmatran
// Hàm tính toán và trả về số lượng phép toán nhân tối thiểu cần thiết để nhân dãy ma trận
int minMatrixMultiplications(vector<int> &dims, vector<vector<int>> &bracket, vector<vector<int>> &dp)
{
    int n = dims.size() - 1; // Số lượng ma trận

    // Duyệt qua độ dài của dãy ma trận từ 2 đến n
    for (int len = 2; len <= n; ++len)
    {
        // Duyệt qua từng đoạn con có độ dài len trong dãy ma trận
        for (int i = 1; i <= n - len + 1; ++i)
        {
            cout << "Voi d = " << len - 1 << ", ";
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            cout << "F[" << i << ", " << j << "] = min(";
            // Duyệt qua từng điểm cắt k để tìm phép nhân tối thiểu
            vector<int> tam;
            for (int k = i; k < j; ++k)
            {
                // Tính số phép toán nhân cho phép nhân 2 dãy con
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                tam.push_back(cost);
                cout << "F[" << i << ", " << k << "] + F[" << k + 1 << ", " << j << "] + " << dims[i - 1] << " * " << dims[k] << " * " << dims[j];
                if (k != j - 1)
                {
                    cout << ", " << endl;
                }

                // cout <<"  {k= " << k << "}" << endl;
                // Cập nhật số phép toán nhân tối thiểu
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    bracket[i][j] = k; // Lưu vị trí của phép nhân tối ưu
                }
            }
            cout << ")"
                 << "=min(";
            for (int i = 0; i < tam.size(); i++)
            {
                if (i == tam.size() - 1)
                {
                    cout << tam[i];
                }
                else
                {
                    cout << tam[i] << ",";
                }
            }
            cout << ") =" << dp[i][j] << endl
                 << endl;
        }
    }
    // Trả về số lượng phép toán nhân tối thiểu cần thiết
    return dp[1][n];
}

// Hàm in ra cách nhóm ma trận tối ưu
void printOptimalParenthesis(vector<vector<int>> &bracket, vector<int> &dims, int i, int j)
{
    if (i == j)
    {
        cout << dims[i - 1];
    }
    else
    {
        cout << "(";
        printOptimalParenthesis(bracket, dims, i, bracket[i][j]);
        cout << ", ";
        printOptimalParenthesis(bracket, dims, bracket[i][j] + 1, j);
        cout << ")";
    }
}

// Hàm in ra mảng số lượng phép toán tối thiểu
void printMinimumOperations(vector<vector<int>> &dp)
{
    int n = dp.size() - 1;
    cout << "So luong phep toan nhan toi thieu cho cac doan con:\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i <= j)
            {
                cout << dp[i][j] << "\t";
            }
            else
            {
                cout << "0\t";
            }
        }
        cout << endl;
    }
}
void printBracketMatrix(vector<vector<int>> &bracket, int n)
{
    cout << "Ma tran de nhom toi uu:\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << bracket[i][j] << "\t";
        }
        cout << endl;
    }
}
// end
void cacDayCon(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int i, int j, vector<int> &current_sequence, vector<vector<int>> &all_sequences)
{
    // Nếu chúng ta đã duyệt qua một trong hai mảng
    if (i == 0 || j == 0)
    {
        // Nếu dãy con chung hiện tại không rỗng, chúng ta lưu nó vào mảng chứa tất cả các dãy con chung
        if (!current_sequence.empty())
        {
            all_sequences.push_back(current_sequence);
        }
        return;
    }

    // Nếu phần tử ở vị trí i và j giống nhau, chúng ta lưu phần tử này vào dãy con chung hiện tại
    if (nums1[i - 1] == nums2[j - 1])
    {
        current_sequence.push_back(nums1[i - 1]);
        cacDayCon(nums1, nums2, dp, i - 1, j - 1, current_sequence, all_sequences);
        current_sequence.pop_back(); // Trả lại trạng thái trước đó
    }
    // Nếu không giống nhau, chúng ta xem xét các trường hợp mà ta đã tính toán trước đó
    else
    {
        if (dp[i - 1][j] >= dp[i][j - 1])
        {
            cacDayCon(nums1, nums2, dp, i - 1, j, current_sequence, all_sequences);
        }
        if (dp[i][j - 1] >= dp[i - 1][j])
        {
            cacDayCon(nums1, nums2, dp, i, j - 1, current_sequence, all_sequences);
        }
    }
}
void dayConDaiNhat(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    vector<int> current_sequence;
    vector<vector<int>> all_sequences;

    // Tạo một bảng 2D để lưu trữ kết quả của các dãy con chung
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                // Nếu phần tử ở vị trí i và j giống nhau, tăng độ dài của dãy con chung lên 1
                cout << endl
                     << nums1[i - 1] << "==" << nums2[j - 1] << endl;
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << "Tang " << dp[i - 1][j - 1] << " len 1 don vi = " << dp[i][j] << endl;
            }
            else
            {
                // Nếu không giống nhau, lấy giá trị lớn nhất giữa các trường hợp đã tính được trước đó
                cout << endl
                     << nums1[i - 1] << "!=" << nums2[j - 1] << endl;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                cout << "Lay Max cua " << dp[i - 1][j] << " va " << dp[i][j - 1] << " = " << dp[i][j] << endl;
            }
        }
    }

    // In ra mảng quy hoạch
    cout << "Mang quy hoach:" << endl;
    cout << "  ";
    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i <= m; ++i)
    {
        cout << i << " ";
        for (int j = 0; j <= n; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Do dai day con chung dai nhat: " << dp[m][n] << endl;
    cacDayCon(nums1, nums2, dp, m, n, current_sequence, all_sequences);

    cout << "Cac day con chung dai nhat:" << endl;
    for (const auto &sequence : all_sequences)
    {
        for (int num : sequence)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // Trả về độ dài của dãy con chung dài nhất
}
struct Item
{
    int weight; // Trọng lượng của món đồ
    int value;  // Giá trị của món đồ
};

// Hàm so sánh để sắp xếp các món đồ theo giá trị trên trọng lượng
bool compareItems(Item a, Item b)
{
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

// Hàm thực hiện thuật toán tham lam để xếp ba lô
void knapsackGreedy(vector<Item> items, int capacity)
{
    // Sắp xếp các món đồ theo giá trị trên trọng lượng
    sort(items.begin(), items.end(), compareItems);
    cout << "Ds do vat xep thu tu: ";
    for (int i = 0; i < items.size(); i++)
    {
        cout << "|Do vat " << i + 1 << ": "
             << " W: " << items[i].weight << " V:" << items[i].value << "|";
    }

    int currentWeight = 0;   // Trọng lượng hiện tại của ba lô
    double finalValue = 0.0; // Giá trị cuối cùng của ba lô

    for (int i = 0; i < items.size(); i++)
    {
        // Nếu món đồ này có thể chứa vào ba lô mà không vượt quá trọng lượng tối đa
        cout << "\n\nBa lo: w=" << currentWeight << " v=" << finalValue;
        cout << "\nChon mon do " << i + 1 << "{" << items[i].weight << "," << items[i].value << "}: ";
        if (currentWeight + items[i].weight <= capacity)
        {
            cout << currentWeight << " + " << items[i].weight << "<=" << capacity << " ->Them vao";
            // Thêm món đồ này vào ba lô
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        else
        {
            // Nếu không thì chỉ lấy một phần của món đồ này
            float a = (capacity - currentWeight) / (items[i].weight);
            cout << currentWeight << " + " << items[i].weight << ">" << capacity << " ->Them 1 phan mon do";
            int remainingCapacity = capacity - currentWeight;
            finalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            cout << endl;
            break;
        }
    }

    cout << "Gia tri cuoi cung cua ba lo: " << finalValue << endl;
}
// Cấu trúc để lưu cạnh đồ thị,
// u, v là 2 đỉnh, w là trọng số cạnh
struct edge
{
    int u, v, w;
};
// Hàm so sánh để dùng trong hàm sort ở dưới
bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

// Số đỉnh tối đa trong đề bài
#define N 10005

// 2 mảng sử dụng trong Disjoint Set
int cha[N], hang[N];

// Tìm xem u thuộc cây nào
int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}

// Hợp nhất 2 cây chứ u và v,
// Trả về false nếu không thể hợp nhất
bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (hang[u] == hang[v])
        hang[u]++;
    if (hang[u] < hang[v])
        cha[u] = v;
    else
        cha[v] = u;
    return true;
}
int NN;

int x[100];

void in(int x[])
{
    for (int i = 1; i <= NN; i++)
        cout << x[i];
    cout << endl;
}

void Try(int i)
{
    cout << "Try(" << i << "): ";
    cout << endl;
    for (int j = 0; j <= 1; ++j)
    {
        x[i] = j;
        cout << " j=" << j;
        cout << "  x" << i << "=" << x[i];
        if (i == NN)
        {
            cout << " i=" << i << " = n=" << NN << " nen xuat";
            in(x);
        }
        else
        {
            cout << " i=" << i << " < n=" << NN << " nen goi" << endl;
            Try(i + 1);
        }
    }
    if (i == 1)
    {
        cout << "j = 2 > 1 nen thoat khoi Try(" << i << ") va ket thuc";
    }
    else
    {
        cout << "j = 2 > 1 nen thoat khoi Try(" << i << ") va quay lui" << endl
             << "Try(" << i - 1 << ")";
    }
}
// Hàm in ra các phần tử của một tập con
void printSubset(vector<int> &subset)
{
    cout << "{";
    for (int i = 0; i < subset.size(); ++i)
    {
        cout << subset[i];
        if (i < subset.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

// Hàm sinh ra tất cả các tập con của tập hợp A với kích thước m
void generateSubsets(int max, vector<int> &A, int m, int index, vector<int> &currentSubset)
{

    if (m == 0)
    {
        cout << "tap con: ";
        printSubset(currentSubset);
        return;
    }
    if (index == A.size() && m == max)
    {
        cout << "END.";
    }
    if (index == A.size())
    {
        return;
    }

    // Thêm phần tử A[index] vào tập con hiện tại và tiếp tục đệ quy
    cout << "Duyet " << A[index] << endl;
    currentSubset.push_back(A[index]);

    generateSubsets(max, A, m - 1, index + 1, currentSubset);
    currentSubset.pop_back(); // Quay lui để thử các phần tử khác
    cout << "Quay lui\n";
    generateSubsets(max, A, m, index + 1, currentSubset);
}
int Nhau = 1;
vector<int> xhau;
vector<vector<int>> a;
vector<bool> c1;
vector<bool> c2;
vector<bool> c;

bool check(int i, int j)
{
    if (c[j] == false || c1[i - j + Nhau - 1] == false || c2[i + j - 2] == false)
        return false;
    return true;
}

void xephau(int i)
{

    cout << "Xephau(" << i << ")  ";
    for (int j = 1; j <= Nhau; j++)
    {
        if (check(i, j))
        {
            xhau[i] = j;
            cout << "x[" << i << "] = " << j << "  ";
            c[j] = c1[i - j + Nhau - 1] = c2[i + j - 2] = false;
            if (i == Nhau)
            {
                cout << "Dat duoc giai phap: ";
                a.push_back(xhau);
                for (int k = 1; k <= Nhau; k++)
                    cout << xhau[k] << " ";
                cout << endl;
                xephau(i);
                c[j] = c1[i - j + Nhau - 1] = c2[i + j - 2] = true;
                i--;
            }
            else
            {
                cout << i << "<" << Nhau << "  goi " << endl;
                xephau(i + 1);
                c[j] = c1[i - j + Nhau - 1] = c2[i + j - 2] = true;
            }

            // xephau(i + 1);
            // c[j] = c1[i - j + N - 1] = c2[i + j - 2] = true;
        }
    }
    cout << "K dung luat";
    if (i == 1)
    {
        cout << " Thoat khoi Xephau(" << i << ") va ket thuc";
    }
    else
    {
        cout << "->Thoat khoi Xephau(" << i << ") va quaylui " << endl
             << "Xephau(" << i - 1 << ")  ";
    }
}

int main()
{
    int luachon;
    do
    {
        std::cout << "\n1. Quicksort\n";
        std::cout << "2. Nhan hai ma tran\n";
        std::cout << "3. Tich n ma tran\n";
        std::cout << "4. Day con chung dai nhat\n";
        std::cout << "5. Ba lo\n";
        std::cout << "6. Cay khung cuc tieu\n";
        std::cout << "7. Day nhi phan\n";
        std::cout << "8. Tap con\n";
        std::cout << "9. Xep n con hau\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            int arr[] = {10, 80, 30, 90, 40, 50, 70};
            int n = sizeof(arr) / sizeof(arr[0]);
            std::cout << "Original array: ";
            printArray(arr, n);
            std::cout << std::endl;
            quickSort(arr, 0, n - 1);
            std::cout << "Sorted array: ";
            printArray(arr, n);
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            // Khởi tạo và nhập liệu cho hai ma trận cấp 4
            int n = 4; // Kích thước của ma trận
            vector<vector<int>> A = {
                {1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23}, {25, 27, 29, 31}};

            vector<vector<int>> B = {
                {2, 4, 6, 8}, {10, 12, 14, 16}, {18, 20, 22, 24}, {26, 28, 30, 32}};
            // In ma trận kết quả
            cout << "Ma tran A:" << endl;
            printMatrix(A);

            cout << "Ma tran B:" << endl;
            printMatrix(B);
            cout << "Cach 1: Su dung thuat toan vet can\n";
            int **result1 = matrixProduct(A, B);
            cout << "Ma tran ket qua:\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << result1[i][j] << " ";
                }
                cout << endl;
            }

            // Giải phóng bộ nhớ
            for (int i = 0; i < 2; i++)
            {
                delete[] result1[i];
            }
            delete[] result1;

            // Thực hiện nhân hai ma trận sử dụng thuật toán Strassen
            cout << "Cach 2: Su dung thuat toan strassen\n";
            vector<vector<int>> result = strassenMultiply(A, B);
            cout << "Ma tran ket qua:" << endl;
            printMatrix(result);
            break;
        }
        case 3:
        {
            vector<int> dims = {20, 2, 30, 12, 8}; // Kích thước của các ma trận
            int n = dims.size() - 1;               // Số lượng ma trận
            vector<vector<int>> bracket(n + 1, vector<int>(n + 1, 0));
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

            int minOperations = minMatrixMultiplications(dims, bracket, dp);
            cout << "So luong phep toan nhan toi thieu: " << minOperations << endl;

            printMinimumOperations(dp);
            printBracketMatrix(bracket, n);

            cout << "Cach nhom ma tran toi uu: ";
            printOptimalParenthesis(bracket, dims, 1, n);
            cout << endl;

            break;
        }
        case 4:
        {
            vector<int> nums1 = {3, 5, 3, 5, 3, 1, 5};
            vector<int> nums2 = {5, 5, 3, 3, 1};
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
            break;
        }
        case 5:
        {
            vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // Mỗi phần tử là một món đồ với trọng lượng và giá trị tương ứng
            int capacity = 37;                                     // Trọng lượng tối đa của ba lô
            cout << "W max Ba-lo: " << capacity << endl;
            knapsackGreedy(items, capacity);
            break;
        }
        case 6:
        {
            // Thêm dòng này để cin, cout chạy nhanh
            ios::sync_with_stdio(false);
            cin.tie(0);
            // Nhập danh sách các cạnh
            vector<edge> edges;
            vector<edge> conlai;
            vector<edge> t;

            // Nhập vào số đỉnh và số cạnh
            int n, m;
            cout << "Nhap so dinh va canh: " << endl;
            cin >> n >> m;

            cout << "Nhap thong tin cac canh: \n";
            for (int i = 0; i < m; ++i)
            {
                edge e;
                cout << "Nhap thong tin cho canh " << i + 1 << endl;
                cout << "Dinh dau: " << endl;
                cin >> e.u;
                cout << "Dinh cuoi: " << endl;
                cin >> e.v;
                cout << "Trong so: " << endl;
                cin >> e.w;
                cout << endl;
                edges.push_back(e);
            }

            // Sắp xếp lại các cạnh theo trọng số tăng dần
            sort(edges.begin(), edges.end(), cmp);
            conlai = edges;
            cout << "Danh sach canh sap xep theo trong so: " << endl;
            cout << "{";
            for (const edge &e : edges)
            {
                cout << "{" << e.u << "," << e.v << "," << e.w << "}"
                     << ",";
            }
            cout << "}" << endl;

            // Khởi tạo cấu trúc Disjoint Set
            for (int i = 1; i <= n; i++)
            {
                cha[i] = i;
                hang[i] = 0;
            }

            // Lưu tổng trọng số các cạnh trong cây khung nhỏ nhất
            int mst_weight = 0;

            // Duyệt qua các cạnh theo thứ tự đã sắp xếp
            for (edge &e : edges)
            {
                // Thử hợp nhất 2 cây chứa u và v
                if (join(e.u, e.v))
                {
                    // Hợp nhất thành công, ta thêm e và kết quả
                    cout << endl
                         << "Thoa man " << endl;
                    cout << "{" << e.u << "," << e.v << "}";
                    mst_weight += e.w;
                    t.push_back(e);
                    // Bổ sung phần ứng viên còn lại
                    // cout << endl << "Tap ung vien con lai :"<< endl;
                    // cout << "{";
                    // for (const edge &v : edges)
                    // {
                    //     cout << "{" << e.u << "," << e.v << "," << e.w << "}"
                    //          << ",";
                    // }
                    // cout << "}";
                    // cout << endl;

                    cout << endl
                         << "Cay khung hien tai: " << endl;
                    cout << "{";
                    for (const edge &e : t)
                    {
                        cout << "{" << e.u << "," << e.v << "," << e.w << "}"
                             << ",";
                    }
                    cout << "}";
                }
                else
                {
                    cout << endl
                         << "Tao thanh chu trinh" << endl;
                    cout << "{" << e.u << "," << e.v << "}";
                }
            }

            // Xuất kết quả
            cout << endl
                 << "Cay khung cuc tieu: " << endl;
            cout << "{";
            for (const edge &e : t)
            {
                cout << "{" << e.u << "," << e.v << "," << e.w << "}"
                     << ",";
            }
            cout << "}";
            cout << endl
                 << "Trong so: ";
            cout << mst_weight;
            break;
        }
        case 7:
        {
            cin >> NN;
            Try(1);
            break;
        }
        case 8:
        {
            vector<int> A = {1, 2, 3, 4}; // Tập hợp A
            int max = 2, m = 2;           // Kích thước của các tập cons
            cout << "Tap hop A: { ";
            for (int i = 0; i < A.size(); i++)
            {
                if (i == A.size() - 1)
                {
                    cout << A[i];
                }
                else
                {
                    cout << A[i] << ",";
                }
            }
            cout << "}\n";

            vector<int> currentSubset;

            generateSubsets(max, A, m, 0, currentSubset);
            // cout << "END.";
            break;
        }
        case 9:
        {
            cout << "N = ";
            cin >> Nhau;
            xhau.resize(Nhau + 1);
            c.resize(Nhau + 1, true);
            c1.resize(2 * Nhau - 1, true);
            c2.resize(2 * Nhau - 1, true);
            xephau(1);
            cout << "\nTong so giai phap: " << a.size() << endl
                 << endl;
            for (int k = 0; k < a.size(); k++)
            {
                for (int i = 1; i <= Nhau; i++)
                {
                    for (int j = 1; j <= Nhau; j++)
                    {
                        cout << (j == a[k][i]) << " ";
                        if (j % Nhau == 0)
                            cout << endl;
                    }
                }
                cout << endl;
            }
            break;
        }
        case 0:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (luachon != 0);

    return 0;
}
