#include <iostream>
#include <stdlib.h>
using namespace std;

double nbl(){
    char str[100];
    cin >> str;
    switch(str[0]){
        case '+': return nbl()+nbl();
        case '-': return nbl()-nbl();
        case '*': return nbl()*nbl();
        case '/': return nbl()/nbl();
        default: return atof(str);
    }
}

int main(int argc, char const *argv[])
{
    printf("%f",nbl());
    return 0;
}
