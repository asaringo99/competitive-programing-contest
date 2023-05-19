#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll A[202020] , G[202020] ;
map<P,bool> mp ;
set<ll> st ;

int main(){
    cin >> n ;
    ll res = 0 , maxval = 0 , id = -1 ;
    rep(i,n) {
        ll a ;
        cin >> A[i] ;
        res += A[i] ;
        if(A[i] > maxval){
            maxval = A[i] ;
            id = i ;
        }
    }
    rep(i,n) cin >> G[i] , res += G[i] ;
    st.insert(id) ;
    int i = 0 ;
    // cout << res << endl ;
    while(i < n){
        if(A[(i+id+1)%n] > G[(i+id)%n] + G[(i+id+1)%n]){
            // cout << i << " " << id << " " << i + id << endl ;
            // cout << A[(i+id+1)%n] << endl ;
            res -= A[(i+id+1)%n] ;
            i++ ;
        }
        else{
            // cout << i << " " << id << endl ;
            // cout << G[(i+id)%n] << " " << G[(i+id+1)%n] << " " << A[(i+id+2)%n] << endl ;
            res -= G[(i+id)%n] + G[(i+id+1)%n] + A[(i+id+2)%n] ;
            i += 2 ;
        }
        // cout << endl ;
    }
    cout << res << endl ;
}