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
char s[100];
int x,ans,val;
string y;
int main () { 
    while(GETLINE(s)){
        vi coeff,ex;
        stringstream ss,tt;
        ss<<string(s);
        for(int i = 0; ss >> i; ) {
            coeff.push_back(i);
        }
        reverse(coeff.begin(),coeff.end());
        dbg(coeff);
        GETLINE(s);
        tt<<string(s);
        for(int i = 0; tt >> i; ) {
            ex.push_back(i);
        }
        dbg(ex);
        for(int j=0;j<(int)ex.size();j++){
            ans=0;
            val=1;
            for(int i=0;i<(int)coeff.size();i++)
            {
                ans+=coeff[i]*val;
                val*=ex[j];
            }
            printf("%d",ans);
            if(j!=(int)ex.size()-1)printf(" ");
        }
        printf("\n");
    }
}