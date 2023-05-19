#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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

const int SQRT = 447 ;

int n , m , q ;

vector<int> G[202020] , F[202020] ;
bool E[202020] ;
int C[202020] , D[202020] , out[202020] , in[202020] ;

int main(){
    fast_input_output
    cin >> n >> m >> q ;
    rep(i,m){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    rep(i,n) if(G[i].size() > SQRT) E[i] = true ;
    rep(i,n) if(E[i]) for(int u : G[i]) if(E[u]) F[i].push_back(u) ;
    rep(i,n) C[i] = i ;
    rrep(i,1,q+1){
        int x ;
        cin >> x ;
        x-- ;
        if(E[x]) {
            for(int u : F[x]) C[u] = C[x] ;
            out[x] = i ;
            D[x] = C[x] ;
        }
        else{
            for(int u : G[x]) if(E[u]) if(out[u] > in[x]) {
                C[x] = D[u] ;
                in[x] = out[u] ;
            }
            for(int u : G[x]) {
                C[u] = C[x] ;
                in[u] = i ;
            }
            in[x] = i ;
        }
    }
    rep(x,n){
        if(E[x]) continue ;
        for(int u : G[x]) if(E[u]) if(out[u] > in[x]) {
            C[x] = D[u] ;
            in[x] = out[u] ;
        }
    }
    rep(i,n) cout << C[i] + 1 << " " ; cout << endl ;
}