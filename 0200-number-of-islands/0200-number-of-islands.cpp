class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid){
        grid[row][col] = '#';
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        
        // Traverse the neighbours and check if 1 is there or not
          int delrow[] = {-1, 1, 0, 0};
          int delcol[] = {0, 0, -1, 1};

          for(int k =0; k<4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k]; 

               if(nrow >=0 && nrow <n && ncol>=0 && ncol<m 
                   && grid[nrow][ncol] == '1'){
                     grid[nrow][ncol] = '#';
                     q.push({nrow, ncol});
                   } 
            }
        
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       

        vector<vector<int>> vis(n, vector<int>(m,0));
         int cnt = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){

                if(grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, grid);                    
                }
            }
        }
        return cnt;
    }
};