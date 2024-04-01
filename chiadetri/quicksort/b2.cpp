#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Hàm nhập mảng từ bàn phím
void inputArray(int arr[], int& size) {
    std::cout << "Nhap kich thuoc cua mang: ";
    std::cin >> size;

    if (size > 0 && size <= MAX_SIZE) {
        std::cout << "Nhap cac phan tu cua mang:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "arr[" << i << "]: ";
            std::cin >> arr[i];
        }
    } else {
        std::cout << "Kich thuoc khong hop le.\n";
        size = 0;
    }
}

// Hàm in mảng ra màn hình
void printArray(const int arr[], int size) {
    std::cout << "Mang da nhap: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
// Hàm hoán đổi giá trị của hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng và trả về vị trí của pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Chọn phần tử cuối cùng làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; ++j) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            ++i;
            // Hoán đổi arr[i] và arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Hoán đổi arr[i + 1] và pivot
    cout << "Hoan doi " << arr[i+1] << " vs " << arr[high] << endl;
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm sắp xếp quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm vị trí pivot sao cho các phần tử trên pivot là lớn hơn,
        // và các phần tử dưới pivot là nhỏ hơn
        int pivotIndex = partition(arr, low, high);
        cout << "p = " << pivotIndex << "\n";

        // Đệ quy sắp xếp nửa trước và nửa sau của mảng
        cout << "Doan 1: ";
        for (int k = low; k <  pivotIndex - 1; k++)
        {
            cout << arr[k] << " ";
        }
         cout << "\nDoan 2: ";
        for (int k = pivotIndex + 1; k < high; k++)
        {
            cout << arr[k] << " ";
        }
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int myArray[MAX_SIZE];
    int n;

    // Gọi hàm nhập mảng
    inputArray(myArray, n);
    quicksort(myArray,0,n-1);

    // Gọi hàm in mảng
    printArray(myArray, n);

    return 0;
}
