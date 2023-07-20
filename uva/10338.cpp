#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

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
int t;
char s[25];
int freq[27];
ll fac[28];
void fact(){
  fac[0]=1;
  for(int i=1;i<=20;i++){
    fac[i]=fac[i-1] *i;
  }
}
int main() {
  fact();
  scanf("%d",&t);
  int tst=0;
  while(t--){
    tst++;
    memset(freq,0,sizeof freq);
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;s[i]!='\0';i++){
      freq[s[i]-'A']++;
    }
    ll ans=fac[n];
    for(int i=0;i<26;i++)
      ans/=fac[freq[i]];
    printf("Data set %d: %lld\n",tst,ans);
  }
}

