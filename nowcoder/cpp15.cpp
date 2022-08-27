#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            // 1 * 3 = 3
            if (j == i)
            {
                cout << j+1 << " * " << i+1 << " = " << (j+1)*(i+1) << endl;
            }
            else cout << j+1 << " * " << i+1 << " = " << (j+1)*(i+1) << "    ";
        }
    }
    
    return 0;
}
