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
int L[55] , A[55] ;

bool f(int k , ll x){
    int cnt = 0 , sum = 0 ;
    rep(i,n){
        sum += L[i] ;
        if(cnt == k) continue;
        if(sum >= x){
            cnt++ ;
            sum = 0 ;
        }
    }
    if(cnt < k) return false ;
    return sum >= x ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> L[i] ;
    rrep(i,1,n){
        ll lef = 0 , rig = 101010 ;
        while(rig - lef > 1){
            ll mid = (lef + rig) / 2 ;
            if(f(i,mid)) lef = mid ;
            else rig = mid ;
        }
    }
}