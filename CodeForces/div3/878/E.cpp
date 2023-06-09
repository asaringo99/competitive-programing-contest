#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

struct SegmentTree{
    int n , n_;
    vector<bool> dat;

    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2;
        dat.resize(2 * n - 1, false);
    }
    void update(int k , bool x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = (dat[2*k+1] & dat[2*k+2]) ;
        }
    }
    bool sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1 ;
        if(a <= l && r <= b) return dat[k] ;
        bool lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        bool rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return (lef & rig) ;
    }
    bool query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int z ;

void solve(){
    int n;
    string S, T;
    cin >> S >> T;
    n = S.size();
    SegmentTree segtree(n);
    rep(i,n) segtree.update(i,(S[i]==T[i]));
    int t, q;
    cin >> t >> q;
    queue<pair<int,int>> que;
    int tim = 0;
    rep(i,q){
        if(!que.empty()){
            auto[v, id] = que.front();
            if(v == tim) {
                que.pop();
                if(S[id] == T[id]) segtree.update(id,true);
                else segtree.update(id,false);
            }
        }
        int type;
        cin >> type;
        if(type == 1){
            int k;
            cin >> k;
            k--;
            segtree.update(k,true);
            que.push({t+tim, k});
        }
        if(type == 2){
            int a, b, v, u;
            cin >> a >> v >> b >> u;
            v--; u--;
            if(a == 1 && b == 1) swap(S[v], S[u]);
            if(a == 1 && b == 2) swap(S[v], T[u]);
            if(a == 2 && b == 1) swap(T[v], S[u]);
            if(a == 2 && b == 2) swap(T[v], T[u]);
            if(S[v] == T[v]) segtree.update(v, true);
            if(S[v] != T[v]) segtree.update(v, false);
            if(S[u] == T[u]) segtree.update(u, true);
            if(S[u] != T[u]) segtree.update(u, false);
        }
        if(type == 3){
            bool res = segtree.query(0,n);
            if(res) cout << "YES" << endl ;
            else cout << "NO" << endl ;
        }
        tim++;
    }
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}