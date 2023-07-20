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
int t;
int line;
int inix,iniy;
int x[9],y[9];
bool used[8];
int solno;
bool check(int xx,int yy,int cols){
	for(int i = 0; i < cols; i++)
        if(abs(x[i]-xx) == abs(y[i]-yy))
            return false;
    return true;
}
void recurbacktrack(int column){
	if(column==8){
	if(y[iniy-1] == inix-1){
		solno++;
		printf("%s%d      ",solno>9?"":" ",solno);
		for(int i=0;i<8;i++)
			printf("%d%s",y[i]+1,i==7?"\n":" ");
		}
		return;
	}
	for(int i=0;i<8;i++){
		if(!used[i] && check(column,i,column)){
			used[i]=true;
			x[column]=column;y[column]=i;
			recurbacktrack(column+1);
			used[i]=false;
		}
	}
}
int main () { 
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&inix,&iniy);
		if(line)
			printf("\n");
		line=1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n");
		printf("\n");
		memset(used,false,sizeof used);
		solno=0;
		recurbacktrack(0);
	}
}