#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

int n , x , y , z ;
P A[1010] , B[1010] , C[1010] ;
bool used[1010] ;

int main(){
    fast_input_output
    cin >> n >> x >> y >> z ;
    rep(i,n) cin >> A[i].first , A[i].second = -i ;
    rep(i,n) cin >> B[i].first , B[i].second = -i ;
    rep(i,n){
        C[i].first = A[i].first + B[i].first ;
        C[i].second = -i ;
    }
    sort(A,A+n,greater<P>()) ;
    sort(B,B+n,greater<P>()) ;
    sort(C,C+n,greater<P>()) ;
    rep(i,n){
        if(x == 0) break ;
        auto[v,id] = A[i] ;
        id = -id ;
        used[id] = true ;
        x-- ;
    }
    rep(i,n){
        if(y == 0) break ;
        auto[v,id] = B[i] ;
        id = -id ;
        if(used[id]) continue;
        used[id] = true ;
        y-- ;
    }
    rep(i,n){
        if(z == 0) break ;
        auto[v,id] = C[i] ;
        id = -id ;
        if(used[id]) continue;
        used[id] = true ;
        z-- ;
    }
    rep(i,n) if(used[i]) cout << i + 1 << endl ;
}