/**/
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
typedef pair<string, ii> sii;
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
int t,a,d;
char name[25];
vector<sii> list;
bool hai[10];
int totd=0;
int indxt;
int main () { 
    scanf("%d",&t);
    while(t--){
        list.clear();
        indxt++;
        for(int i=0;i<10;i++){
            scanf("%s %d %d",name,&a,&d);
            list.push_back(sii(name,ii(a,d)));
            totd+=d;
        }
        int mxa=-2;
        int mxd=-2;
        sort(list.begin(),list.end());
        for(int i=0;i<10;i++)
            for(int j=i+1;j<10;j++)
                for(int k=j+1;k<10;k++)
                    for(int l=k+1;l<10;l++)
                        for(int m=l+1;m<10;m++){
                            int cura=0;
                            int curd=0;
                            cura+=list[i].second.first;
                            cura+=list[j].second.first;
                            cura+=list[k].second.first;
                            cura+=list[l].second.first;
                            cura+=list[m].second.first;
                            curd+=list[i].second.second;
                            curd+=list[j].second.second;
                            curd+=list[k].second.second;
                            curd+=list[l].second.second;
                            curd+=list[m].second.second;
                            curd=totd-curd;
                            if(cura>mxa){
                                mxa=cura;
                                memset(hai,false,sizeof hai);
                                hai[i]=true;
                                hai[j]=true;
                                hai[k]=true;
                                hai[l]=true;
                                hai[m]=true;
                                mxd=curd;
                            }
                            else if(cura==mxa){
                                if(curd>mxd){
                                    memset(hai,false,sizeof hai);
                                    hai[i]=true;
                                    hai[j]=true;
                                    hai[k]=true;
                                    hai[l]=true;
                                    hai[m]=true;
                                    mxd=curd;
                                }
                            }
                        }
        int x=0;
        printf("Case %d:\n",indxt);
        for(int i=0;i<10;i++){
            if(hai[i]){
                x++;
                printf("%s%s%s",(x==1)?"(":" ",list[i].first.data(),(x==5)?")":",");
            }
        }
        printf("\n");
        x=0;
        for(int i=0;i<10;i++){
            if(!hai[i]){
                x++;
                printf("%s%s%s",(x==1)?"(":" ",list[i].first.data(),(x==5)?")":",");
            }
        }
        printf("\n");
    }
}