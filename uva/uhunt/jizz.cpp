/*PKJ*/
#define DEBUG_MODE
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
ll t,nl,l,nr,r;
char a[100100];
ll mox=1e9+7;
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%lld",&t);
    while(t--){
    	int i;
        scanf("%lld %lld",&nl,&l);
        scanf("%lld %lld",&nr,&r);
        ll ans=0;
        for(int j=l;j<=r;j++){
        int d=j;
        ll x=d%10;
        ll y; 
        i=0;
        while(d!=0){
        	dbg(d);
        	dbg(i);
        	i++;
        	d=d/10;
        	dbg(d);
        	y=d%10;
        	if(x!=y){
        		ans+=(x*((ll)pow(10,i-1)))%mox;
        		x=y;
        	}
        } }
        printf("%lld\n",ans);    
}
}