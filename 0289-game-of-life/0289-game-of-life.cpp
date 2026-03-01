class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();//row
        int n = board[0].size();//column

        vector<vector<int>> res{board};
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]==0){
                    int cnt =0;
                    for(auto d: dir){
                        
                        int x = i + d[0];
                        int y = j + d[1];
                        if(isValid(x, y , m, n)){
                            if(board[x][y] == 1){
                                cnt++;
                            }
                        }
                        
                    }
                    if(cnt == 3)
                        res[i][j]=1;
                    
                }
                else if(board[i][j] == 1){
                    int cnt = 0;
                    for(auto d: dir){
                        
                        int x = i + d[0];
                        int y = j + d[1];
                        if(isValid(x, y, m, n)){
                            if(board[x][y] ==1){
                                cnt++;
                            }
                        }
                    }
                    if(cnt<2) {
                        res[i][j] = 0;
                    }
                    else if(cnt == 2 || cnt ==3){
                        res[i][j]=1;
                    }
                    else if(cnt >3){
                        res[i][j]=0;
                    }
                }
            }
        }
        

        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                board[i][j] = res[i][j];
            }
        }


    }
};