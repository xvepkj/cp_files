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
int ans,sum,n,m,i,j;
char gird[21][21],land;
int memo[21][21];
void dfs(int x,int y){
    if(y<0)y=m-1;
    if(y>m-1)y=0;
    if(x<0 || x>n-1)return;
    if(memo[x][y]!=0 || gird[x][y]!=land)return;
    memo[x][y]=1;
    sum++;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d %d",&n,&m)==2){
        memset(memo,0,sizeof memo);
        for(int i=0;i<n;i++)scanf("%s",gird[i]);
        scanf("%d %d",&i,&j);
        land=gird[i][j];
        dfs(i,j);
        ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                sum=0;
                dfs(i,j);
                ans=max(ans,sum);
            }
        printf("%d\n",ans);
    }
}