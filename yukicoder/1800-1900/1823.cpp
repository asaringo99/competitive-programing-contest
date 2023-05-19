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

int t ;

int main(){
    cin >> t ;
    rep(z,t){
        int n; 
        cin >> n ;
        vector<ll> A(n,0) ;
        ll sum = 0 ;
        rep(i,n) cin >> A[i] , sum += A[i] ;
        if(sum % 3 != 0){
            cout << "No" << endl ;
            continue ;
        }
        sort(A.begin(),A.end()) ;
        if(A[n-1] > sum / 3) cout << "No" << endl ;
        else cout << "Yes" << endl ;
    }
}