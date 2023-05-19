#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,int,int,int> TP ;
typedef tuple<int,int,int> BTP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int x , y , z , n ;
priority_queue<TP> que ;
map<BTP,bool> mp ;
ll A[1010] , B[1010] , C[1010] ;

int main(){
    fast_input_output
    cin >> x >> y >> z >> n ;
    rep(i,x) cin >> A[i] ;
    rep(i,y) cin >> B[i] ;
    rep(i,z) cin >> C[i] ;
    sort(A,A+x,greater<ll>()) ;
    sort(B,B+y,greater<ll>()) ;
    sort(C,C+z,greater<ll>()) ;
    que.push({A[0]+B[0]+C[0],0,0,0}) ;
    while(n > 0){
        auto [top,i,j,k] = que.top() ; que.pop() ;
        mp[{i,j,k}] = true ;
        cout << top << endl ;
        if(i+1<x && !mp[{i+1,j,k}]) {
            que.push({A[i+1]+B[j]+C[k],i+1,j,k}) ;
            mp[{i+1,j,k}] = true ;
        }
        if(j+1<y && !mp[{i,j+1,k}]) {
            que.push({A[i]+B[j+1]+C[k],i,j+1,k}) ;
            mp[{i,j+1,k}] = true ;
        }
        if(k+1<z && !mp[{i,j,k+1}]) {
            que.push({A[i]+B[j]+C[k+1],i,j,k+1}) ;
            mp[{i,j,k+1}] = true ;
        }
        n-- ;
    }
}