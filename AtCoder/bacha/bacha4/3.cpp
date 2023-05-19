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
deque<ll> que ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        que.push_back(a) ;
    }
    ll res = 0 ;
    while(que.size() >= 3){
        ll f1 = que.front() ; que.pop_front() ;
        ll f2 = que.front() ; que.pop_front() ;
        ll val_front = f1 * 2 + f2 + 1 ;
        que.push_front(f2) ;
        que.push_front(f1) ;
        ll b1 = que.back() ; que.pop_back() ;
        ll b2 = que.back() ; que.pop_back() ;
        ll val_back = b1 * 2 + b2 + 1 ;
        que.push_back(b2) ;
        que.push_back(b1) ;
        if(val_front > val_back) {
            res += val_back ;
            que.pop_back() ;
            que.pop_back() ;
            que.back() += b1 + b2 + 2 ;
        }
        else{
            res += val_front ;
            que.pop_front() ;
            que.pop_front() ;
            que.front() += f1 + f2 + 2 ;
        }
    }
    cout << res << endl ;
}