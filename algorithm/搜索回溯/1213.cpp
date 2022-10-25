#include <iostream>
using namespace std;
int pos[9],cur = 1;

bool check(int r,int c){
    for(int i = r-1;i >= 1;i--){
        if(pos[i] == c) return false;
        if(pos[i] + i == r+c) return false;
        if(pos[i] - i == c-r) return false;
    }
    return true;
}

void queen(int r){
    if(r == 9){
        printf("No. %d\n",cur);
        cur++;
        for(int i = 1;i <= 8;i++){
            for(int j = 1;j <= 8;j++)
                if(pos[i] == j) printf("1 ");
                else printf("0 ");
            printf("\n");
        }
    }
    for(int i = 1;i <= 8;i++)
        if(check(r,i)){
            pos[r] = i;
            queen(r+1);
            pos[r] = 0;
        }
}

int main(){
    queen(1);
    return 0;
}