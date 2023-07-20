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
vi primes;
bitset<1000020> bs;
void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=1000000;i++)if(bs[i]){
        for(ll j=i*i;j<=1000000;j+=i)
            bs[j]=0;
        primes.push_back((int)i);
    }
}
ll sumDiv(ll N) { 
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1; // start from ans = 1 
  while (PF * PF <= N) { ll power = 0; 
  while (N % PF == 0) { N /= PF; power++; } 
  ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1); 
  PF = primes[++PF_idx]; } 
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last 
  return ans; 
}
int n,ans;
int main(){
  sieve();
  int t=0;
  while(scanf("%d",&n),n){
    t++;
    ans=-1;
    if(n==1){printf("Case %d: 1\n",t);continue;}
    for(int i=1;i<=1000;i++){
      if(sumDiv(i)==n)ans=i;
    }
    printf("Case %d: %d\n",t,ans);
  }
}