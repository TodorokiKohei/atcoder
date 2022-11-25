#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    int A, B, C, D;
    A = 1; B = n; C = 1; D = n;
    
    int mid, t;
    while(A != B){
        mid = (B+A)/2;
        printf("? %d %d %d %d\n", A, mid, 1, n);
        flush(cout);
        cin >> t;
        if (t != (mid-A+1)){
            B = mid;
        }else{
            A = mid + 1;
        }
    }

    while(C != D){
        mid = (C+D)/2;
        printf("? %d %d %d %d\n", 1, n, C, mid);
        flush(cout);
        cin >> t;
        if (t != (mid-C+1)){
            D = mid;
        }else{
            C = mid + 1;
        }
    }

    printf("! %d %d\n", A, C);
}