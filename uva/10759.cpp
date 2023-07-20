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
typedef unsigned long long int ull;
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
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a % b); }
int n,x;
ull memo[25][150];
ull solve(int dice_left,int score){
    if(dice_left==0 && score<x)return 0;
    if(dice_left==0 && score>=x)return 1;
    if(memo[dice_left][score]!=-1)return memo[dice_left][score];
    ull ans=0;
    for(int i=1;i<=6;i++){
        ans+=solve(dice_left-1,score+i);
    }
    memo[dice_left][score]=ans;
    return ans;
}
int main () { 
    while(scanf("%d %d",&n,&x),(n+x)){
        memset(memo, -1, sizeof(memo));
        ull correct=solve(n,0);
        ull tot=pow(6ll,n);
        ull g=gcd(correct,tot);
        correct/=g;
        tot/=g;
        if(correct==0)printf("0\n");
        else if(tot==1)printf("%llu\n",correct);
        else printf("%llu/%llu\n",correct,tot);
    }
}