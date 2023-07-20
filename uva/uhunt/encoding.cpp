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
ll t,n,i,j;
vi g,sum;
vector<bool> vis;
int a[101000];
int b[101000];
ll mox=1e9+7;
int dfs(int u){
  vis[u]=true;
  int tot=0;
  if(g[u]!=-1 && !vis[g[u]])
    tot+=1+dfs(g[u]);
  vis[u]=false;
  return sum[u]=tot;
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    int t,nl,nr,l,r;
    scanf("%d",&t);
    nr=0;
    while(t--){
      nr++;
      scanf("%d",&n);
      g.assign(n,-1);
      sum.assign(n,-1);
      vis.assign(n,false);
      for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        g[l-1]=r-1;
      }
      int ans=0,max=0;
      for(int i=0;i<n;i++){
        if(sum[i]==-1)dfs(i);
        if(sum[i]>max){
          max=sum[i];
          ans=i;
        }
      }
      printf("Case %d: %d\n",nr,ans+1);
    }
}