#include <iostream>
using namespace std;

void isort(int arr[],int len,int desc){
    for(int i = 1;i < len;i++){
        if(arr[i] < arr[i-1] && desc == 0){  //升序
            int temp = arr[i],j;
            for(j = i-1;j >= 0 && arr[j] > temp;j--)
                arr[j+1] = arr[j];
            arr[j+1] = temp;
        }
        if(arr[i] > arr[i-1] && desc == 1){   //降序
            int temp = arr[i],j;
            for(j = i-1;j >= 0 && arr[j] < temp;j--)
                arr[j+1] = arr[j];
            arr[j+1] = temp;
        }
    }
}

int main(){
    int n,odd[10],even[10],i = 0,j = 0;
    for(int k = 0;k < 10;k++){
        scanf("%d",&n);
        if(n % 2 == 0) even[j++] = n;
        else odd[i++] = n;
    }
    isort(even,j,0);
    isort(odd,i,1);
    for(int k = 0;k < i;k++) printf("%d ",odd[k]);
    for(int k = 0;k < j;k++) printf("%d ",even[k]);
    return 0;
}