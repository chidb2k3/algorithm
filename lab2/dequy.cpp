#include <iostream>
#include <time.h>
#include <chrono>
using  namespace std;
int dequy(int x, int n){
    if (n==0)
    {
        return 1;
    }else{
        return x*dequy(x,n-1);
    }
    
}

int main(){
     cout << "gioi han  n " << dequy(2,30);
     // Lấy thời điểm bắt đầu
    auto start_time = std::chrono::high_resolution_clock::now();

    // Gọi hàm cần đo thời gian thực thi
    cout << "\nket qua cho dequy: " << dequy(2,50) << endl;

    // Lấy thời điểm kết thúc
    auto end_time = std::chrono::high_resolution_clock::now();

    // Tính toán thời gian thực thi
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // In ra thời gian thực thi
    std::cout << "thoi gian cho dequy: " << duration.count() << " microseconds" << std::endl;
    system("pause");
    return 0;
    
   

}