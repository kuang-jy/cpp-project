#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);
    int max = INT_MIN,min = INT_MAX;
    
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << min << " " << max << endl;
    return 0;
}
