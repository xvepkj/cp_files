// 12844
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
int t,tst;
int w[15];
int ans[7];
int main () { 
    scanf("%d",&t);
    while(t--){
        tst++;
        for(int i=1;i<=10;i++)
            scanf("%d",&w[i]);
        sort(w,w+10);
        for(int a1=1;a1<=400;a1++){
            ans[1]=a1;
            ans[2]=w[1]-a1;
            ans[3]=w[2]-a1;
            ans[4]=w[9]-ans[3];
            ans[5]=w[10]-ans[4];
            vi ha;
            for(int j=1;j<=5;j++)
                for(int k=j+1;k<=5;k++){
                    ha.push_back(ans[j]+ans[k]);
                }
            sort(ha.begin(),ha.end());
            int j;
            for(j=0;j<10;j++){
                if(ha[j]!=w[j+1] || (j<=4 && ans[j+1]<0))
                    break;
            }
            if(j==10)
                break;
        }
        printf("Case %d: ",tst);
        sort(ans+1,ans+6);
        for(int i=1;i<=5;i++)
            printf("%d%s",ans[i],(i==5)?"\n":" ");
    }
}