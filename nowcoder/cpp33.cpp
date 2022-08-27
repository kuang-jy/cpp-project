#include <iostream>

using namespace std;

int main()
{
    char str[100] = { 0 };
    char substr[100] = { 0 };

    cin.getline(str, sizeof(str));
    cin.getline(substr, sizeof(substr));

    int count = 0;

    int i = 0;
    while (str[i] != '\0')
    {
        int temp = i;
        int idx = 0;
        while (str[temp] == substr[idx] && substr[idx] != '\0')
        {
            temp++;
            idx++;
        }
        if (substr[idx] == '\0') count++;
        i++;
    }
    cout << count << endl;

    return 0;
}
