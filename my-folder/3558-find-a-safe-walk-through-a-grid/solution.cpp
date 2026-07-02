class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> direction ={{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> deq;

        result[0][0] = grid[0][0];
        deq.push_front({0,0});

        while(!deq.empty()){
            auto [r,c]=deq.front();
            deq.pop_front();

            for(auto& dir : direction) {
                int nr = r+dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nr >= m || nc < 0 ||nc >= n) continue;

                if(result[r][c] + grid[nr][nc] < result[nr][nc]){
                    result[nr][nc]=result[r][c]+grid[nr][nc];

                    if(grid[nr][nc]==0){

                        deq.push_front({nr, nc});
                    }else{
                        deq.push_back({nr, nc});
                    }
                }
            }
        }
        int minimum_health_lost = result[m - 1][n - 1];
        return (health - minimum_health_lost) >= 1;
    }
};
