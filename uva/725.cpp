// 725
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
int n,x,y,z,t;
int a[]={0,1,2,3,4,5,6,7,8,9};
map<int,vii> ans;
int main () { 
    do{
            x=0;
            y=0;
            z=1e4;
            for(int i=0;i<5;i++){
                x+=z*a[i];
                y+=z*a[i+5];
                z=z/10;
            }  
            if(x%y==0)
                ans[x/y].push_back(ii(x,y));
        }while(next_permutation(a,a+10));
    while(scanf("%d",&n),n){
        if(t)printf("\n");
        t++;       
        sort(ans[n].begin(),ans[n].end());
        if(ans[n].size()==0){
            printf("There are no solutions for %d.\n",n);
        }
        else {
            for(int i=0;i<ans[n].size();i++)
                printf("%05d / %05d = %d\n",ans[n][i].first,ans[n][i].second,n);
        }
    }

}