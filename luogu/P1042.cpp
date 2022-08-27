//
// Created by Kjoye on 2022/4/21.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr[60000];
    char c;
    cin >> c;
    arr[0] = c;
    int counta_11=0,countb_11=0,counta_21=0,countb_21=0;
    int i = 0;
    while (c != 'E'){
        arr[i++] = c;
        if(c == 'W') counta_11++;
        else countb_11++;
        if((counta_11 >= 11 || countb_11 >= 11) && abs(counta_11-countb_11) >= 2){
            cout << counta_11 << ":" << countb_11 << endl;
            counta_11 = 0;
            countb_11 = 0;
        }
        cin >> c;
    }
    cout << counta_11 << ":" << countb_11 << endl ;
    cout << endl;

    for (int j = 0;j < i;j++) {
        if(arr[j] == 'W') counta_21++;
        if(arr[j] == 'L') countb_21++;
        if((counta_21 >= 21 || countb_21 >= 21) && abs(counta_21-countb_21) >= 2){
            cout << counta_21 << ":" << countb_21 << endl;
            counta_21 = 0;
            countb_21 = 0;
        }
    }
    cout << counta_21 << ":" << countb_21 << endl;

    return 0;
}
