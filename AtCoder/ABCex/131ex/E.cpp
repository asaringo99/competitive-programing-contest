#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k ;

int main(){
    cin >> n >> k ;
    int sum = (n - 1) * (n - 2) / 2 ;
    if(sum < k){
        cout << -1 << endl ;
        return 0 ;
    }
    vector<P> res ;
    for(int i = 1 ; i < n ; i++){
        res.push_back(P(0,i)) ;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(sum == k) break ;
            res.push_back(P(i,j)) ;
            sum-- ;
        }
    }
    cout << res.size() << endl ;
    for(P p : res){
        cout << p.first + 1 << " " << p.second + 1 << endl ;
    }
}