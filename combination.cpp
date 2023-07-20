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
const ll Mod=998244353;
const int N=3*1e5+12;
ll factorialNumInverse[N + 1]; 
ll naturalNumInverse[N + 1]; 
  
ll fact[N + 1]; 
  
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
ll Binomial(ll N, ll R, ll p) 
{ 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 

ll addMod (ll a, ll b) { ll r = a + b; return r >= Mod ? r - Mod : r; }
int n,k,r,l;
vii lamps;
int main () { 
    InverseofNumber(Mod); 
    InverseofFactorial(Mod); 
    factorial(Mod); 
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&l,&r);
        lamps.push_back(ii(l,1));
        lamps.push_back(ii(r+1,-1));
    }
    sort(lamps.begin(),lamps.end());
    ll cur=0;
    ll ans=0;
    for(int i=0;i<(int)lamps.size();i++){
        if(lamps[i].second==-1){
            cur--;
        }
        else{
            cur++;
            if(cur>=k){
                ans=addMod(ans,Binomial(cur-1,k-1,Mod));
            }
        }
    }
    printf("%lld\n",ans);
}