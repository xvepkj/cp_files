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
#define PI acos(-1)
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
vll humnum;
ll num[]={2,3,5,7};
set<ll> exist;
vll powers[4];
void powgen(){
    for(int i=0;i<4;i++){
        ll x=1;
        for(int j=0;j<32;j++){
            powers[i].push_back(x);
            x*=num[i];
        }
    }
}
void gen(){
    for(int i=0;i<32;i++)
        for(int j=0;j<32;j++)
            for(int k=0;k<32;k++)
                for(int l=0;l<32;l++){
                    ll x=powers[3][i]*powers[2][j]*powers[1][k]*powers[0][l];
                    if(x>=1 && exist.count(x)==0){humnum.push_back(x);exist.insert(x);}
                }
    sort(humnum.begin(),humnum.end());

}
int n;
int main() {
    powgen();
    gen();
    dbg(powers[0]);
    dbg(powers[1]);
    dbg(powers[2]);
    dbg(powers[3]);

    while(scanf("%d",&n),n){

        printf("The %d",n);
        
        if(n%10==1 && (n/10)%10!=1) printf("st");
        else if(n%10==2 && (n/10)%10!=1) printf("nd");
        else if(n%10==3 && (n/10)%10!=1) printf("rd");
        else printf("th");
        
        printf(" humble number is %d.\n",humnum[n-1]);
    }
}