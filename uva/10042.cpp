/* */
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
int digitsum(int n){
    char s[12];
    sprintf(s,"%d",n);
    int sum=0;
    for(int i=0;s[i]!='\0';i++)
        sum+=(s[i]-'0');
    return sum;
}
bool solve(int n){
    dbg(n);
    int s=digitsum(n);
    int t=0;
    bool has=false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0) {
            int x = 0;
            while(n%i == 0) {
                x++;
                n /= i;
            }
            t += x*digitsum(i);
            has=true;
        } 
    }
    if(n!=1)t+=digitsum(n);
    if(s==t && has)
        return true;
    return false;
}
int main () { 
    int n,tst;
    scanf("%d",&tst);
    while(tst--){
        scanf("%d",&n);
        while(n++){
            if(solve(n)){
                printf("%d\n",n);
                break;
            }
        }
    }
}