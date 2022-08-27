#include <iostream>
using namespace std;

int main() {

    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);
    
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    
    for(int i = len-1;i > 0;i--){
        for(int j = i-1;j >= 0;j--){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    for(int i = 0;i <len;i++){
        if(i == len-1){
            cout << arr[i] << endl;
            break;
        }
        cout << arr[i] << " ";
    }
    
    return 0;
}