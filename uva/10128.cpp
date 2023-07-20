/* */
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
const int MAX_LEN = 1010;
#define GETLINE(x) fgets(x,MAX_LEN,stdin);
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<ll> vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(...) errp("[%s]: ", #__VA_ARGS__), dbg_str(__VA_ARGS__)
#else
	#define errp(...)
	#define dbg(...)
#endif
template <typename U, typename V> string to_string (pair<U, V>);
string to_string (const string& e_) { return "\"" + e_ + "\""; }
string to_string (char e_) { return "\'" + string(1, e_) + "\'"; }
string to_string (bool e_) { return e_ ? "true" : "false"; }
template <typename T> string to_string (T e_) {
	string s_ = "[ ";
	for (const auto& x_ : e_) s_ += to_string(x_) + " ";
	return s_ + "]";
}
template <typename U, typename V> string to_string (pair<U, V> e_) {
	return "(" + to_string(e_.first) + ", " + to_string(e_.second) + ")";
}
void dbg_str () { errp(" \n"); }
template <typename U, typename... V> void dbg_str (U u, V... v) {
 	errp(" %s", to_string(u).c_str()); dbg_str(v...);
}
/* --- */
bool cmp1s(int x,int y){return (x%10)<(y%10);}
bool cmp10s(int x,int y){return ((x/10)%10)<((y/10)%10);}
bool cmp100s(int x,int y){return ((x/100)%10)<((y/100)%10);}
void print(int *a,int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int t,n,p,r;
ll dp[15][15][15];
int main () { 
	dp[1][1][1]=1;
	for(int i=2;i<=13;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i;k++)
				dp[i][j][k]=dp[i-1][j][k-1]+dp[i-1][j-1][k]+dp[i-1][j][k]*(i-2);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&p,&r);
		printf("%lld\n",dp[n][p][r]);
	}
}