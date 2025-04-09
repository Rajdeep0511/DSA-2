#include<bits/stdc++.h>
using namespace std;
int main(){
int graph[9][9]={0,0,0,0,0,0,0,0,0,
0,0,1,7,6,0,0,0,6,
0,0,0,7,5,4,3,0,1,
0,0,0,0,9,8,6,0,0,
0,0,0,0,0,7,0,0,0,
0,0,0,0,0,0,5,6,0,
0,0,0,0,0,0,0,8,7,
0,0,0,0,0,0,0,5,4,
0,0,0,0,0,0,0,0,0};
int stages=4,min;
int n=8;
int cost[9],d[9],path[9];
cost[n]=0;
for(int i=n-1;i>=1;i--)
{
    min=INT_MAX;
    for(int k=i+1;k<=n;k++)
    {
        if(graph[i][k]!=0 && (graph[i][k]+cost[k])<min)
        {
            min=graph[i][k]+cost[k];
            d[i]=k;
        }
    }
    cost[i]=min;
    
}
path[1]=1;
path[stages]=n;
for(int i=2;i<stages;i++)
{
    path[i]=d[path[i-1]];
}
cout << "Minimum cost from 1 to " << n << " is: " << cost[1] << endl;
    cout << "Path: ";
    for (int i = 1; i <= stages; i++) {
        cout << path[i] << " ";
    }
    cout << endl;

return 0;
}
