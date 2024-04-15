//lab
#include <iostream>
#include <vector>
using namespace std;

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
    if (index == A.size() && m==max)
    {
        cout << "END.";
        
    }
    if (index == A.size())
    {
        return;
        
    }
    
    // Thêm phần tử A[index] vào tập con hiện tại và tiếp tục đệ quy
    cout << "Duyet " << A[index]<< endl;
    currentSubset.push_back(A[index]);
    
    generateSubsets(max, A, m - 1, index + 1, currentSubset);
    currentSubset.pop_back(); // Quay lui để thử các phần tử khác
    cout << "Quay lui\n";
    generateSubsets(max,A, m, index + 1, currentSubset);
 
    
}

int main()
{
    vector<int> A = {1, 2, 3,4}; // Tập hợp A
    int max=2, m = 2;                 // Kích thước của các tập cons
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

    return 0;
}
