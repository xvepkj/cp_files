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
int main () { 
#ifdef DEBUG_MODE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	double a[10010];
	double ans=0,avg;
	for(int i=0;i<n;i++){scanf("%lf",&a[i]);avg+=a[i];}
	avg=avg/n;
	for(int i=0;i<n;i++)if(a[i]>avg)ans+=a[i]-avg;
	printf("%.2f\n",ans);
}
