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
#define PI acos(-1)
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
pair<double, double> get_pos(int n) {
    int level = sqrt(n);
    int trianglenofromleft = n - level * level + 1;
    double x = -(level + 1) * 0.5 + trianglenofromleft * 0.5;
    double height = cos(PI / 6);
    double sub_height = 0.5 * tan(PI / 6);
    double y = level * height;
    if (trianglenofromleft % 2 == 1)
        y += (height - sub_height);
    else
        y += sub_height;
    return make_pair(x, y);
}
double dist(const pair<double, double> &p1, const pair<double, double> &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    long long n, m;
    while (scanf("%lld %lld", &n, &m) == 2) {
        auto pos1 = get_pos(n);
        auto pos2 = get_pos(m);
        printf("%.3f\n", dist(pos1, pos2));
    }
    return 0;
}