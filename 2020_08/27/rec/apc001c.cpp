#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    string s;
    cout << 0 << endl;;
    cin >> s;
    flush(cout);
    if (s == "Vacant"){
        cout << 0 << endl;
        return 0;
    }
    string sex = s;
    int left = 0, right = n;
    while(true){
        int mid = (right+left) / 2;
        cout << mid << endl;;
        cin >> s;
        flush(cout);
        if (s == "Vacant"){
            cout << mid << endl;
            return 0;
        }
        if (mid % 2 != 0){
            if (sex != s) left = mid;
            else right = mid;
        }else{
            if (sex == s) left = mid;
            else right = mid;
        }
    }
    return 0;
}