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
int n,m,s;
int a[45];
int b[45];
int memo[305][305];
int solve(int x,int y){
    if(x==0 && y==0)return 0;
    if(x<0 || y<0)return INF;
    if(memo[x][y]!=-1)return memo[x][y];
    memo[x][y]=INF;
    for(int i=0;i<m;i++){
        memo[x][y]=min(1+solve(x-a[i],y-b[i]),memo[x][y]);
    }
    return memo[x][y];
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&n);
    while(n--){
        vii z;
        memset(memo,-1,sizeof memo);
        scanf("%d %d",&m,&s);
        for(int i=0;i<=s;i++)
            for(int j=0;j<=s;j++)if(((i*i)+(j*j))==(s*s))z.push_back(ii(i,j));
        for(int i=0;i<m;i++)scanf("%d %d",&a[i],&b[i]);
        int res=INF;
        for(int i=0;i<z.size();i++)res=min(res,solve(z[i].first,z[i].second));
        if(res!=INF)printf("%d\n",res);
        else printf("not possible\n");
    }
    }
