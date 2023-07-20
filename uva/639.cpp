// 639
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
const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { -1, 0, 0, 1 };
int n,ans;
char cb[5][5];
bool choosen[5][5];
bool inside(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool canPlace(int x, int y) {
    if (cb[x][y] == 'X') return false;
    for(int i=0;i<4;i++){
        int xx = x, yy = y;
        while (inside(xx, yy)) {
            if (cb[xx][yy] == 'X') break;
            if (choosen[xx][yy]) return false;
            xx += dx[i]; yy += dy[i];
        }
    }
    return true;
}

void dfs(int x,int y,int cur){
    if(y==n)
        {x++;y=0;}
    ans=max(ans,cur);
    if(x>=n)return;
    for(int i=x;i<n;i++){
        for(int j=y;j<n;j++){
            dfs(i,j+1,cur);
            if(canPlace(i,j)){
                choosen[i][j]=true;
                dfs(i,j+1,cur+1);
                choosen[i][j]=false;
            }
        }
        y=0;
    }
}
int main () { 
    while(scanf("%d",&n),n){
        ans=0;
        for(int i=0;i<n;i++)
            scanf("%s",cb[i]);
        memset(choosen,false,sizeof choosen);
        dfs(0,0,0);
        printf("%d\n",ans);
    }
}