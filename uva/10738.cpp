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
const int N=1000010;
int numDiff[N];
int mu[N];
int M[N];
bool squarefree[N];
void modsieve(){
  mu[1]=1;
  M[1]=1;
  memset(squarefree,true,sizeof squarefree);
  for(int i=2;i<N;i++){
    if(numDiff[i]==0)
      for(int j=i;j<N;j+=i){
        numDiff[j]++;
        if(j%(i*i)==0)squarefree[j]=false;
      }
    if(!squarefree[i])mu[i]=0;
    if(squarefree[i] && (numDiff[i]&1))mu[i]=-1;
    if(squarefree[i] && !(numDiff[i]&1))mu[i]=1;
    M[i]+=mu[i]+M[i-1];
  }
}
int n,ans;
int main(){
  modsieve();
  while(scanf("%d",&n),n){
    printf("%8d%8d%8d\n",n,mu[n],M[n]);
  }
}