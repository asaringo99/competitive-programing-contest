#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int q ;
priority_queue<ll,vector<ll>,greater<ll>> que ;

int main(){
    cin >> q ;
    ll sum = 0 ;

    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            ll x ;
            cin >> x ;
            que.push(x-sum) ;
        }
        if(t == 2){
            ll x ;
            cin >> x ;
            sum += x ;
        }
        if(t == 3){
            ll val = que.top() ;
            que.pop() ;
            cout << val + sum << endl ;
        }
    }
}