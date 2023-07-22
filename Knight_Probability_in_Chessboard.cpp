//Knight Probability in Chessboard

class Solution {
public:

double dp[25][25][104];
int xDir[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
int yDir[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };

double solveDp(int i,int j,int k, int n)
{
    if(i < 0 || j < 0 ||i >= n || j >= n) return 0;
    if(k == 0) return 1;
    if(dp[i][j][k] != 0) return dp[i][j][k];

    double res = 0;

    for(int p = 0;p < 8; ++p)
    {
      int x = i + xDir[p];
      int y = j + yDir[p];
      res += solveDp(x,y,k-1,n);
    }
    return dp[i][j][k] += (res/8.0);
}

    double knightProbability(int n, int k, int row, int column) {

        memset(dp,0,sizeof(dp));
        return solveDp(row,column,k,n); 
    }
};
