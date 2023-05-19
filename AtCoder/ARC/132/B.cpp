#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int p[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> p[i] ;
    bool cl = true ;
    rep(i,n) if(p[i] != i) cl = false ;

    if(cl){
        cout << 0 << endl ;
        return 0 ;
    }

    if(n == 2){
        cout << 1 << endl ;
        return 0 ;
    }

    bool ok = true ;
    rep(i,n-1){
        if(p[i+1]-p[i]==1) break ;
        if(p[i+1]-p[i]==-1){
            ok = false ;
            break ;
        }
    }
    if(ok){
        int res = 1e8 ;
        int count1 = 0 ;
        rep(i,n) {
            count1 = i ;
            if(p[i] == 1) break ;
        }
        int count2 = n - count1 + 2 ;
        res = min(count1,count2) ;
        cout << res << endl ;
    }
    else{
        int res = 1e8 ;
        int count1 = 0 ;
        rep(i,n) {
            count1 = i ;
            if(p[i] == 1) break ;
        }
        int count2 = count1 + 2 ;
        count1 = n - count1 ;
        res = min(count1,count2) ;
        cout << res << endl ;
    }
}