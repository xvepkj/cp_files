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
int n,p,imp,timex,t;
int a[10];
int anstime[10];
int prefix[10];
int ans[7];
int cur[7];
vector<vi> imporalign;
int main () { 
    while(scanf("%d",&n),n){
        t++;
        printf("Data set %d\n",t);
        printf("Order: ");
        for(int i=1;i<=5;i++)
            ans[i]=1e9;
        imporalign.assign(9,vi(0));
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&p);
        for(int i=0;i<p;i++){
            scanf("%d %d",&imp,&timex);
            imporalign[imp].push_back(timex);
        }
        sort(a,a+n);
        do {
            memset(cur,0,sizeof cur);
            prefix[0]=0;
            for(int i=0;i<n;i++)
                prefix[i+1]=prefix[i]+a[i];
            for(int i=1;i<=5;i++){
                for(int j=0;j<(int)imporalign[i].size();j++){
                    int mn=1e9;
                    for(int k=0;k<=n;k++){
                        mn=min(mn,abs(imporalign[i][j]-prefix[k]));
                    }
                    cur[i]+=mn;
                }
            }
            for(int i=1;i<=5;i++){
                if(ans[i]>cur[i]){
                    for(int j=1;j<=5;j++)
                        ans[j]=cur[j];
                    for(int j=0;j<n;j++)
                        anstime[j]=a[j];
                    break;
                }
                else if(ans[i]<cur[i])
                        break;
            }

        }while(next_permutation(a,a+n));
        for(int i=0;i<n;i++)
            printf("%d%s",anstime[i],(i==n-1)?"\n":" ");
        printf("Error: ");
        int tot=0;
        for(int i=1;i<=5;i++)
            tot+=ans[i];
        printf("%d\n",tot);
    }
}