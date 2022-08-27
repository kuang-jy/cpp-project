#include <iostream>

using namespace std;

int main()
{
    // 有数列为：9，99，999，...，9999999999（10个9）。要求使用循环结构编写程序计算此数列的和，并在控制台输出结果。
    long long num = 9;
    long long sum = 0;
    for (size_t i = 0; i < 10; i++)
    {
        sum += num;
        num = num*10+9;
    }
    cout << sum << endl;
    return 0;
}
