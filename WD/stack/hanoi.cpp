#include <iostream>
using namespace std;

void hanoi(int i,char a,char b,char c){   //从a移到c，以b为辅助栈
    if(i == 1){
        printf("%c->%c\n",a,c);
        return;
    }
    hanoi(i-1,a,c,b);   //将前n-1个移到b，以c为辅助栈
    printf("%c->%c\n",a,c);
    hanoi(i-1,b,a,c);   
}

int main(){
    hanoi(3,'a','b','c');
    return 0;
}