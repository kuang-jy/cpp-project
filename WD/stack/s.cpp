#include <iostream>
using namespace std;

void myfun(int n){
	int i,j,s=0,x;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			++s;
		}
	}
	i=0;j=n;x=0;
	while(i<j){
		i++;
		j--;
		x+=2;
	}
	printf("%d,%d",s,x);
}

int main(){
    myfun(5);
    return 0;
}