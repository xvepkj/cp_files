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
int m,n;
int p[110],f[110];
int dp[110][15000];
 int solve(int i,int w){
    if(w > m && m < 1800)
        return -1000;
    if(w > m + 200)
        return -1000;
    if(i == n) {
        if(w > m && w <= 2000)
            return -1000;
        return 0;}
    if(dp[i][w] != -1)
        return dp[i][w];
 
    return dp[i][w] = max(solve(i + 1, w),
        f[i] + solve(i + 1, w + p[i]));
 }
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    while(scanf("%d %d",&m,&n)!=EOF){
        for(int i=0;i<n;i++)scanf("%d %d",&p[i],&f[i]);
        memset(dp,-1,sizeof dp);
        int res=solve(0,0);
        printf("%d\n",res);
    }    
    }
