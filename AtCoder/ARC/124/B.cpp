#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[3000],B[3000] ;
set<int> st ;
set<int> bb ;
vector<int> ans ;

int main(){
    cin >> n;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    sort(B,B+n) ;
    rep(i,n) st.insert(A[0]^B[i]) ;
    rep(i,n){
        
    }
    for(int u : st){
        bool ok = true ;
        rep(i,n){
            int val = u ^ A[i] ;
            auto it = lower_bound(B,B+n,val) ;
            if(*it != val) ok = false ;
        }
        if(ok) ans.push_back(u) ;
    }
    cout << (ans.size()) << endl ;
    for(int u : ans) cout << u << endl ;
}