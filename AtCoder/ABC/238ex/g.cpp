#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

struct FastPrimeFactorization{
    int n ;
    vector<int> factor ;

    FastPrimeFactorization(int n_){
        n = max(n_,303030) ;
        factor.resize(n,-1) ;
        build() ;
    }

    void build(){
        for(int i = 2 ; i < n ; i++){
            if(factor[i] != -1) continue ;
            for(int j = i ; j < n ; j += i) factor[j] = i ;
        }
    }

    // 素因数分解 20 -> { (5,1), (2,2) }
    vector<P> primeFactorization(int k){
        vector<P> res ;
        while(k != 1){
            int ex = 0 ;
            int d = factor[k] ;
            while(k % d == 0){
                k /= d ;
                ex++ ;
            }
            res.push_back(P(d,ex)) ;
        }
        return res ;
    }

    // 素因数分解の素因数のみ 20 -> { 5, 2 }
    vector<int> primeFactor(int k){
        vector<int> res ;
        while(k != 1){
            int ex = 0 ;
            int d = factor[k] ;
            while(k % d == 0){
                k /= d ;
                ex++ ;
            }
            res.push_back(d) ;
        }
        return res ;
    }
};

int n , q ;
int A[202020] ;
vector<TP> query[1010] ;
vector<int> query1[1010] ;
vector<int> query2[1010] ;
vector<int> query3[1010] ;
vector<P> prime[1010101] ;
vector<int> prime1[1010101] ;
vector<int> prime2[1010101] ;
int cnt[1010101] ;
bool res[202020] ;
bool used[1010101] ;
int sum ;

void e(int& x , int y){
    while(x < y){
        int m = prime1[A[x]].size() ;
        rep(i,m){
            int k = prime1[A[x]][i] ;
            int s = prime2[A[x]][i] ;
            int c = cnt[k] ;
            int t = c + s >= 3 ? c + s - 3 : c + s ;
            if(c == 0 && t != 0) sum++ ;
            else if(c != 0 && t == 0) sum-- ;
            cnt[k] = t ;
        }
        x++ ;
    }
}

void f(int& x , int y){
    while(x > y){
        x-- ;
        int m = prime1[A[x]].size() ;
        rep(i,m){
            int k = prime1[A[x]][i] ;
            int s = prime2[A[x]][i] ;
            int c = cnt[k] ;
            int t = c - s < 0 ? c - s + 3 : c - s ;
            if(c == 0 && t != 0) sum++ ;
            else if(c != 0 && t == 0) sum-- ;
            cnt[k] = t ;
        }
    }
}

void g(int& x , int y){
    while(x < y){
        int m = prime1[A[x]].size() ;
        rep(i,m){
            int k = prime1[A[x]][i] ;
            int s = prime2[A[x]][i] ;
            int c = cnt[k] ;
            int t = c - s < 0 ? c - s + 3 : c - s ;
            if(c == 0 && t != 0) sum++ ;
            else if(c != 0 && t == 0) sum-- ;
            cnt[k] = t ;
        }
        x++ ;
    }
}

void h(int& x , int y){
    while(x > y){
        x-- ;
        int m = prime1[A[x]].size() ;
        rep(i,m){
            int k = prime1[A[x]][i] ;
            int s = prime2[A[x]][i] ;
            int c = cnt[k] ;
            int t = c + s >= 3 ? c + s - 3 : c + s ;
            if(c == 0 && t != 0) sum++ ;
            else if(c != 0 && t == 0) sum-- ;
            cnt[k] = t ;
        }
    }
}

int main(){
    fast_input_output
    cin >> n >> q ;
    int SQRT = 700 ;
    rep(i,n) cin >> A[i] ;
    FastPrimeFactorization fpf(1000001) ;
    fpf.build() ;
    rep(i,n) {
        if(!used[A[i]]) {
            for(P p : fpf.primeFactorization(A[i])){
                auto [a,b] = p ;
                b %= 3 ;
                prime1[A[i]].push_back(a) ;
                prime2[A[i]].push_back(b) ;
            }
        }
        used[A[i]] = true ;
    }
    rep(i,q){
        int l , r ;
        cin >> l >> r ;
        l-- ;
        query[l/SQRT].push_back({r,l,i}) ;
    }
    rep(i,SQRT) {
        sort(query[i].begin() , query[i].end()) ;
        for(TP tp : query[i]){
            auto [a,b,c] = tp;
            query1[i].push_back(a) ;
            query2[i].push_back(b) ;
            query3[i].push_back(c) ;
        }
    }
    
    int l = 0 , r = 0 ;
    rep(i,SQRT){
        int m = query1[i].size() ;
        rep(j,m){
            int rig = query1[i][j] ;
            int lef = query2[i][j] ;
            int id  = query3[i][j] ;
            e(r,rig) ;
            f(r,rig) ;
            g(l,lef) ;
            h(l,lef) ;
            if(sum == 0) res[id] = true ;
            else res[id] = false ;
        }
    }
    rep(i,q){
        if(res[i]) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}