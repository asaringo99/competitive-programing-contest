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

template<typename T> struct StringMatch {
    private:
        vector<int> table , res ;
        vector<T> str , pattern ;

        void build_() {
            makeTable() ;
            kmp() ;
        }

        void makeTable(){
            int n = pattern.size();
            table.resize(n+1) ;
            table[0] = -1;
            int j = -1;
            for (int i = 0; i < n; i++) {
                while(j >= 0 && pattern[i] != pattern[j]) j = table[j] ;
                j++ ;
                table[i+1] = j ;
            }
        }

        void kmp() {
            int m = 0, i = 0, n = str.size();
            while (m+i < n) {
                if (pattern[i] == str[m+i]) {
                    if (++i == (int)(pattern.size())) {
                        res.push_back(m);
                        m = m+i-table[i];
                        i = table[i];
                    }
                }
                else {
                    m = m+i-table[i];
                    if (i > 0) i = table[i];
                }
            }
        }

    public:
        StringMatch(vector<T> s , vector<T> p) : str(s) , pattern(p) {}
        void build() { build_() ; }
        vector<int> first_index_matching() { return res ; }
};

int n ;
int A[202020] , B[202020] ;
vector<int> S , Q ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n-1) Q.push_back((B[i]^B[i+1])) ;
    rep(i,2*n-2) S.push_back((A[i%n]^A[(i+1)%n])) ;
    StringMatch<int> sm(S,Q) ;
    sm.build() ;
    vector<int> vec = sm.first_index_matching() ;
    for(int u : vec){
        cout << u << " " << (A[u] ^ B[0]) << endl ;
    }
}
