//lab
#include <bits/stdc++.h>
using namespace std;

int N = 1;
vector<int> x;
vector<vector<int>> a;
vector<bool> c1;
vector<bool> c2;
vector<bool> c;

bool check(int i, int j)
{
    if (c[j] == false || c1[i - j + N - 1] == false || c2[i + j - 2] == false)
        return false;
    return true;
}

void xephau(int i)
{

    cout << "Xephau(" << i << ")  ";
    for (int j = 1; j <= N; j++){
        if (check(i, j))
        {
            x[i] = j;
            cout << "x[" << i << "] = " << j << "  ";
            c[j] = c1[i - j + N - 1] = c2[i + j - 2] = false;
            if (i == N)
            {
                cout << "Dat duoc giai phap: ";
                a.push_back(x);
                for (int k = 1; k <= N; k++)
                    cout << x[k] << " ";
                cout << endl;
                xephau(i);
                c[j] = c1[i - j + N - 1] = c2[i + j - 2] = true;
                i--;
                
            }
            else
            {
                cout << i << "<" << N << "  goi " << endl;
                xephau(i + 1);
                c[j] = c1[i - j + N - 1] = c2[i + j - 2] = true;
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
    cout << "N = ";
    cin >> N;
    x.resize(N + 1);
    c.resize(N + 1, true);
    c1.resize(2 * N - 1, true);
    c2.resize(2 * N - 1, true);
    xephau(1);
    cout << "\nTong so giai phap: " << a.size() << endl
         << endl;
    for (int k = 0; k < a.size(); k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cout << (j == a[k][i]) << " ";
                if (j % N == 0)
                    cout << endl;
            }
        }
        cout << endl;
    }
}
