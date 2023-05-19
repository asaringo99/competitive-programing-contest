#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int MAX_N = 1 << 20 ;

template<typename T>
struct SegmentTree{
    int n ;
    T dat[2 * MAX_N - 1] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
    }
    void update(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n ;
vector<ll> H[101010] ;
ll dp[101010] ;

int main(){
    cin >> n ;
    rep(i,n){
        int w , h ;
        cin >> w >> h ;
        H[h].push_back(w) ;
    }
    rep(i,101010) sort(H[i].begin(),H[i].end(),greater<ll>()) ;
    SegmentTree<ll> SegTree(101010) ;
    for(int h = 100000 ; h >= 1 ; h--){
        queue<pair<ll,ll>> que ;
        for(int w : H[h]){
            ll val = SegTree.query(w+1,100001) ;
            dp[w] = max(dp[w],val+1) ;
            que.push(pair<ll,ll>(w,dp[w])) ;
        }
        while(!que.empty()){
            pair<ll,ll> p = que.front() ; que.pop() ;
            SegTree.update(p.first,p.second) ;
        }
    }
    ll res = 0 ;
    rep(i,101010) res = max(res,dp[i]) ;
    cout << res << endl ;
}