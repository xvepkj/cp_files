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

const int N = 310;
const int M = 35;
const int INF = (int)1e9;

int t1, t2, n, f[M][N], g[M][N], t[M], c[2][M][M], m[M];
/* f[i][j] : Minimum value for stations 1...i, using j rods 
  for NCPC and t[i] - j rods for BCEW */
int solve() {
  dbg(t1); dbg(t2); dbg(n);

  t[0] = 0;
  for (int i = 1; i <= n; i++) t[i] = m[i] + t[i - 1];
  for (int i = 0; i < n; i++) {
    /* analysing station i + 1 */
    int x = m[i + 1];
    f[0][0] = 0;
    for (int r = 0; r <= t[i]; r++) if (f[i][r] != INF) {
      for (int j = 0; j <= x; j++) {
        int y = f[i][r] + c[0][i + 1][j] + c[1][i + 1][x - j];
        if (y < f[i + 1][r + j]) {
          f[i + 1][r + j] = y;
          g[i + 1][r + j] = j;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= t[n]; j++)
      errp("f(%d, %d) = %d\n", i, j, f[i][j]);

  return f[n][t1];
}

void printSolution() {
  vi res;
  int s = n, r = t1;
  while (s) {
    res.push_back(g[s][r]);
    r -= g[s][r];
    s--;
  }
  dbg(r);
  reverse(begin(res), end(res));
  for (int i = 0; i < res.size(); i++) printf("%d%c", res[i], " \n"[i == res.size() - 1]);
}

int main () { 
#ifdef DEBUG_MODE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  while (scanf("%d%d", &t1, &t2), t1 || t2) {
    memset(c, 0, sizeof c);
    fill_n(&f[0][0], N * M, INF);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &m[i]);
      for (int j = 1; j <= m[i]; j++) scanf("%d", &c[0][i][j]);
      for (int j = 1; j <= m[i]; j++) scanf("%d", &c[1][i][j]);
    }
    printf("%d\n", solve());
    printSolution();
    printf("\n");
  }
}