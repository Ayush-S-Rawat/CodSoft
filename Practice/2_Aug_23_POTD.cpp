#include <bits/stdc++.h>
// Shortest Path
// #include <iostream>

using namespace std;

void distance(int N, int M, vector<vector<int>> A, int destx, int desty, int x, int y, int count, int& ans, vector<vector<bool>> vis)
{
    vis[x][y] = true;
    if(x == destx && y == desty)
    {
        // if(ans == -1)
        //     ans = count;
        // else
        //     ans = (count<ans) ? count : ans;
        ans = count;
        return;
    }
    else
    {
        if(count + 1<ans || ans==-1)
        {if(x+1 < N)
            if(A[x+1][y] && !vis[x+1][y])
                distance(N,M,A,destx,desty,x+1,y,count+1,ans,vis);
        if(x-1 >= 0)
            if(A[x-1][y] && !vis[x-1][y])
                distance(N,M,A,destx,desty,x-1,y,count+1,ans,vis);
        if(y+1 < M)
            if(A[x][y+1] && !vis[x][y+1])
                distance(N,M,A,destx,desty,x,y+1,count+1,ans,vis);
        if(y-1 >= 0)
            if(A[x][y-1] && !vis[x][y-1])
                distance(N,M,A,destx,desty,x,y-1,count+1,ans,vis);}
    }
}

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    // int dis = -1;
    // vector<vector<bool> > dis(N,vector<bool>(M, false));
    // distance(N,M,A,X,Y,0,0,0,dis,vis);
    // return dis;
    if(X==0 && Y==0)
        return 0;
    if(A[0][0]==0)
        return -1;
    vector<vector<int>> dis(N,vector<int>(M, INT_MAX));
    queue<pair<int,pair<int,int>>> q;
    dis[0][0] = 0;
    q.push({0,{0,0}});
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    int dist,x,y,i,newr,newc;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        dist = it.first;
        x = it.second.first;
        y = it.second.second;

        for(i=0;i<4;i++)
        {
            newr = x+dr[i];
            newc = y+dc[i];
            if(newr>=0 && newr<N && newc>=0 && newc<M && A[newr][newc] && dist+1<dis[newr][newc])
            {
                dis[newr][newc] = dist+1;
                if(newr == X && newc == Y)
                    return dist+1;
                q.push({dist+1,{newr,newc}});
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> input{{1,1,1,1},
   {0,0,0,1},
   {0,0,0,1}};

   cout<<endl<<shortestDistance(3,4,input,0,3)<<endl;
    return 0;
}
