#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll n , k ;
ll digit[101] , x[101] ;
vector<int> K ;

ll f(){
    ll res = 0 ;
    for(int i = K.size() - 1 ; i >= 0 ; i--){
        rep(j,K[i]) if(digit[j] * 2 < n) x[j]++ ;
        ll sum = 0 ;
        rep(j,60) {
            if(x[j] == 0) sum += digit[j] * (1LL << j) ;
            if(x[j] == 1) sum += (n - digit[j]) * (1LL << j) ;
        }
        res = max(res,sum) ;
        rep(j,K[i]) if(digit[j] * 2 < n) x[j]-- ;
        x[K[i]]++ ;
    }
    ll sum = 0 ;
    rep(j,60) {
        if(x[j] == 0) sum += digit[j] * (1LL << j) ;
        if(x[j] == 1) sum += (n - digit[j]) * (1LL << j) ;
    }
    res = max(res,sum) ;

    return res ;
}

int main(){
    cin >> n >> k ;
    rep(i,60) if(k >> i & 1) K.push_back(i) ;
    rep(i,n){
        ll a ;
        cin >> a ;
        rep(j,60) if(a >> j & 1) digit[j]++ ;
    }
    cout << f() << endl ;
}