#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

int lap(int x, int n)
{
    int kq = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            kq *= x;
        }
        return kq;
    }
}
int dequy(int x, int n){
    if (n==0)
    {
        return 1;
    }else{
        return x*dequy(x,n-1);
    }
    
}
int main(){
     int n;
    do
    {
       
    cout << "nhap n = ";
    cin >> n;
    cout << "x = 2, n = "<<n;
    
    auto start_time = std::chrono::high_resolution_clock::now();

    
    cout << "\nket qua cho lap: " << lap(2,n) << endl;

    
    auto end_time = std::chrono::high_resolution_clock::now();

   
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

   
    
    std::cout << "thoi gian cho lap: " << duration.count() << " microseconds" << std::endl;
 
   
    
    auto start = std::chrono::high_resolution_clock::now();

    
    cout << "\nket qua cho dequy: " << dequy(2,n) << endl;

    
    auto end = std::chrono::high_resolution_clock::now();

    
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

   
    std::cout << "thoi gian cho dequy: " << duration2.count() << " microseconds" << std::endl;
    } while (n=-1);
    
    
 
    system("pause");
    return 0;
    
   

}