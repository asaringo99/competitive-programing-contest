#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<bool,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , m , x , k ;
vector<ll> vec[202020] ;
priority_queue<ll> que ;
ll S[202020] ;

int main(){
    cin >> n >> m >> x ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        vec[b].push_back(a) ;
    }
    rep(i,202020){
        sort(vec[i].begin(),vec[i].end(),greater<ll>()) ;
        bool ok = true ;
        for(ll u : vec[i]){
            if(ok) que.push(u+x) ;
            else que.push(u) ;
            ok = false ;
        }
    }
    rep(i,n){
        S[i+1] = S[i] + que.top() ;
        que.pop() ;
    }
    ll res = 0 ;
    cin >> k ;
    rep(i,k) {
        int c ;
        cin >> c ;
        res += S[c] ;
    }
    cout << res << endl ;
}