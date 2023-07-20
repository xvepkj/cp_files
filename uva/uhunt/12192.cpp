#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
 // #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())
int a[505][505];
int Lo,Up;
int Lbound(int x,int y,int n){
	int l=0;
	int r=n-1;
	int m;
	while(l<r){
		m=(l+r)/2;
		if(a[x+m][y+m]>=Lo)
			r=m;
		if(a[x+m][y+m]<Lo)
			l=m+1;
	}
	if(a[x+l][y+l]>=Lo)return l;
	else return -1;
}
int Rbound(int x,int y,int n){
	int l=0;
	int r=n-1;
	int m=(l+r)-((l+r)/2);
	while(l<r){
		m=(l+r)-((l+r)/2);
		if(a[x+m][y+m]<=Up)
			l=m;
		if(a[x+m][y+m]>Up)
			r=m-1;
	}
	if(a[x+l][y+l]<=Up)return l;
	else return -1;
}
int main () { 
#ifdef DEBUG_MODE
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif
	int n,m;
	while(scanf("%d %d",&n,&m),(n+m)!=0){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
	dbg(n); dbg(m);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d %d",&Lo,&Up);
		dbg(Lo);
		int maxx=0, low, high, len;
			int j=0;
			for(int k=0;k<=n-1;k++){
				len = min(n - k, m);
				low = Lbound(k, 0, len);
				if (low == -1) continue;
				high = Rbound(k, 0, len);
				if (high == -1) continue;
				maxx = max(maxx, high - low + 1);
			}
			for(int k=1;k<=m-1;k++)
			{
				len = min(m - k, n);
				low = Lbound(0, k, len);
				if (low == -1) continue;
				high = Rbound(0, k, len);
				if (high == -1) continue;
				maxx = max(maxx, high - low + 1);

			}
		printf("%d\n",maxx);
	}
	printf("-\n");
	}
}
