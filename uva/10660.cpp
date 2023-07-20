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
int t,n,x,y,p,a,b,c,d,e;
int dist(int x,int y,int xx,int yy){
    return (abs(x-xx)+abs(y-yy)); 
}
int main () { 
    int indx=0;
    scanf("%d",&t);
    while(t--){
        int g[25][25];
        memset(g,0,sizeof g);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&x,&y,&p);
            g[x][y]=p;
        }
        vi offices;
        int ans=1e9;
        for(int i=0;i<25;i++)
            for(int j=i+1;j<25;j++)
                for(int k=j+1;k<25;k++)
                    for(int l=k+1;l<25;l++)
                        for(int m=l+1;m<25;m++){
                            int sum=0;
                            for(int r=0;r<5;r++)
                                for(int ce=0;ce<5;ce++){
                                    // dbg(i,j,k,l,m,r,c);
                                    a=dist(i/5,i%5,r,ce)*g[r][ce];
                                    b=dist(j/5,j%5,r,ce)*g[r][ce];
                                    c=dist(k/5,k%5,r,ce)*g[r][ce];
                                    d=dist(l/5,l%5,r,ce)*g[r][ce];
                                    e=dist(m/5,m%5,r,ce)*g[r][ce];
                                    sum+=min(min(a,min(b,c)),min(d,e));
                                }
                            if(sum<ans){
                                ans=sum;
                                offices.clear();
                                offices.push_back(i);
                                offices.push_back(j);
                                offices.push_back(k);
                                offices.push_back(l);
                                offices.push_back(m);

                            }
                        }
        sort(offices.begin(),offices.end());
        dbg(offices);
        for(int i=0;i<5;i++)
            printf("%d%s",offices[i],(i==4)?"\n":" ");
    }
}   