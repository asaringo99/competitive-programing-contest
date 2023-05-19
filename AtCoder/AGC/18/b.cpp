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

int n , m ;
int A[303][303] ;

bool f(ll x){
    vector<bool> used(m+1,0) ;
    queue<int> que[303] ;
    rep(i,n) rep(j,m) que[i].push(A[i][j]) ;
    while(true){
        unordered_map<int,int> mp ;
        bool ok = true ;
        rep(i,n){
            int v = que[i].front() ;
            while(used[v]){
                que[i].pop() ;
                if(que[i].empty()) return false ;
                v = que[i].front() ;
            }
            mp[v]++ ;
        }
        rrep(i,1,m+1) if(mp[i] > x) ok = false , used[i] = true ;
        if(ok) return true ;
    }
}

int main(){
    cin >> n >> m ;
    rep(i,n) rep(j,m) cin >> A[i][j] ;
    ll lef = 0 , rig = n ;
    while(rig - lef > 1){
        ll mid = (lef + rig) / 2 ;
        if(f(mid)) rig = mid ;
        else lef = mid ;
    }
    cout << rig << endl ;
}