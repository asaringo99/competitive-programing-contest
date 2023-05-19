#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
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
priority_queue<ll> que ;

int main(){
    cin >> n ;
    rrep(z,1,3001){
        rrep(y,1,5001){
            int x = n - y - z ;
            if(x <= 0) continue ;
            if((x + 3 * y + 5 * z - 4) % 15 == 0){
                vector<int> vec ;
                rrep(i,1,x+1) vec.push_back(2*i) ;
                rrep(i,1,y+1) vec.push_back(3*(2*i-1)) ;
                rrep(i,1,z+1) vec.push_back(5*(2*i-1)) ;
                for(int u : vec) cout << u << " " ; cout << endl ;
                return 0 ;
            }
        }
    }
}