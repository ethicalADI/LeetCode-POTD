// 01 Matrix


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    distance[i][j]=0;
                }
            }
        }

        int dirx[]={0, 0, 1, -1};
        int diry[]={1, -1, 0, 0};
        while(!q.empty()){
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
        
            q.pop();
            for(int k=0; k<4; ++k){
                int ni=i+dirx[k];
                int nj=j+diry[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n && (d+1)<distance[ni][nj]){
                    distance[ni][nj]=d+1;
                    q.push({d+1, {ni, nj}});
                }
            }
        }
        return distance;
    }
};
