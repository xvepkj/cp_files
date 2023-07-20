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
ll t,n,k;
ll mod=1000000;
ll memo[105][105];
ll solve(ll nt,ll num){
	if(nt==1 || num==0)return 1;
	if(memo[nt][num]!=-1)return memo[nt][num];
	ll ans=0;
	for(int i=0;i<=num;i++)
		ans=(ans+solve(nt-1,num-i))%mod;
	return memo[nt][num]=ans;
}
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    	memset(memo,-1,sizeof memo);
    while(scanf("%lld %lld",&n,&k),(n+k)){
    	ll sol=solve(k,n);
    	printf("%lld\n",sol);
    }  
}