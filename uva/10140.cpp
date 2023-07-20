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
vi primes;
bitset<1000020> bs;
void sieve(){
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=1000000;i++)if(bs[i]){
        for(ll j=i*i;j<=1000000;j+=i)
            bs[j]=0;
        primes.push_back((int)i);
    }
}
bool isPrime(ll N){
    if(N<=1000000)return bs[N];
    for(int i=0;i<(int)primes.size();i++){
        if (primes[i]> sqrt(N))return true;
        if(N%primes[i]==0)return false;
    }
    return true;
}
ll L,U;
int main () {
   sieve();
   while(scanf("%lld %lld",&L,&U)==2){
    pair<ll,ll> c,d;
    ll fdist=-1;
    ll cdist=-1;
    ll prevprime=-1;
    for(ll i=L;i<=U;i++){
        if(isPrime(i)){
            if(prevprime!=-1){
                if(cdist==-1 || (i-prevprime)<cdist){
                    cdist=i-prevprime;
                    c={prevprime,i};
                }
                if(fdist==-1 || (i-prevprime)>fdist){
                    fdist=i-prevprime;
                    d={prevprime,i};
                }
            }
            prevprime=i;
        }
    }
    if(cdist!=-1)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",c.first,c.second,d.first,d.second);
    else 
        printf("There are no adjacent primes.\n");
   }
}