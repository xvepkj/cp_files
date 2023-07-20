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
const int MAX_LEN = 1010;
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
vi primes;
bitset<100002> bs;
int n;
int myPow(int x, int p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  return x * myPow(x, p-1);
}
void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=100000;i++)if(bs[i]){
        for(ll j=i*i;j<=100000;j+=i)
            bs[j]=0;
        primes.push_back((int)i);
    }
}
vii findprimfac(int x){
  vii facts;
  int indx=0;
  int prm=primes[indx];
  int cnt=0;
  while(prm<=x){
    while(x%prm==0){x=x/prm;cnt++;}
    if(cnt)facts.push_back(ii(prm,cnt));
    cnt=0;
    prm=primes[indx++];
  }
  return facts;
}
char s[10010];
int main () { 
  sieve();
  while(GETLINE(s)){
    vii numpow;
    if(s[0]=='0')break;
    stringstream tt;
    tt<<string(s);
    int x=1;
    for(ll i = 0,j=0; tt >> i,tt >> j;) 
        x*=myPow(i,j);
    dbg(x);
    numpow=findprimfac(x-1);
    for(int i=numpow.size()-1;i>=0;i--){
      if(i==0)
          printf("%d %d\n",numpow[i].first,numpow[i].second);
      else 
          printf("%d %d ",numpow[i].first,numpow[i].second);
    }
  }
}