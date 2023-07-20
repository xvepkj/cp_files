// 11659
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
int n,a,x,y,lim;
int count(int no){
    int on=0;
    for(int i=0;i<n;i++){
        if(no & (1<<i))
            on++;
    }
    return on;
}
int main () { 
    while(scanf("%d %d",&n,&a),(n+a)){
        vii pr;
        for(int i=0;i<a;i++){
            scanf("%d %d",&x,&y);
            x--;
            int t=y;
            if(t<0)t=-t;
            t--;
            if(y<0)t=-t;
            if(y<0 && t==0)t--;
            pr.push_back(ii(x,t));
        }
        lim=(1<<n);
        int ans=0;
        dbg(pr,lim);
        for(int i=0;i<lim;i++){
                int j;
                for(j=0;j<a;j++){
                int f=pr[j].first;
                int s=pr[j].second;
                if((i & (1<<f))==0)
                    continue;
                else {
                    if(s>=0 && ((i & 1<<s)==0))
                        break;
                    if(s<0){
                        if(s==-1)s=0;
                         if((i & 1<<-s)!=0)
                                break;
                    }
                }
            }
            if(j==a){
                dbg(i,j);
                ans=max(ans,count(i));
            }
        }
        printf("%d\n",ans);
    }
}