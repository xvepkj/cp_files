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
	#define dbg(x) fprintf(stderr, "[%s = %d]\n", #x, x)
#else
	#define errp(...)
	#define dbg(x) 
#endif
int a[30];
int mx,limit,md;
int result;
int ans,n;
void solve(int i){
	if(i==n){if(mx-limit>ans){ans=mx-limit;result=md;}
			return;}
	solve(i+1);
	if(a[i]<=limit){
		limit=limit-a[i];
		md=(1<<i)|md;
		solve(i+1);
		limit=limit+a[i];
		md=(1<<i)^md;
			}
}
int main () { 
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	while(scanf("%d",&mx)!=-1){
		limit=mx;
		ans=0;
		md=0;
		result=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
		solve(0);
	for(int i=0;i<n;i++){
		if((1<<i) & result)printf("%d ",a[i]);
	}
	printf("sum:%d\n",ans);
}}
