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

const int inf = 1 << 30;
const ll INF = 1LL << 60;

bool f(string num, VI &nums){
    VI cnums(10);
    rep(i, sz(num)) cnums[num[i]-'0']++;
    rep(i,10) if (nums[i] < cnums[i]) return false;
    return true;
}

int main(){
    string s;
    cin >> s;
    int n = sz(s);
    VI nums(10);
    rep(i,n) nums[s[i]-'0']++;
    if (n == 1){
        if (s == "8"){
            cout << "Yes" << endl;
            return 0;
        } 

    }else if(n == 2){
        if (stol(s) % 8 == 0){
            cout << "Yes" << endl;
            return 0;
        }
        swap(s[0], s[1]);
        if (stol(s) % 8 == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }else{
        for(int i = 8; i < 1000; i += 8){
            string num = to_string(i);
            string d = "";
            rep(i, 3-sz(num)) d += "0";
            num = d + num;
            if (f(num, nums)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
 
    cout << "No" << endl;
    return 0;
}