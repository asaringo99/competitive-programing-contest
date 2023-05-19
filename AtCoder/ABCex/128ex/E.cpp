#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , q ;

int main(){
    cin >> n >> q ;
    TP tp[n] ;
    for(int i = 0 ; i < n ; i++){
        int s , t , x ;
        cin >> s >> t >> x ;
        tp[i] = {x,s-x,t-x} ;
    }
    sort(tp,tp+n) ;
    set<int> st ;
    map<int,vector<int>> rem ;
    for(int i = 0 ; i < q ; i++){
        int d ;
        cin >> d ;
        st.insert(d) ;
        rem[d].push_back(i) ;
    }
    int res[q] ;
    for(int i = 0 ; i < n ; i++){
        int x , s , t ;
        tie(x,s,t) = tp[i] ;
        auto it = st.lower_bound(s) ;
        while(*it < t && it != st.end()){
            for(int u : rem[*it]) res[u] = x ;
            st.erase(it++) ;
        }
    }
    for(int u : st){
        for(int v : rem[u]) res[v] = -1 ;
    }
    for(int i = 0 ; i < q ; i++) cout << res[i] << endl ;
}