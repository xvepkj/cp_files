// #define DEBUG_MODE
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
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef DEBUG_MODE
  #define errp(...) fprintf(stderr, __VA_ARGS__)
#else
  #define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())

const int N = 550;
ll a[N][N], n;

void solve() {
  memset(a, 0, sizeof a);
  scanf("%lld", &a[n][1]);

  errp("before\n");
  for (int i = 0; i <= n; i++)
  for (int j = 0; j <= n; j++)
    errp("%5d%c", a[i][j], " \n"[j == n]);
  

  ll p, q;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= n; j++) {
      if (i >= j) {
        p = q = 0;
        if (i < n)
          for (int k = i + 1; k <= n; k++) p = max(p, a[k][1] + a[k][j]);
        if (j > 0)
          for (int k = 1; k < j; k++) q = max(q, a[i][k] + a[n][k]);   
        dbg(a[i][j]);
        a[i][j] = max(a[i][j], p + q);    
        dbg(p + q);
      }
      else {
        for (int k = i; k < j; k++)
          a[i][j] = max(a[i][j], a[i][k] + a[k + 1][j]);
      }
    }
  }

  errp("after\n");
  for (int i = 0; i <= n; i++)
  for (int j = 0; j <= n; j++)
    errp("%5d%c", a[i][j], " \n"[j == n]);


  printf("%lld\n", a[1][n]);
}

int main () { 
#ifdef DEBUG_MODE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  while (scanf("%lld", &n) != -1) solve();
}