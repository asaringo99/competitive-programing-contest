#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
string S;
int C[3], O[3], N[3];

int main(){
    fast_input_output
    cin >> n >> S ;
    rep(i,n*3){
        if(S[i] == 'c') C[i%3]++;
        if(S[i] == 'o') O[(i+2)%3]++;
        if(S[i] == 'n') N[(i+1)%3]++;
    }
    int res = 0;
    rep(i,3) res += min({C[i],O[i],N[i]});
    if(res == n && C[0] != n) res--;
    cout << res << endl;
}