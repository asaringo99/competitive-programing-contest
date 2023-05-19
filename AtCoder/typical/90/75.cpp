#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;
unordered_map<ll,int> mp ;

int main(){
    cin >> n ;
    for(ll i = 2 ; i * i <= n ; i++){
        if(n % i != 0) continue ;
        while(n % i == 0){
            mp[i]++ ;
            n /= i ;
        }
    }
    if(n != 1) mp[n]++ ;
    ll sum = 0 ;
    for(auto it : mp) sum += it.second ;
    ll res = 1 , count = 0 ;
    while(res < sum) {
        res *= 2 ;
        count++ ;
    }
    cout << count << endl ;
}