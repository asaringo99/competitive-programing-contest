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
ll A[202020] ;
P X[202020] ;
ll res[202020] ;
priority_queue<ll,vector<ll>,greater<ll>> que ;

int main(){
    fast_input_output
    cin >> n >> q ;
    rep(i,n) cin >> A[i] , que.push(A[i]) ;
    rep(i,q){
        int a ;
        cin >> a ;
        X[i] = P(a,i) ;
    }
    sort(X,X+q) ;
    ll sum = 0 , cnt = 0 ;
    rep(i,n){
        sum += abs(X[0].first - A[i]) ;
    }
    while(!que.empty()){
        ll top = que.top() ;
        if(top <= X[0].first) {
            que.pop() ;
            cnt++ ;
        }
        else break ;
    }
    res[X[0].second] = sum ;
    rrep(i,1,q){
        auto[val, id] = X[i] ;
        ll ans = sum , c = 0 ;
        while(!que.empty()){
            ll top = que.top() ;
            if(top <= val){
                que.pop() ;
                ans += abs(val - top) - abs(top - X[i-1].first) ;
                c++ ;
            }
            else break ;
        }
        ans += cnt * (X[i].first - X[i-1].first) ;
        cnt += c ;
        ans -= (n - cnt) * (X[i].first - X[i-1].first) ;
        res[id] = ans ;
        sum = ans ;
    }
    rep(i,q) cout << res[i] << endl ;
}