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

int n , q ;
vector<ll> vec ;
deque<P> deq ;

int main(){
    fast_input_output
    cin >> q ;
    ll sum = 0 ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            ll x , c ;
            cin >> x >> c ;
            deq.push_back(P(x,c)) ;
            sum += x * c ;
        }
        if(t == 2){
            ll c , y ;
            ll res = 0 ;
            cin >> c ;
            while(c > 0){
                auto [x,cnt] = deq.front() ; deq.pop_front() ;
                c -= cnt ;
                sum -= x * cnt ;
                res += x * cnt ;
                y = x ;
            }
            c = abs(c) ;
            if(c != 0) deq.push_front(P(y,c)) ;
            sum += y * c ;
            res -= y * c ;
            cout << res << endl ;
        }
    }
}