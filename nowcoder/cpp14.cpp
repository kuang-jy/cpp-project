#include <iostream>

using namespace std;

int main()
{
    for (size_t i = 100; i < 1000; i++)
    {
        int high = i%10;
        int mid = (i/10)%10;
        int low = i/100;
        if (high*high*high + mid*mid*mid + low*low*low == i)
        {
            cout << i << endl;
        }
    }
    
    return 0;
}
