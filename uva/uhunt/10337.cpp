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
int t,n,x;
int a[11][1005];
int memo[11][1005];
int solve(int alt,int mile){
    if(alt>9 || alt<0 || mile>x)
    return 1e9;
    if(mile==x){
        if(alt==0)return 0;
        else return 1e9;
    }
    if(memo[alt][mile]!=-1)return memo[alt][mile];
    return memo[alt][mile]=min(30-a[alt][mile]+solve(alt,mile+1),min(60-a[alt][mile]+solve(alt+1,mile+1),20-a[alt][mile]+solve(alt-1,mile+1)));
    }

int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x=n/100;
        for(int i=9;i>=0;i--)
            for(int j=0;j<x;j++)
                scanf("%d",&a[i][j]);
        memset(memo,-1,sizeof memo);
        int ans=solve(0,0);
        printf("%d\n\n",ans);
    }
}
