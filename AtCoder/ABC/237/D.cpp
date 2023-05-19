#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<char,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
string S ;
vector<P> vec[505050] ;
map<int,int> mp ;

int main(){
    cin >> n >> S ;
    int lef = 0 , rig = 0 ;
    mp[0] = n ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(S[i] == 'R'){
            lef-- ;
            mp[lef] = i ;
        }
        if(S[i] == 'L'){
            rig++ ;
            mp[rig] = i ;
        }
    }
    for(auto it : mp) cout << it.second << " " ; cout << endl ;
}