#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;

int main(){
    cin >> n ;
    int sum = 0 ;
    for(int i = n - 1 ; i > 0 ; i -= 2) sum += i ;
    cout << sum << endl ;
    int tmp = 1 , beg = 2 , end = n ;
    while(end >= beg){
        while(beg <= end){
            cout << tmp << " " << beg << endl ;
            beg++ ;
        }
        tmp++ ;
        beg = tmp + 1 ;
        end-- ;
    }
}