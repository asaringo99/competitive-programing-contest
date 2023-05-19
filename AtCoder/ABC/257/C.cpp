#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;
P W[202020] ;
map<int,int> T ;

int main(){
    fast_input_output
    cin >> n >> S ;
    int child = 0 , adult = 0 ;
    rep(i,n) {
        int w ;
        cin >> w ;
        W[i] = P(w,i) ;
        if(S[i] == '1') adult++ ;
        else child++ ;
    }
    sort(W,W+n) ;
    int x = 0 , y = 0 , res = min(child,adult) ;
    int i = 0 ;
    while(i < n){
        auto [w,id] = W[i] ;
        while(i < n && w == W[i].first){
            if(S[W[i].second] == '1') x++ ;
            else y++ ;
            i++ ;
        }
        chmin(res,x+child-y) ;
    }
    cout << n - res << endl ;
}