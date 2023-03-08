#include <iostream>
#include <vector>
using namespace std;
int n,m,f,t,ans[100010];
vector<int> links[100010];  //存图
/*
    反向建图，考虑从编号最大结点可以访问的所有节点，从n-1走dfs，若数组中有值直接返回
*/

void dfs(int i,int cur){
    if(ans[i] != 0) return;
    ans[i] = cur;
    for(int j = 0;j < links[i].size();j++)
        dfs(links[i][j],cur);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= m;i++){
        scanf("%d %d",&f,&t);
        links[t].push_back(f);  //反向建边
    }
    for(int i = n;i >= 1;i--) dfs(i,i);
    for(int i = 1;i <= n;i++) printf("%d ",ans[i]);
    return 0;
}