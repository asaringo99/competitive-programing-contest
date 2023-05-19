#include <bits/stdc++.h>
using namespace std ;
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
set<int> st[26] ;
string S ;
int q ;

int main(){
    cin >> n >> S >> q ;
    rep(i,n) st[S[i]-'a'].insert(i) ;
    rep(i,q){
        int t ; 
        cin >> t ;
        if(t == 1){
            int k ; char c ;
            cin >> k >> c ;
            k-- ;
            st[S[k]-'a'].erase(k) ; S[k] = c ;
            st[S[k]-'a'].insert(k) ;
        }
        if(t == 2){
            int l , r ;
            cin >> l >> r ;
            l-- ;
            int sum = 0 ;
            rep(j,26){
                auto it = st[j].lower_bound(l) ;
                if(it == st[j].end()) continue ;
                if(*it < r) sum++ ;
            }
            cout << sum << endl ;
        }
    }
}