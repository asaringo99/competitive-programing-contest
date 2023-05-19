#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
ll p ;

ll A[45] ;
vector<ll> X[45] ;

int main(){
    cin >> n >> k >> p ;
    rep(i,n) cin >> A[i] ;
    int n2 = n / 2 ;
    for(int i = 0 ; i < (1 << n2) ; i++){
        int count = 0 ;
        ll val = 0 ;
        for(int j = 0 ; j < n2 ; j++){
            if(i >> j & 1){
                count++ ;
                val += A[j] ;
            }
        }
        if(val > p || count > k) continue ;
        X[count].push_back(val) ;
    }
    ll res = 0 ;
    rep(i,k+1) sort(X[i].begin(),X[i].end()) ;
    for(int i = 0 ; i < 1 << (n - n2) ; i++){
        int count = 0 ;
        ll val = 0 ;
        for(int j = 0 ; j < (n - n2) ; j++){
            if(i >> j & 1){
                count++ ;
                val += A[n2 + j] ;
            }
        }
        if(val > p || count > k) continue ;
        int t = k - count ;
        ll tmp = p - val ;
        auto it = upper_bound(X[t].begin(),X[t].end(),tmp) ;
        res += it - X[t].begin() ;
    }
    cout << res << endl ;
}