#include <iostream>
using namespace std;
const int MAX = 50;

int timMax(int arr[MAX]){
   int max = arr[0];
    for (int i = 1; i < 8; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        
    }
    return max;
    
}
int main(){
    int arr[MAX] = {1,2,3,4,6,2,5,76};
    cout << timMax(arr);


}