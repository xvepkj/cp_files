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
ll x=5;
ll n;
ll memo[10][50000];
ll c[]={1,5,10,25,50};
 ll solve(ll i,ll w){
    if(w==0)return 1;
    if(w<0 || i==x)return 0;
    if(memo[i][w]!=-1)return memo[i][w];
    return memo[i][w]=solve(i+1,w)+solve(i,w-c[i]);
 }
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    memset(memo,-1,sizeof memo);
    while(scanf("%lld",&n)!=EOF){
        ll res=solve(0,n);
        if(res==1)printf("There is only 1 way to produce %lld cents change.\n",n);
        else printf("There are %lld ways to produce %lld cents change.\n",res,n);
    }    
    }
