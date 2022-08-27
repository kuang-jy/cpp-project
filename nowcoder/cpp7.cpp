#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << (a > b ? (a > c ? a : c) : (b > c ? b : c)) << endl;
    return 0;
}
