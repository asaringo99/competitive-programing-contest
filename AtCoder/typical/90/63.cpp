#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int H , W ;
int P[10][10007] ;

int main(){
    cin >> H >> W ;
    rep(i,H) rep(j,W) cin >> P[i][j] ;
    int res = 0 ;
    rep(i,1<<H){
        bool target[H] ;
        memset(target,0,sizeof(target)) ;
        map<int,int> mp ;
        int count = 0 ;
        rep(j,H) if(i>>j&1){
            target[j] = true ;
            count++ ;
        }
        rep(j,W) {
            set<int> st ;
            rep(k,H){
                if(!target[k]) continue ;
                st.insert(P[k][j]) ;
            }
            if(st.size() != 1) continue ;
            auto it = st.begin() ;
            mp[*it] += count ;
        }
        int val = 0 ;
        for(auto it : mp) val = max(val,it.second) ;
        res = max(res,val) ;
    }
    cout << res << endl ;
}