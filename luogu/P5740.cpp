
//
// Created by Kjoye on 2022/4/20.
//

#include <bits/stdc++.h>
#include "string"
using namespace std;


struct student{
    string name;
    int a,b,c,sum,id;
}stu[1000];
bool cmp(const student &s1,const student &s2){
    if(s1.sum == s2.sum) return s1.id < s2.id;
    return s1.sum>s2.sum;
}

int main() {
    int n,a,b,c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name;
        cin >> a >> b >> c;
        stu[i].id = i;
        stu[i].a = a;
        stu[i].b = b;
        stu[i].c = c;
        stu[i].sum = a+b+c;
    }
    sort(stu,stu+n-1,cmp);
    printf("%s %d %d %d",stu[0].name.c_str(),stu[0].a,stu[0].b,stu[0].c);
    return 0;
}
