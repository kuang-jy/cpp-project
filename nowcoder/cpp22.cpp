#include <iostream>

using namespace std;

int main()
{
    int arr[6] = { 0 };
    int len = sizeof(arr) / sizeof(int);
    
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    for (size_t i = 0; i < len; i++)
    {
        int min_idx = i;
        for (size_t j = i+1; j < len; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    
    for (size_t i = 0; i < len; i++)
    {
        if (i == len-1)
        {
            cout << arr[i] <<endl;
            break;
        }
        cout << arr[i] << " ";
    }
    
    return 0;
}
