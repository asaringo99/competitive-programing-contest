#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

double a , b ;

int main(){
    cin >> a >> b ;
    double x = (a - b) / 3 + b ;
    cout << setprecision(15) << x << endl ;
}