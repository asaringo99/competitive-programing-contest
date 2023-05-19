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

ll a , n ;
ll d[10101010] ;

void bfs(){
    rep(i,10101010) d[i] = 1e9 ;
    d[1] = 0 ;
    queue<ll> que ;
    que.push(1) ;
    while(!que.empty()){
        ll v = que.front() ; que.pop() ;
        ll x = v * a ;
        if(x <= 10 * n){
            if(d[x] > d[v] + 1){
                d[x] = d[v] + 1 ;
                que.push(x) ;
            }
        }
        string s = to_string(v) ;
        if(s[s.size() - 1] == '0') continue ;
        ll u = s[s.size() - 1] - '0' ;
        for(int i = 0 ; i < s.size() - 1 ; i++){
            u *= 10 ;
            u += s[i] - '0' ;
        }
        // cout << s << " " << u << endl ;
        if(d[u] > d[v] + 1){
            d[u] = d[v] + 1 ;
            que.push(u) ;
        }
    }
}

int main(){
    cin >> a >> n ;
    bfs() ;
    if(d[n] == 1e9) cout << -1 << endl ;
    else cout << d[n] << endl ;
    
}