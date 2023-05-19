#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int a , b ;
map<int,int> mp ;

int main(){
    cin >> a >> b ;
    for(int i = b + 1 ; i <= a ; i++){
        int t = i ;
        for(int j = 2 ; j * j <= t ; j++){
            if(t % j != 0) continue ;
            while(t % j == 0){
                t /= j ;
                mp[j]++ ;
            }
        }
        if(t != 1) mp[t]++ ;
    }
    ll res = 1 ;
    for(auto it : mp){
        (res *= (it.second + 1)) %= mod ;
    }
    cout << res << endl ;
}