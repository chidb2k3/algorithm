// lab
#include <iostream>
#include <stdio.h>
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

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Day so ban dau: ";
    printArray(arr, n);
    cout << "\nChi so:         ";
    for (int  i = 0; i < n; i++)
    {
        cout << i << "  ";
    }
    
    cout << endl;
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}