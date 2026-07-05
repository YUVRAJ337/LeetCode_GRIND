class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    pair<int, int> dp[101][101];

    int getIntFromChar(char ch){
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string> & board){
        if(i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X') {
            return true;
        }
        return false;
    }

    pair<int, int> solve(int i, int j, vector<string> & board){
        if(board[i][j] == 'E'){
            return {0, 1};
        }
        
        if(dp[i][j].first != -1) {
            return dp[i][j];
        }

        int maxScore = -1;
        int totalPaths = 0;

        char ch = board[i][j];
        int currentVal = getIntFromChar(ch);

        if(isValid(i - 1, j, board)){
            auto [score, paths] = solve(i - 1, j, board);
            if(paths > 0) {
                if(score > maxScore) {
                    maxScore = score;
                    totalPaths = paths;
                } else if(score == maxScore) {
                    totalPaths = (totalPaths + paths) % mod;
                }
            }
        }

        if(isValid(i, j - 1, board)){
            auto [score, paths] = solve(i, j - 1, board);
            if(paths > 0) {
                if(score > maxScore) {
                    maxScore = score;
                    totalPaths = paths;
                } else if(score == maxScore) {
                    totalPaths = (totalPaths + paths) % mod;
                }
            }
        }

        if(isValid(i - 1, j - 1, board)){
            auto [score, paths] = solve(i - 1, j - 1, board);
            if(paths > 0) {
                if(score > maxScore) {
                    maxScore = score;
                    totalPaths = paths;
                } else if(score == maxScore) {
                    totalPaths = (totalPaths + paths) % mod;
                }
            }
        }

        if(maxScore == -1) {
            return dp[i][j] = {0, 0};
        }

        return dp[i][j] = {maxScore + currentVal, totalPaths};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = {-1, -1};
            }
        }

        auto [maxScore, totalPaths] = solve(n - 1, n - 1, board);
        return {maxScore, totalPaths};
    }
};
