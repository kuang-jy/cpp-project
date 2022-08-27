#include <iostream>

using namespace std;

long long solve(int n){
    if (n == 0)
    {
        return 1;
    }
    else{
        return n*solve(--n);
    }
}

int main()
{
    int n;
    cin >> n;
    long long factorial = 1;
    
    factorial = solve(n);

    cout << factorial << endl;
    return 0;
}
