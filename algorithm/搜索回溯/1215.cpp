#include <iostream>
using namespace std;
int n,size,xa,ya,xb,yb;
bool flag = false;
char mp[110][110];

void dfs(int x,int y){
    if(x < 0 || y < 0 || x >= size || y >= size || mp[x][y] == '#' || flag) return;
    if(x == xb && y == yb){
        flag = true;
        return;
    }
    mp[x][y] = '#';
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main(){
    cin >> n;
    while(n--){
        cin >> size;
        for(int i = 0;i < size;i++)
            for(int j = 0;j < size;j++)
                cin >>mp[i][j];
        cin >> xa >> ya >> xb >> yb;
        if(mp[xa][ya] == '#' || mp[xb][yb] == '#'){
            printf("NO\n");
            continue;
        }
        flag = false;
        dfs(xa,ya);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}