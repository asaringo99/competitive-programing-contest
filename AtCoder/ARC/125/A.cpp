#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int zs , zg , os , og ;
int S[200007] , T[200007];
set<int> setz , seto ;

int main(){
    cin >> n >> m ;
    rep(i,n) {
        cin >> S[i] ;
        setz.insert(S[i]) ;
    }
    rep(i,m) {
        cin >> T[i] ;
        seto.insert(T[i]) ;
    }
    rep(i,n){
        if(S[i] == 0) zg = i ;
        if(S[i] == 1) og = i ;
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(S[i] == 0) zs = i ;
        if(S[i] == 1) os = i ;
    }
    bool fa = true ;
    for(int u : seto) if(setz.count(u) == 0) fa = false ;
    if(!fa){
        cout << -1 << endl ;
        return 0 ;
    }
    ll res = 0 ;
    if(S[0] == T[0]){
        if(S[0] == 0 && seto.size() == 2) res += min(os,n-og) ;
        if(S[0] == 1 && seto.size() == 2) res += min(zs,n-zg) ;
        if(seto.size() == 1) res++ ;
        rep(i,m-1){
            if(T[i] == T[i+1]) res++ ;
            else res += 2 ;
        }
        cout << res << endl ;
        return 0 ;
    }
    if(S[0] != T[0]){
        res++ ;
        if(T[0] == 0) res += min(zs,n-zg) ;
        else res += min(os,n-og) ;
        rep(i,m-1){
            if(T[i] == T[i+1]) res++ ;
            else res += 2 ;
        }
        cout << res << endl ;
        return 0 ;
    }
}