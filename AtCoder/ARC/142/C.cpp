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
int V[101] , U[101] ;
vector<int> A[1010] , B[1010] ;
set<int> st , tt ;

int main(){
    // fast_input_output
    cin >> n ;

    int res = 1300 ;
    rrep(i,3,n+1){
        int d, c ;
        cout << '?' << " " << 1 << " " << i << endl ;
        cin >> d ;
        cout << '?' << " " << 2 << " " << i << endl ;
        cin >> c ;
        V[i] = d ;
        U[i] = c ;
        chmin(res,d+c) ;
        st.insert(d+c) ;
        tt.insert(abs(d-c)) ;
    }
    // int dd = *st.begin() ;
    // if(st.size() == 1 && dd == n - 1){
    //     cout << '!' << " " << dd << endl ;
    //     return 0 ;
    // }
    int ee = *tt.begin() ;
    if(tt.size() == 1 && ee == 1 && n == 4){
        cout << '!' << " " << 1 << endl ;
        return 0 ;
    }
    cout << '!' << " " << res << endl ;
}