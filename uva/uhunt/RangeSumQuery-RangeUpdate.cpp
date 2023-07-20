#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
 #define DEBUG_MODE
#ifdef DEBUG_MODE
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("[%s = %s]\n", #x, to_string(x).data())

int n;
vi a, b, seg, upd;

inline int left (int x) { return (x << 1); }
inline int right (int x) { return (x << 1) + 1; }

void build (int L, int R, int k) {
	if (L == R) {
		seg[k] = a[L];
		return;
	}
	build(L, (L + R) / 2, left(k));
	build((L + R) / 2 + 1, R, right(k));
	seg[k] = seg[left(k)] + seg[right(k)];
}

int rsq (int i, int j, int L, int R, int k) {
	errp("\trsq(%d, %d, %d, %d, %d)\n", i, j, L, R, k);
	if (i <= L && j >= R) return seg[k];
	if (i > R || j < L) return 0;
	return upd[k] * (min(j, R) - max(i, L) + 1) +
		rsq(i, j, L, (L + R) / 2, left(k)) + 
		rsq(i, j, (L + R) / 2 + 1, R, right(k));
}

void update (int i, int j, int L, int R, int k, int x) {
	errp("update (%d, %d) (%d, %d)[%d], %d\n", i, j, L, R, k, x);
	if (i <= L && j >= R) {
		upd[k] += x;
		seg[k] = seg[k] + x * (R - L + 1);
		errp("exact range %d, %d [%d]\n", L, R, seg[k]);
		return;
	}
	if (i > R || j < L) return;
	update(i, j, L, (L + R) / 2, left(k), x);
	update(i, j, (L + R) / 2 + 1, R, right(k), x);
	seg[k] += (min(j, R) - max(i, L) + 1) * x;
}

int rsq (int i, int j) {
	return rsq(i, j, 0, n - 1, 1);
}
void update (int i, int j, int x) {
	update(i, j, 0, n - 1, 1, x);
}

int findSum (int x, int y) {
	int sm = 0;
	for (int i = x; i <= y; i++) sm += b[i];
	return sm;
}

int main () { 
#ifdef DEBUG_MODE
	freopen("inp.txt", "r", stdin);
	freopen("oup.txt", "w", stdout);
#endif
	scanf("%d", &n);
	a.assign(n, 0);
	seg.assign(4 * n, 0);
	upd.assign(4 * n, 0);
	b.assign(n, 0);
	int type, x, y, val, cnt = 1;
	while (scanf("%d", &type), type) {
		errp("QUERY %d-------------------\n", cnt++);
		scanf("%d%d", &x, &y);
		if (type == 1) {
			printf("#%d : %d\n", cnt, rsq(x, y));
			printf("correct : %d\n", findSum(x, y));
		}
		else {
			scanf("%d", &val);
			update(x, y, val);
			for (int i = x; i <= y; i++) b[i] += val;
		}
	}
}
