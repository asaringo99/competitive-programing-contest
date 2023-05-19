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


int n ;
ll sx , sy , tx , ty ;

ll X[3030] , Y[3030] , R[3030] ;
vector<int> G[3030] ;
bool S[3030] , T[3030] ;

bool d[202020] ;

void bfs(){
    queue<int> que ;
    rep(i,n) if(S[i]) {
        d[i] = true ;
        que.push(i) ;
    }
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        d[v] = true ;
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(!d[u]){
                d[u] = true;
                que.push(u) ;
            }
        }
    }
}

int main(){
    fast_input_output
    cin >> n ;
    cin >> sx >> sy >> tx >> ty ;
    rep(i,n) cin >> X[i] >> Y[i] >> R[i] ;
    rep(i,n){
        ll xs = sx - X[i] , ys = sy - Y[i] , rs = R[i] ;
        ll xt = tx - X[i] , yt = ty - Y[i] , rt = R[i] ;
        if(xs * xs + ys * ys == rs * rs) S[i] = true ;
        if(xt * xt + yt * yt == rt * rt) T[i] = true ;
    }
    rep(i,n) rep(j,n){
        ll x = X[i] , y = Y[i] , r = R[i] ;
        ll nx = X[j] , ny = Y[j] , nr = R[j] ;
        ll dx = abs(nx - x) ;
        ll dy = abs(ny - y) ;
        // cout << dx * dx << " " << dy * dy << " " << abs(r - nr) << endl ;
        if(dx * dx + dy * dy < abs(r - nr)) continue;
        if(dx * dx + dy * dy <= (r + nr) * (r + nr)){
            // cout << i << " " << j << endl ;
            G[i].push_back(j) ;
        }
    }
    bfs() ;
    // rep(i,n) cout << S[i] << " " ; cout << endl ;
    // rep(i,n) cout << T[i] << " " ; cout << endl ;
    // rep(i,n) cout << d[i] << " " ; cout << endl ;
    rep(i,n) if(T[i] && d[i]){
        cout << "Yes" << endl ;
        return 0 ;
    }
    cout << "No" << endl ;
}