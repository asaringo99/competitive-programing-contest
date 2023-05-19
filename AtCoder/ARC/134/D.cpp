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
ll A[202020] ;
P B[202020] ;

int main(){
    cin >> n ;
    rep(i,2*n) cin >> A[i] ;
    rep(i,n) B[i] = P(A[i],i) ;
    sort(B,B+n) ;
    vector<ll> arr ;
    P res = P(1e10,1e10) ;
    rep(i,n){
        ll val = B[i].first , id = B[i].second ;
        ll wal = A[id+n] ;
        chmin(res,P(val,wal)) ;
    }
    arr.push_back(res.first) ;
    arr.push_back(res.second) ;

    vector<ll> vec , adr ;
    int i = 0 , j = 0 ;
    bool ok = true , gg = false , gd = false ;
    while(i < n){
        int val = B[i].first , id = B[i].second ;
        if(ok){
            vec.push_back(val) ;
            adr.push_back(A[id+n]) ;
            ok = false ;
            j = id ;
        }
        else{
            if(id > j && val < adr[0]){
                vec.push_back(val) ;
                adr.push_back(A[id+n]) ;
                j = id ;
            }
            if(!gg && !gd && id > j && val == adr[0]){
                gg = true ;
                rep(t,adr.size()-1){
                    if(adr[t] == adr[0]) continue ;
                    if(adr[t] < adr[0]) break ;
                    if(adr[t] > adr[0]){
                        gd = true ;
                        break ;
                    }
                }
            }
            if(gd && id > j && val == adr[0]){
                vec.push_back(val) ;
                adr.push_back(A[id+n]) ;
                j = id ;
            }
        }
        i++ ;
    }
    for(int u : adr) vec.push_back(u) ;
    if(arr[1] <= vec[1]) cout << arr[0] << " " << arr[1] << endl ;
    else for(int u : vec) cout << u << " " ; cout << endl;
}