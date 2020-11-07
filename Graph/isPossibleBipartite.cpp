/*
https://leetcode.com/problems/possible-bipartition/
*/
class Solution {
public:
    bool dfs(int j,int visit[],int color[],vector<int>g[])
    {
        visit[j]=1;
        //cout<<color[j]<<" ";
        for(auto i:g[j])
        {
            if(!visit[i])
            {
                if(color[j]!=color[i])
                {
                    color[i]=(color[j]==1?2:1);
                    dfs(i,visit,color,g);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(color[i]==color[j])
                {
                    return false;
                }
                
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        int m=dislikes.size();
        vector<int>g[N+1];
        int visit[N+1],color[N+1];
        for(int i=1;i<=N;i++) visit[i]=0,color[i]=0;
        for(int i=0;i<m;i++)
        {
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=N;i++)
        {
            if(!visit[i])
            {
                color[i]=1;
                if(!dfs(i,visit,color,g))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
