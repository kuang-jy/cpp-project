//
// Created by eason on 2022/4/17.
//
#include "iostream"

using namespace std;

int main(){
    char a;
    cin >> a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 3-i-1; j > 0; --j) {
            printf("%s"," ");
        }
        for (int j = i+1; j > 0 ; --j) {
            printf("%c",a);
        }
        for (int j = i; j > 0 ; --j) {
            printf("%c",a);
        }
        printf("\n");
    }
    return 0;
}