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
int t,n,gx,gy;
int x[11];
int y[11];
int memo[11][1<<11];
int dist[11][11];
int solve(int p,int bmask){
    if(bmask==((1<<(n+1))-1))return dist[p][0];
    if(memo[p][bmask]!=-1)return memo[p][bmask];
    int ans = 2000000000;
    for(int i=0;i<=n;i++){
        if(i!=p && !(bmask & (1<<i)))
            ans=min(ans,dist[i][p]+solve(i,bmask | (1<<i)));
    }
    return memo[p][bmask]=ans;
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        memset(memo,-1,sizeof memo);
        scanf("%d %d",&gx,&gy);
        scanf("%d %d",&x[0],&y[0]);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&x[i],&y[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            int an=solve(0,1);
            printf("The shortest path has length %d\n",an);
    }
}
