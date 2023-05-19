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
ll A[101] ;
map<ll,int> mp , M ;
set<ll> st , S ;
vector<ll> vec , res ;
bool ok = false ;

void dfs(ll x){
    if(ok) return ;
    if(vec.size() == n) {
        for(ll u : vec) cout << u << " " ; cout << endl ;
        ok = true ;
        return ;
    }
    auto it = S.lower_bound(2LL * x) ;
    if(it != S.end() && *it == 2LL * x) {
        M[2LL*x]-- ;
        if(M[2LL*x] == 0) S.erase(2LL*x) ;
        vec.push_back(2LL*x) ;
        dfs(2LL*x) ;
        vec.pop_back() ;
        S.insert(2LL*x) ;
        M[2LL*x]++ ;
    }
    if(x % 3 == 0){
        auto it = S.lower_bound(x / 3) ;
        if(it != S.end() && *it == x / 3) {
            M[x / 3]-- ;
            if(M[x / 3] == 0) S.erase(x / 3) ;
            vec.push_back(x / 3) ;
            dfs(x / 3) ;
            vec.pop_back() ;
            S.insert(x / 3) ;
            M[x / 3]++ ;
        }
    }
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] , M[A[i]]++ , S.insert(A[i]) ;
    sort(A,A+n) ;
    rep(i,n){
        if(ok) break ;
        res = {} ;
        M[A[i]]-- ;
        if(M[A[i]] == 0) S.erase(A[i]) ;
        vec.push_back(A[i]) ;
        dfs(A[i]) ;
        vec.pop_back() ;
        S.insert(A[i]) ;
        M[A[i]]++ ;
    }
}