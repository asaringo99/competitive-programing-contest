#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b) ;
#define chmax(a,b) a = max(a,b) ;
#define bit_count(x) __builtin_popcountll(x)
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int H , W ;
char C[707][707] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> C[i][j] ;
    rep(i,H){
        rep(j,W){
            set<char> st = {'1','2','3','4','5'} ;
            if(C[i][j] == '.'){
                if(i - 1 >= 0) st.erase(C[i-1][j]);
                if(i + 1 < H)  st.erase(C[i+1][j]);
                if(j - 1 >= 0) st.erase(C[i][j-1]);
                if(j + 1 < W)  st.erase(C[i][j+1]);
                auto it = st.begin() ;
                C[i][j] = *it ;
            }
        }
    }
    rep(i,H){
        rep(j,W){
            cout << C[i][j] ;
        }
        cout << endl;
    }
}