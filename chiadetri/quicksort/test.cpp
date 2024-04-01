#include <iostream>
using namespace std;

// Hàm hoán đổi giá trị của hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp quicksort
void quicksort(int arr[], int l, int r) {
    int i = l;
    int j = r;
    int x = arr[(l + r) / 2]; // Chọn phần tử ở giữa làm pivot
    cout << "p=" << x << endl;

    do {
        while (arr[i] < x) {
            i = i + 1;
        }

        while (arr[j] > x) {
            j = j - 1;
        }

        if (i <= j) {
            // Hoán đổi arr[i] và arr[j]
            swap(arr[i], arr[j]);
            i = i + 1;
            j = j - 1;
            cout << "Doan 1: ";
        for (int k = 0; k < j-1; k++)
        {
            cout << arr[k];
        }
        cout << endl;
         cout << "Doan 2: ";
        for (int k = j-1; k <=r; k++)
        {
            cout << arr[k];
        }
        cout << endl;

        }
    } while (i <= j);

    // Gọi đệ quy sắp xếp cho nửa trước và nửa sau của mảng
    if (l < j) {
        
        quicksort(arr, l, j);
    }
    if (i < r) {
        quicksort(arr, i, r);
    }
}

int main() {
    int myArray[] = {3, 5, 4, 1, 6, 2, 7};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    std::cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; ++i) {
        std::cout << myArray[i] << " ";
    }
    cout << endl;

    // Gọi hàm sắp xếp quicksort
    quicksort(myArray, 0, n - 1);

    std::cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < n; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
