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
ll a,b,N;
ll f(ll val){
    return (a*(val*val%N)%N + b)%N;
}
pll floydCycleFinding(ll x0) { // function int f(int x) is defined earlier
 // 1st part: finding k*mu, hare’s speed is 2x tortoise’s
  ll tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0 
  while (tortoise != hare) 
    { tortoise = f(tortoise); hare = f(f(hare)); } 
    // 2nd part: finding mu, hare and tortoise move at the same speed 
    ll mu = 0; hare = x0; 
        while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;} 
    // 3rd part: finding lambda, hare moves, tortoise stays 
    ll lambda = 1; hare = f(tortoise); 
        while (tortoise != hare) { hare = f(hare); lambda++; } return pll(mu, lambda); }
int main () { 
    while(scanf("%lld",&N),N){
        scanf("%lld %lld",&a,&b);
        pll ans=floydCycleFinding(0);
        printf("%lld\n",N-ans.second);
    }
}