#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , a , b ;
vector<int> res ;

int main(){
    cin >> n >> a >> b ;
    if(a + b - 1 > n){
        cout << -1 << endl ;
        return 0 ;
    }
    bool ok = true ;
    if(b > a) ok = false , swap(a,b) ;
    int i = 0 , cnt = 0 ;
    while(true){
        int k = n - (a - cnt) ;
        if(k <= i){
            if(i - b <= k){
                cout << k - i + b << endl ;
                for(int j = 0 ; j < k - i + b ; j++) res.pop_back() ;
                for(int j = k ; k < n + 1 ; j++) res.push_back(j) ;
                break;
            }
            else{
                cout << -1 << endl ;
                return 0 ;
            }
        }
        for(int j = i + b ; j > i ; j--) res.push_back(j) ;
        i += b ;
        cnt++ ;
    }
    if(ok) reverse(res.begin(),res.end()) ;
    rep(i,res.size()) cout << res[i] << endl ;
}