/* */
#include <cstdio>
#include <cstdlib>
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
ll C[55][55];
int t,n;
char s[10000];
void gen(){
        C[0][0] = 1;
        for (int n = 1; n <= 50; n++) {
            C[n][0] = C[n][n] = 1;
            for (int k = 1; k < n; k++)
                C[n][k] = C[n - 1][k - 1]+C[n - 1][k];
        }
}
int main () { 
    gen();
    GETLINE(s);
    errp("%s",s);
    t=stoi(s);
    for(int tst=1;tst<=t;tst++){
        string x,y,p;
        GETLINE(s);
        errp("%s",s);
        int i=1;
        while(s[i]!='+')x+=s[i++];
        i++;
        while(s[i]!=')')y+=s[i++];
        i+=2;
        while(s[i]!='\n')p+=s[i++];
        n=stoi(p);
        printf("Case %d: ",tst);
        for(int r=0;r<=n;r++){
            if(C[n][r]>1)printf("%lld",C[n][r]);
            if(n-r){
                if(C[n][r]>1)printf("*");
                printf("%s",x.data());
                if(n-r>1)printf("^%d",n-r);
            }
             if(r){
                if(n-r)printf("*");
                printf("%s",y.data());
                if(r>1)printf("^%d",r);
            }
            if(r!=n)printf("+");
        }
        printf("\n");
    }
}