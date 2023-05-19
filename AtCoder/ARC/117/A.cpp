#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

ll A , B ;

int main(){
    ll cnt = 0 ;
    cin >> A >> B ;
    vector<ll> res ;
    bool ok = true ;
    if(A < B) ok = false ;
    for(int i = 1 ; i <= max(A,B) ; i++) {
        if(ok) res.push_back(i) ;
        else res.push_back(-i) ;
        if(i >= min(A,B)) cnt += i ;
    }
    for(int i = 1 ; i <= min(A,B) ; i++){
        if(i == min(A,B)) {
            if(ok) res.push_back(-1 * cnt) ;
            else res.push_back(cnt) ;
            break ;
        }
        if(ok) res.push_back(-1 * i) ;
        else res.push_back(i) ;
    }
    for(ll u : res) cout << u << " " ;
    cout << endl ;
}