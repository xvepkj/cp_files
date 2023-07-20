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
int t,n,m,k;
int a[101000];
ll mox=1e9+7;
int main() { 
#ifdef DEBUG_MODE
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
#endif
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
	int x=n/2;
	int ans=a[x];
	int j=x+1;
	while(j!=n-1){
		int y=a[j]-a[j-1];
		ans+=min(y,k);
		if(y>=k)break;
		k-=y;
		j++;
	}
	if(a[x]==a[n-1]){
		if(k>=x+1){
			ans+=k/(x+1);
		}
	}
	printf("%d\n",ans);
}