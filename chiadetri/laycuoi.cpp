#include<stdio.h>
#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
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
        cout << "\nGia tri phan cach: " << arr[pi] << endl;

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        cout << "\nDoan 1: ";
        for (int i = low; i <= pi-1; i++)
        {
            cout << arr[i] << " ";
        }
        
        cout << "\nDoan 2: ";
        for (int i = pi+1; i <= high; i++)
        {
            cout << arr[i] << " ";
        }
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}