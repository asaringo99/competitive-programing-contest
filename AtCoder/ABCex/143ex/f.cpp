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

int n ;
int A[303030] , S[303030] ;
int res[303030] ;
vector<int> vec ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        a-- ;
        A[a]++ ;
    }
    rep(i,n) if(A[i] > 0) vec.push_back(A[i]) ;
    sort(vec.begin(),vec.end()) ;
    int m = vec.size() ;
    rep(i,m) S[i+1] = S[i] + vec[i] ;
    rrep(i,1,n+1){
        auto it = lower_bound(vec.begin(),vec.end(),i) ;
        int id = it - vec.begin() ;
        ll sum = (m - id) * i + S[id] ;
        chmax(res[sum / i],i) ;
    }
    for(int i = n ; i > 0 ; i--){
        if(res[i] > res[i-1]) res[i-1] = res[i] ;
    }
    rrep(i,1,n+1) cout << res[i] << endl ;
}