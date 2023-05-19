#include <iostream>
#include <string>
using namespace std;

int han0(int&　i,int& x,string& A,int a)
{
    string t ;
    int count ;
    for(int j = i ; j < a){
        t = A[i] ;
        if(A[i] == t)
        count = count + 1 ;
        else 
        break
    }
    
}

void match()
{
    int a,y;
    cin >> a ;
    int A[a] ;
    string str
    for(int i = 0 ; i < a ; i++) cin >> A[i] ;
    cin >> str ;
    int x = 0 ;
    for(int i = 0 ; i < a ; i++){
        y = A[i] ^ x ;
        if(str[i]=='1') x = max(x,y) ;
        else min(x,y)
        }
    }
}

int main(void) {
    int n ;
    cin >> n ;

    string str;   //今回は15文字入力と予めわかっている
    string N[15];

    cin >> str;

    for (int i = 0; i < 15; ++i) {

        N[i] = str[i];  //str[i]　はchar型なのでchar→intへ変換

        cout << N[i] << endl;  //確認のため表示

    }

    return 0;
}