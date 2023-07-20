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
int n,t,p;
int a[109];
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--){
        dbg(t);
        scanf("%d",&p);
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int dp[30001];

        dp[0] = 0;
        for (int i=1; i<=30000; i++)
        dp[i] = INF;

        for(int i=0;i<n;i++){
        for (int v = 25000 - a[i]; v >= 0; v--)
        if (dp[v] < INF)
        dp[v+a[i]] = min(dp[v+a[i]], dp[v]+1);
            }
        for(int i=p;i<25000;i++)
            if(dp[i]!=INF){
                printf("%d %d\n",i,dp[i]);
                break;
            }
    }
    }
