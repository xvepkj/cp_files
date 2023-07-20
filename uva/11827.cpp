/* */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
const int MAX_LEN = 10100;
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
int t,g;
char s[MAX_LEN];
int gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
// void filldivisors(){
//         for(int i=1;i*i<=n;i++)
//             if(n%i==0){
//                 divx.push_back(i);
//                 if(i*i!=n)
//                     divx.push_back(n/i);
//             }
// }
int main () {
    scanf("%d",&t);
    GETLINE(s);
    while(t--){
        GETLINE(s);
        vi num;
        g=1;
        stringstream ss;
        ss<<string(s);
        for(int i = 0; ss >> i; ) {
            num.push_back(i);
        }
        for(int i=0;i<(int)num.size();i++)
            for(int j=i+1;j<(int)num.size();j++)
                g=max(g,gcd(num[i],num[j]));
        printf("%d\n",g);
    }   
}