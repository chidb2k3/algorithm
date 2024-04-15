#include <iostream>

using namespace std;

int N;

int x[100];

void in(int x[])
{
    for (int i = 1; i <= N; i++)
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
        if (i == N)
        {
            cout << " i=" << i << " = n=" << N << " nen xuat";
            in(x);
        }
        else
        {
            cout << " i=" << i << " < n=" << N << " nen goi" << endl;
            Try(i+1);
        }
    }
    if(i==1){
        cout << "j = 2 > 1 nen thoat khoi Try(" << i << ") va ket thuc";
    }else{
    cout << "j = 2 > 1 nen thoat khoi Try(" << i << ") va quay lui" << endl << "Try(" << i - 1 << ")";
    }
}

int main()
{
    cin >> N;
    Try(1);
    return 0;
}
