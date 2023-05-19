#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<ll,ll,ll> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1 << 20 ;

int n , q ;
ll C[101010] ;
ll d[101010] ;
vector<int> G[101010] ;

int in[202020] , out[202020] ;
int dat[2 * MAX_N - 1] ;

struct SegTree{
    int n ;
    SegTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
        for(int i = 0 ; i < n_ ; i++){
            if(i != 0 && in[i] == 0) continue ;
            dat[in[i]+n-1] = C[i] ;
        }
        for(int i = n - 2 ; i >= 0 ; i--) dat[i] = dat[i*2+1] ^ dat[i*2+2] ;
    }
    void add(int v , int y){
        v += n - 1 ;
        dat[v] ^= y ;
        while(v > 0){
            v = (v - 1) / 2 ;
            dat[v] = dat[2*v+1] ^ dat[2*v+2] ;
        }
    }

    int sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        int lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        int rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef ^ rig ;
    }

    int query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int sec ;
void dfs(int v , int prev){
    in[v] = sec++ ;
    for(int i = 0 ; i < G[v].size() ; i++){
        int u = G[v][i] ;
        if(u == prev) continue ;
        dfs(u,v) ;
    }
    out[v] = sec++ ;
}

int main(){
    cin >> n >> q ;
    rep(i,n) cin >> C[i] ;
    rep(i,n-1){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    dfs(0,-1) ;
    SegTree seg(out[0]) ;
    rep(i,q){
        int t , x , y ;
        cin >> t >> x >> y ;
        x-- ;
        if(t == 1){
            seg.add(in[x],y) ;
        }
        if(t == 2){
            cout << seg.query(in[x],out[x]) << endl ;
        }
    }
}