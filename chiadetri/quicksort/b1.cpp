#include <iostream>

// Hàm hoán đổi giá trị của hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm chia mảng và trả về vị trí của pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
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
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm sắp xếp quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm vị trí pivot sao cho các phần tử trên pivot là lớn hơn,
        // và các phần tử dưới pivot là nhỏ hơn
        int pivotIndex = partition(arr, low, high);

        // Đệ quy sắp xếp nửa trước và nửa sau của mảng
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    // Gọi hàm sắp xếp quicksort
    quicksort(arr, 0, n - 1);

    std::cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
