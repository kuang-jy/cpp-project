#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a,b;
    cin >> a >> b;
    // 和，差，积，商，模（若 a > b 则输出 a - b，a / b，a % b 的值反之输出 b - a，b / a，b % a 的值，不考虑小数和数据越界情况）
    cout << a+b << " ";
    if (a>b)
    {
        cout << a-b << " "<< a*b << " "<< a/b << " "<< a%b <<endl;
    }
    else cout << b-a << " "<< a*b << " "<< b/a << " "<< b%a <<endl;
    return 0;
}
