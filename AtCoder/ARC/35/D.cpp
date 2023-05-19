#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1 << 18 ;

template<typename T>
struct SegmentTree{
    int n ;
    T dat[2 * MAX_N - 1] ;
    SegmentTree(int n_){
        n = 1 ;
        while(n < n_) n *= 2 ;
        memset(dat,0,sizeof(dat)) ;
    }
    void add(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = dat[2*k+1] + dat[2*k+2] ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 0 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return lef + rig ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

double logfac[2020202] ;

void init(){
    for(int i = 1 ; i < 2020202 ; i++){
        logfac[i] = logfac[i-1] + log(i) ;
    }
}

int n , q ;
P A[202020] ;

int main(){
    init() ;
    cin >> n ;
    SegmentTree<double> SegTree(202020) ;
    rep(i,n) cin >> A[i].first >> A[i].second ;
    rrep(i,1,n){
        int dx = A[i].first - A[i-1].first , dy = A[i].second - A[i-1].second ;
        SegTree.add(i,logfac[dx+dy] - logfac[dx] - logfac[dy]) ;
    }
    cin >> q ;
    rep(i,q){
        int t , k , a , b , x , y ;
        cin >> t ; 
        if(t == 1){
            cin >> k >> a >> b ;
            k-- ;
            A[k] = P(a,b) ;
            if(k != 0){
                int dx = A[k].first - A[k-1].first , dy = A[k].second - A[k-1].second ;
                SegTree.add(k,logfac[dx+dy] - logfac[dx] - logfac[dy]) ;
            }
            if(k != n - 1){
                int dx = A[k+1].first - A[k].first , dy = A[k+1].second - A[k].second ;
                SegTree.add(k+1,logfac[dx+dy] - logfac[dx] - logfac[dy]) ;
            }
        }
        if(t == 2){
            cin >> a >> b >> x >> y ;
            double fir = SegTree.query(a,b) ;
            double sec = SegTree.query(x,y) ;
            if(fir > sec) cout << "FIRST" << endl ;
            else cout << "SECOND" << endl ;
        }
    }
}