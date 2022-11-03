class Solution {
public:
    int m,n;

    void dfs(int x,int y,vector<vector<int>>& grid,int step,int time[12][12]){
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) return;
        grid[x][y] = 2;
        time[x][y] = step;
        dfs(x-1,y,grid,step+1,time);
        dfs(x+1,y,grid,step+1,time);
        dfs(x,y-1,grid,step+1,time);
        dfs(x,y+1,grid,step+1,time);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int time[12][12];
        memset(time,0,sizeof(time));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2){
                    grid[i][j] = 1;
                    dfs(i,j,grid,0,time);
                }
                if(grid[i][j] == 1) return -1;
            }
        }
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                printf("%d\n",time[i][j]);
        int ans = 0;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                ans = max(ans,time[i][j]);
        return ans;
    }
};

int main(){
    Solution s = new Solution;
    s.orangesRotting;
}