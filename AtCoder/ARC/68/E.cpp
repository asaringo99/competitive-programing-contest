#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int MAX_N = 1 << 18 ;

template <typename T>
struct BinaryIndexedTree {
    int n;             // 要素数
    T bit[2][MAX_N];  // データの格納先
    BinaryIndexedTree(int n_) {
        n = n_ + 1 ;
        memset(bit,0,sizeof(bit)) ;
    }

    void add_sub(int p , int i , T x) {
        for (int idx = i ; idx < n ; idx += (idx & -idx)) {
            bit[p][idx] += x ;
        }
    }
    void add(int l , int r , T x) {  // [l,r) に加算
        add_sub(0 , l , -x * (l - 1)) ;
        add_sub(0 , r , x * (r - 1)) ;
        add_sub(1 , l , x) ;
        add_sub(1 , r , -x) ;
    }

    T sum_sub(int p, int i) {
        T s = 0 ;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) {
        return sum_sub(0, i) + sum_sub(1, i) * i ;
    }
};

int n , m ;
vector<P> sec[303030] ;
int res[101010] ;

int main(){
    cin >> n >> m ;
    BinaryIndexedTree<ll> BIT(m+1);
    rep(i,n){
        int l , r ;
        cin >> l >> r ;
        sec[r-l+1].push_back(P(l,r)) ;
    }
    int count = 0 ;
    rrep(i,1,m+1){
        int res = n - count ;
        for(int j = i ; j <= m ; j += i) res += BIT.sum(j) - BIT.sum(j-1) ;
        cout << res << endl ;
        for(P p : sec[i]){
            int l = p.first , r = p.second ; 
            r++ ;
            BIT.add(l,r,1) ;
            count++ ;
        }
    }
}