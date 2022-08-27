#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    if (n % 2 != 0)
    {
        n--;
    }
    if (n > 1)
    {
        n /= 2;
        sum = n*2+(n-1)*n;
    }
    
    cout << sum << endl;
    return 0;
}
