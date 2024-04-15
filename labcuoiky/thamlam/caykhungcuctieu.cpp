#include <iostream>
#include <vector>
#include <algorithm> // Hàm sort
using namespace std;

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

int main()
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
            cout << endl <<"Thoa man " << endl;
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
            


            cout <<endl << "Cay khung hien tai: " << endl;
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
            cout <<endl<< "Tao thanh chu trinh" << endl;
            cout << "{" << e.u << "," << e.v << "}";
        }
    }

    // Xuất kết quả
    cout << endl << "Cay khung cuc tieu: "<< endl;
    cout << "{";
    for (const edge &e : t)
    {
        cout << "{" << e.u << "," << e.v << "," << e.w << "}"
             << ",";
    }
    cout << "}";
    cout << endl << "Trong so: ";
    cout << mst_weight;
    return 0;
}