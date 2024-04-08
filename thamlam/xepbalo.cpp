#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc cho mỗi món đồ
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
    cout << "Danh sach do vat dc xep thu tu: " << endl;
    for (int i = 0; i < items.size(); i++)
    {
        cout << "Do vat " << i + 1 << ": "
             << " W: " << items[i].weight << " V:" << items[i].value << endl;
    }

    int currentWeight = 0;   // Trọng lượng hiện tại của ba lô
    double finalValue = 0.0; // Giá trị cuối cùng của ba lô

    for (int i = 0; i < items.size(); i++)
    {
        // Nếu món đồ này có thể chứa vào ba lô mà không vượt quá trọng lượng tối đa
        cout << "Trong luong hien tai cua ba lo: " << currentWeight << endl;
        cout << "Gia tri balo hien tai: " << finalValue << endl;
        cout << "Xet mon do "<< i+1 << "{" << items[i].weight << "," << items[i].value<< "}"<< endl;
        if (currentWeight + items[i].weight <= capacity)
        {
            cout << currentWeight << " + " << items[i].weight << "<=" << capacity << endl;
            cout << "Mon do thoa man. Them vao balo" << endl;
            // Thêm món đồ này vào ba lô
            currentWeight += items[i].weight;
            finalValue += items[i].value;
            cout << "Mon do co trong luong " << items[i].weight << " va gia tri " << items[i].value <<" dc them vao "<< endl;
        //     cout << "Trong luong hien tai cua ba lo: " << currentWeight << endl;
        //     cout << "Gia tri balo hien tai: " << finalValue << endl;
        cout << endl;
        }
        else
        {
            // Nếu không thì chỉ lấy một phần của món đồ này
            cout << currentWeight << " + " << items[i].weight << ">" << capacity << endl;
            cout << "Chon mot phan mon do"<< endl;
            int remainingCapacity = capacity - currentWeight;
            finalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            cout << "Mot phan cua mon do co trong luong " << items[i].weight << " va gia tri " << items[i].value << " dc them vao"<< endl;
            cout << endl;
            break;
        }
    }

    cout << "Gia tri cuoi cung cua ba lo: " << finalValue << endl;
}

int main()
{
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // Mỗi phần tử là một món đồ với trọng lượng và giá trị tương ứng
    int capacity = 37;                                         // Trọng lượng tối đa của ba lô
    cout << "Trong luong toi da cua ba lo: " << capacity << endl;
    knapsackGreedy(items, capacity);

    return 0;
}
