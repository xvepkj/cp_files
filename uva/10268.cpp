/* */
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
const int MAX_LEN = 1000010;
#define GETLINE(x) fgets(x,MAX_LEN,stdin)
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
char s[1000000];
ll x,ans,val,diff;
string y;
int main () { 
    while(GETLINE(s)){
        vi coeff,ex;
        stringstream ss,tt;
        ss<<string(s);
        ss>>x;
        GETLINE(s);
        tt<<string(s);
        for(ll i = 0; tt >> i;) 
            coeff.push_back(i);
        coeff.pop_back();
        reverse(coeff.begin(),coeff.end());
        dbg(coeff);
        ans=0;
        val=1;
        diff=1;
        for(int i=0;i<(int)coeff.size();i++)
        {
            ans+=coeff[i]*val*diff;
            val*=x;
            diff++;
        }
        printf("%lld\n",ans);
    }
}