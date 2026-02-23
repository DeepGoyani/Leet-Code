class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int ans = 0;
        while (!q.empty()) {
            ans++;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                auto j = q.front(); q.pop();

                int x = j.first + 1, y = j.second;
                if (x < maze.size() && maze[x][y] == '.') {
                    if (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)
                        return ans;
                    maze[x][y] = '+';
                    q.push({x, y});
                }

                x = j.first; y = j.second + 1;
                if (y < maze[0].size() && maze[x][y] == '.') {
                    if (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)
                        return ans;
                    maze[x][y] = '+';
                    q.push({x, y});
                }
             x = j.first - 1; y = j.second;
                if (x >= 0 && maze[x][y] == '.') {
                    if (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)
                        return ans;
                    maze[x][y] = '+';
                    q.push({x, y});
                }

                
                x = j.first; y = j.second - 1;
                if (y >= 0 && maze[x][y] == '.') {
                    if (x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1)
                        return ans;
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};