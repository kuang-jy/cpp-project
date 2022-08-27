#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    // 按顺序分别定义char、int、long、double类型的变量，并用sizeof()依次输出这几个变量在内存中所占用的字节数。
    char c;
    int i;
    long l;
    double d;
    cout << sizeof(c) << "\n" << sizeof(i) << "\n"<< sizeof(l) << "\n"<< sizeof(d) << endl;
    return 0;
}
