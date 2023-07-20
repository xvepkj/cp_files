/*PKJ*/
// #define DEBUG_MODE
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef DEBUG_MODE
    #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
    #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
int INF=1e8;
int t,n,m,k;
int a[101][101];
vector<vi> adjlist;
vi vis;
vi vis1;
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<adjlist[u].size();i++){
		{
			int h=adjlist[u][i];
			if(!vis[h])
				dfs(h);
		}
	}
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    for(int e=1;e<=t;e++){
    	dbg(e);
    	scanf("%d",&n);
    	vis.assign(n,0);
    	vis1.assign(n,0);   	
    	adjlist.assign(n,vi(0));
    	int x;
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			{
    				scanf("%d",&x);
    				if(x)adjlist[i].push_back(j);
    			}
    			memset(a,-1,sizeof a);
    			dfs(0);
    			for(int i=0;i<n;i++)vis1[i]=vis[i];
    			for(int i=0;i<n;i++){
    				if(vis1[i]){
    					vis.assign(n,0);
    					a[i][i]=1;
    					vis[i]=1;
    					dfs(0);
    					for(int j=1;j<n;j++)
    						if(vis1[j] && !vis[j])a[i][j]=1;
    				}
    			}
    			for(int i=0;i<n;i++)if(vis1[i])a[0][i]=1;
    			 printf("Case %d:\n",e);
        		putchar('+');
        		for(int i = -n+1; i < n; i++)
            	putchar('-');
        		puts("+");
        		for(int i = 0; i < n; i++) {
            	for(int j = 0; j < n; j++) {
                putchar('|');
                putchar(a[i][j]==1 ? 'Y' : 'N');
            	}
            	puts("|");
            	putchar('+');
            	for(int j = -n+1; j < n; j++)
                putchar('-');
            	puts("+");
        }
    }
}