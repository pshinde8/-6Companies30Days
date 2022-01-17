
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid.empty())
            return 0;
        int min=0, tot=0, rot=0;
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]!=0)
                    tot++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty())
        {
            int k = q.size();
            rot+=k;
            while(k--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    
                }
            }
            if(!q.empty())
                min++;
        }
        if(tot==rot)
            return min;
        else
            return -1;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<vector<int>>& grid;
		int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
        	for(int j=0; j<n; j++)
        	{
        		int k[i][j];
        		cin>>k[i][j];
        		grid.push_back(k[i][j]);
			}
		}
		Solution ob;
		cout<<ob.orangesRotting(grid)<<endl;
	}
}
