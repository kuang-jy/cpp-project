#include <iostream>
#include <vector>
using namespace std;
int n,m,degrees[5010],a,b,dp[5010],outdegrees[5010],ans;
const int mod = 80112002;
vector<int> links[5010];

//找到所有从食物链顶端到低端的所有路径数
//拓扑排序+dp

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= m;i++){
        scanf("%d %d",&a,&b);
        links[b].push_back(a);
        degrees[a]++;
        outdegrees[b]++;
    }
    //拓扑排序
    int que[5010],front = -1,rear = -1;
    for(int i = 1;i <= n;i++){
        if(!degrees[i]){
            que[++rear] = i;
            dp[i] = 1;   //初始化食物链顶端结点
        }
    }
    while(front < rear){
        int out = que[++front];
        for(int i = 0;i < links[out].size();i++){
            dp[links[out][i]] += dp[out];   //每次删除一个点，都把到这个点的路径数加到他可达的所有点上
            dp[links[out][i]] %= mod;
            if(!--degrees[links[out][i]])
                que[++rear] = links[out][i];
        }
    }
    for(int i = 1;i <= n;i++)   //遍历所有食物链低端的结点，累加取余
        if(!outdegrees[i])
            ans = (ans+dp[i]) % mod;
    printf("%d\n",ans);
    return 0;
}