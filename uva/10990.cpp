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
const int N= 2000010;
int phi[N] ;
int dp[N] ;
void EulerPhi() {
    phi[0] = 0 ;
    phi[1] = 1 ;
    for(int i = 2 ; i <= N ; i++) {
        if(phi[i] == 0) {
            phi[i] = i - 1 ;
            for(int j = i + i ; j <= N ; j += i) {
                if(phi[j] == 0) {
                    phi[j] = j ;
                }
                phi[j] -= phi[j] / i ;
            }
        }
    }
}
int n,m,t;
int main () { 
  EulerPhi();
  dp[0]=0;
  dp[1]=1;
  dp[2]=1;
  for(int i = 3 ; i <= N ; i++) {
      dp[i] = dp[phi[i]] + 1 ;
  }
  for(int i = 1 ; i <= N ; i++) {
      dp[i] += dp[i - 1] ;
  }
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&m,&n);
    printf("%d\n",dp[n]-dp[m-1]);
  }
}