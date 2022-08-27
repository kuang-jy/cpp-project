//
// Created by eason on 2022/4/17.
//
#include "iostream"

using namespace std;

int main(){
    int arr[5];
    for (int &i:arr) {
        cin >> i;
    }
    int sum = 0;
    for (int i = 0;i < 5;i++) {
        int num = arr[i];
        sum += num % 3;
        num /= 3;
        arr[i] = num;
        if (i == 0){
            arr[4] += num;
            arr[i+1] += num;
        }
        else if (i == 4){
            arr[0] += num;
            arr[i-1] += num;
        } else{
            arr[i+1] += num;
            arr[i-1] += num;
        }
    }
    for (int i = 0;i < 5;i++) {
        printf("%d ",arr[i]);
        if (i == 4)
            cout << endl;
    }
    printf("%d",sum);

    return 0;
}