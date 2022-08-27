#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // 下落的高度和落地的次数
    double h;
    int n;

    cin >> h;
    cin >> n;

    double H = 0;
    double s = 0;
    H = h*pow(0.5,n);
    if (n == 1)
    {
        s = h;
    }
    else{
        s = h+h*(1-pow(0.5,n-1))/0.5;
    }
    printf("%.1f %.1f\n",s,H);
    return 0;
}
