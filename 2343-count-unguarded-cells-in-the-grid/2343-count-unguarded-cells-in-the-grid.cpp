class Solution {
public:
    int M,N;
    // unordered_map<int,int> mp;
    void solve(int i,int j, vector<vector<int>> &grid) {
        grid[i][j] = -1;
        for(int x = i+1;x<M;x++) { // down
            if(grid[x][j] == 2) break;
            if(N == 1 && grid[x][j] == -1) break;
            grid[x][j] = -1;
        }
        for(int y = j+1; y<N; y++) { //right
            if(grid[i][y] == 2) break;
            if(M == 1 && grid[i][y] == -1) break;
            grid[i][y] = -1;
        }
        for(int x = i-1;x>=0;x--) { //up
            if(grid[x][j] == 2) break;
            if(N == 1 && grid[x][j] == -1) break;
            grid[x][j] = -1;
        }

        for(int y = j-1;y>=0;y--){ //left
            if(grid[i][y] == 2) break;
            if(M == 1 && grid[i][y] == -1) break;
            grid[i][y] = -1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        //wall = 2, guards = 1;
        M = m, N = n;
        for(auto w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        // sort(guards.begin(), guards.end());
        for(auto g : guards) {
            solve(g[0], g[1], grid);
        }
        int ans = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) ans++;
            }
        }

        return ans;
    }
};