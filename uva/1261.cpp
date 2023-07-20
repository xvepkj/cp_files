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

const int N = 30;
char a[N];
map<int, bool> dp;

void show (int x) {
  for (int i = 0; i < 25; i++)
    errp("%d", (x & (1 << i)) ? 1 : 0);
  errp("\n");
}

int len(int x) {
  for (int i = 25; i >= 0; i--) if (x & (1 << i)) return i;
  return -1;
}

int conv() {
  int res = 0, n = strlen(a);
  for (int i = 0; i < n; i++) if (a[i] == 'b')
    res |= (1 << i);
  res |= (1 << n);
  return res;
}

int removeGroup (int x, int s, int len) {
  int mask = x & ((1 << s) - 1);
  x >>= len;
  x &= (~((1 << s) - 1));
  x |= mask;
  return x;
}

bool isPossible (int x) {
  errp("isPossible :"); show(x);
  if (x == 1) return true;
  auto it = dp.find(x);
  if (it != dp.end()) return it->second;

  bool can = false;
  int n = len(x), s = 0, y, mask;
  for (int i = 1; i < n; i++) {
    int last = (x & (1 << s)) > 0;
    int cur = (x & (1 << i)) > 0;
    if (last != cur) {
      if (i - s > 1) {
        if (isPossible(removeGroup(x, s, i - s))) {
          can = true;
          break;
        }
      }
      s = i;
    }
  }
  if (n - s > 1 && isPossible(removeGroup(x, s, n - s))) can = true;

  dp[x] = can;
  return can;
}

int main () { 
#ifdef DEBUG_MODE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", a);
    errp("%s\n", a);
    int x = conv();
    printf("%d\n", isPossible(x));
  }
}