#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double price;
    cin >> price;

    double cost = 0.0;

    //  满100打9折；
    // 满500打8折；
    // 满2000打7折；
    // 满5000打6折
    // 牛阿姨算不清楚自己应该付多少钱，请你帮忙算一下 
    if (price >= 5000)
    {
        cost = price*0.6;
    }
    else if (price < 5000  && price >= 2000)
    {
        cost = price*0.7;
    }
    else if (price < 2000 && price >= 500)
    {
        cost = price*0.8;
    }
    else
    {
        cost = price*0.9;
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << cost << endl;
    return 0;
}
