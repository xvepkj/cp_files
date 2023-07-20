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
const ll Mod = 1000000000; 
ll addMod (ll a, ll b) { ll r = a + b; return r >= Mod ? r - Mod : r; } 
ll subMod (ll a, ll b) { ll r = a - b; return r < 0 ? r + Mod : r; }
ll mulMod (ll a, ll b) { return (a * b) % Mod; }
// ll divMod (ll a, ll b) { return mulMod(a, modInv(b, Mod)); }
ll addTo (ll& a, ll b) { a += b; if (a >= Mod) a -= Mod; return a; } 
ll subTo (ll& a, ll b) { a -= b; if (a < 0) a += Mod; return a; }
ll mulTo (ll& a, ll b) { return a = (a * b) % Mod; }
// ll divTo (ll& a, ll b) { return mulTo(a, modInv(b, Mod)); }
ll n,m;
int main () { 
    while(scanf("%lld %lld",&n,&m)==2){
        ll ans=1;
        for(int i=n;i>=(n-m+1);i--){
            ans=ans*i;
            while(ans%10==0)ans/=10;
            ans=ans%Mod;
        }
        printf("%lld\n",ans%10);
    }
}