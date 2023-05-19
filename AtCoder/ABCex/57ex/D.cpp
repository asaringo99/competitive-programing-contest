#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , a , b ;
ll V[100] ;
ll comb[100][100] ;
set<ll> st ;

void pascal(){
    comb[0][0] = 1 ;
    rep(i,80) rep(j,80){
        comb[i+1][j] += comb[i][j] ;
        comb[i+1][j+1] += comb[i][j] ;
    }
}

int main(){
    pascal() ;
    cin >> n >> a >> b ;
    rep(i,n) cin >> V[i] ;
    sort(V,V+n,greater<ll>()) ;
    rep(i,a) st.insert(V[i]) ;
    ll sum = 0 ;
    rep(i,a) sum += V[i] ;
    cout << fixed << setprecision(15) << (double) sum / a << endl ;
    sort(V,V+n) ;
    if(st.size() == 1){
        ll v = V[n-1] ;
        int cnt = upper_bound(V,V+n,v) - lower_bound(V,V+n,v) ;
        ll res = 0 ;
        rrep(i,a,b+1) res += comb[cnt][i] ;
        cout << res << endl ;
        return 0 ;
    }
    ll v = V[n-a] ;
    int id = upper_bound(V,V+n,v) - V ;
    int tmp = a - (n - id);
    int cnt = upper_bound(V,V+n,v) - lower_bound(V,V+n,v) ;
    cout << comb[cnt][tmp] << endl ;
}