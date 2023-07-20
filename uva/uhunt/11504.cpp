#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
 
using namespace std;
 
 
typedef vector<int>ve;
typedef vector<ve>vve;
vve G(100010);
bool known[100010];
stack<int>s;
 
 
void dfs(int num)
{
    int j;
    known[num]=true;
     
    for (j=0;j<G[num].size();j++)
    {
        if (known[G[num][j]]) continue;
        dfs(G[num][j]);
    }
    s.push(num);
}
 
int main() {
    
    int t,n,m,u,v,i,global,j;
     
    cin>>t;
    while (t--)
    {
        global=0;
        cin>>n>>m;
         
        for (i=0;i<=n;i++)
            G[i].clear();
         
        while (m--)
        {
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
        }
         
        memset(known,false,sizeof(known));
         
        for (i=1;i<=n;i++)
        {
            if (known[i]) continue;
            dfs(i);
        }
         
        memset(known,false,sizeof(known));
         
        while (!s.empty())
        {
            u=s.top();
            s.pop();
            if (known[u]) continue;
            queue<int>q;
            global++;
            q.push(u);
            while (!q.empty())
            {
                v=q.front();
                q.pop();
                if (known[v]) continue;
                known[v]=true;
                 
                for (j=0;j<G[v].size();j++)
                {
                    if (known[G[v][j]]) continue;
                    q.push(G[v][j]);
                }
            }
        }
        cout<<global<<endl;
    }
     
    return 0;
}