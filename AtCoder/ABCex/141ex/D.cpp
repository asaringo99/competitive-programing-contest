#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

priority_queue<ll> que ;

int main(){
    cin >> n >> m ;
    ll res = 0 ;
    rep(i,n){
        ll a ;
        cin >> a ;
        que.push(a) ;
        res += a ;
    }
    while(m > 0){
        ll a = que.top() ; que.pop() ; 
        res -= (a - a/2) ;
        a /= 2 ;
        que.push(a) ;
        m-- ;
    }
    cout << res << endl ;
}