#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

const int MAX_N = 1 << 18 ;

template<typename T>
struct BIT {

    //bit[0] = 0
    T bit[MAX_N] ;
    T n ;
    
    BIT(){
        memset(bit,0,sizeof(bit)) ;
    }

    T sum(T i){
        T s = 0 ;
        while(i > 0){
            s += bit[i] ;
            i -= i & -i ; // iから(i & -i)を引く
        }
        return s ;
    }

    void add(T i , T x){
        while(i <= n){
            bit[i] += x ;
            i += i & -i ;
        }
    }
};



int main(){
    int n ;
    cin >> n ;
    cout << bitset<8>((n&-n)) << endl ;
}