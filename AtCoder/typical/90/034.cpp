#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
int A[100007] ;
set<int> res ;
map<int,int> tmp ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    int lef = 0 , rig = 0 , ans = 0 ;
    while(rig < n){
        while(rig < n && res.size() <= k){
            if(res.count(A[rig]) == 0 && res.size() == k) break ;
            res.insert(A[rig]) ;
            tmp[A[rig]]++ ;
            rig++ ;
        }
        ans = max(ans,rig-lef) ;
        while(res.size() == k){
            tmp[A[lef]]-- ;
            if(tmp[A[lef]] == 0) res.erase(A[lef]) ;
            lef++ ;
        }
    }
    cout << ans << endl ;
}