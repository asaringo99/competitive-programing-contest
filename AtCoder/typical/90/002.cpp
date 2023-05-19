#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    if(n % 2 == 1) return 0 ;
    vector<string> ans ;
    for(int i = 0 ; i < (1 << n) ; i++){
        int count = 0 ;
        string res = "" ;
        for(int j = 0 ; j < n ; j++){
            if(count < 0) break ;
            if(i >> j & 1){
                res += ")" ;
                count-- ;
            }
            else{
                res += "(" ;
                count++ ;
            }
        }
        if(count != 0) continue ;
        ans.push_back(res) ;
    }
    for(int i = 0 ; i < ans.size() ; i++){
        string res = ans[ans.size() - 1 - i] ;
        for(int j = 0 ; j < n ; j++){
            char s = res[n - 1 - j] == '(' ? ')' : '(' ; 
            cout << s ;
        }
        cout << endl ;
    }
}