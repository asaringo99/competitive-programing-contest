#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] ;
unordered_map<ll,ll> mp ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll res = 0 ;
    rep(i,n){
        res += mp[A[i] - i] ;
        mp[-i - A[i]]++ ;
    }
    cout << res << endl ;
}