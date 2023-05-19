#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
int A[101010] ;

int prime[101010] ;
bool X[101010] ;

void ertstns(){
    memset(prime,-1,sizeof(prime)) ;
    prime[0] = prime[1] = 1 ;
    for(int i = 2 ; i < 101010 ; i++){
        if(prime[i] == -1){
            for(int j = i ; j < 101010 ; j += i){
                prime[j] = i ;
            }
        }
    }
}

void f(){
    rep(i,n){
        int v = A[i] ;
        while(v != 1){
            X[prime[v]] = true ;
            v /= prime[v] ;
        }
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) cin >> A[i] ;
    ertstns() ;
    f() ;
    vector<int> res ;
    rrep(i,1,m+1){
        bool ok = true ;
        int v = i ;
        while(v != 1){
            if(X[prime[v]]) ok = false ;
            v /= prime[v] ;
        }
        if(ok) res.push_back(i) ;
    }
    cout << res.size() << endl ;
    rep(i,res.size()) cout << res[i] << endl ;
}