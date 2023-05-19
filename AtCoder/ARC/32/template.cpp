#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
typedef tuple<ll,ll,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

struct SegmentTree{
    int n ;
    vector<P> dat ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        dat.resize(2*n-1,P(0,0)) ;
    }
    void update(int k , P x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = max(dat[2*k+1],dat[2*k+2]) ;
        }
    }

    P sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return P(0,0) ;
        if(a <= l && r <= b) return dat[k] ;
        P lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        P rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return max(lef,rig) ;
    }

    P query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
} ;

TP A[101010] ;
P dp[1010101] ;
int pre[1010101] ;

int main(){
    cin >> n ;
    int v = -1 ;
    rep(i,n){
        int a , b ;
        cin >> a >> b ;
        A[i] = {b,a,-(i+1)} ;
        v = max(v,b) ;
    }
    sort(A,A+n,greater<TP>()) ;
    SegmentTree SegTree(v+1) ;
    rep(i,1010101) dp[i] = P(0,0) , pre[i] = -10 ;
    P val = P(0,-1) ;
    rep(i,n){
        int a , b , id ;
        tie(b,a,id) = A[i] ;
        P p = SegTree.query(b,v+1) ;
        if(dp[a] < P(p.first+1,id)){
            dp[a] = P(p.first+1,id) ;
            pre[-id] = -p.second ;
            SegTree.update(a,dp[a]) ;
            val = max(val,dp[a]) ;
        }
    }
    vector<int> vec ;
    int id = -val.second ;
    while(id != 0){
        vec.push_back(id) ;
        id = pre[id] ;
    }
    cout << vec.size() << endl ;
    rep(i,vec.size()) {
        if(i == vec.size() - 1) cout << vec[i] << endl;
        else cout << vec[i] << " " ;
    }
}