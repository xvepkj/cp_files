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
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) {
	string res = "["; for (int i = 0; i < (int)v.size()-1; i++) res += to_string(v[i]) + ", ";
	if (!v.empty()) res += to_string(v.back());	res += "]"; return res; }
int main () { 
#ifdef XVENOM
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif
	int t,x,y,z;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&x,&y,&z);
		int u;
		// float m=(z+y-x)/2;
		dbg(3/2);
		dbg(u);
		int ans=0;
		if(u<0){u=0;ans++;}
		dbg(u);
		dbg(ans);
		if(z>u)ans+=z-u;
		printf("%d\n",ans);
	}
}