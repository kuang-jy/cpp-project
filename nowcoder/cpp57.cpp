#include <iostream>

using namespace std;

int main()
{
    int n = 3;
    // cin>>n;
    
    int** arr = new int* [n];
    for(int i = 0;i < n;i++){
        arr[i] = new int[n];
        for(int j = 0;j < n;j++){
            *(*(arr+i)+j) = i+j;
        }
    }
    cout << *(*(arr+1)+2) << endl;
    return 0;
}
