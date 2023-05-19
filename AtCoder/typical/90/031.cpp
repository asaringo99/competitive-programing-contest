#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int mex[2007] ;
int W[60] , B[60] , V[60] ;

void MEX(){
    set<int> st ;
    rrep(i,1,2001) st.insert(i) ;
    mex[1] = 0 ;
    rrep(i,2,2001){
        if(i % 2 != 0){
            int val = mex[i/2] ;
            st.insert(val) ;
        }
        auto it = st.begin() ;
        mex[i] = *it ;
        st.insert(*it) ;
    }
}

int main(){
    MEX() ;
    cin >> n ;
    rep(i,n) cin >> W[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n) V[i] = W[i] * (W[i] + 1) / 2 + B[i] ;
    int res = 0 , sum = 0 ;
    rep(i,n){
        sum += W[i] ;
        res ^= mex[V[i]] ;
    }
    if(res != 0 && sum % 2 == 0) cout << "First" << endl ;
    if(res != 0 && sum % 2 != 0) cout << "Second" << endl ;
    if(res == 0 && sum % 2 == 0) cout << "Second" << endl ;
    if(res == 0 && sum % 2 != 0) cout << "First" << endl ;
}