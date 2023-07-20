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
const int N=55;
vector<vi> pegs;
ll dp[N];
int t,n;
bool perfectsq(int x){
	int z=sqrt(x);
	if(z*z==x)
		return true;
	return false;
}
void calc(){
	int pegno=1;
	int no=1;
	while(pegno<52){
		int i;
		for(i=1;i<pegno;i++){
			if(perfectsq(pegs[i].back()+no)){
				pegs[i].push_back(no);
				break;
			}
		}
		if(i==pegno){
			for(int i=1;i<pegno;i++){
				dp[pegno-1]+=(int)pegs[i].size();
			}
			pegs[i].push_back(no);
			pegno++;
		}
		no++;
	}
}
int main () { 
	pegs.assign(N,vi(0));
	calc();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}