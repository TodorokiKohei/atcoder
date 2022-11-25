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
    int h, w;
    cin >> h >> w;
    vector<int> cnt(26);
    rep(i,h){
        string s;
        cin >> s;
        rep(j, s.size()) cnt[s[j]-'a']++;
    }

    int g1 = (h % 2) * (w % 2);
    int g2 = (h % 2) * (w / 2) + (w % 2) * (h / 2);
    int g4 = (h * w - 2 * g2 - g1) / 4;

    int i = 0;
    while(i < 26){
        if (cnt[i] % 4 == 1 || cnt[i] % 4 == 3){
            if (g1 == 0) break;
            cnt[i]--;
            g1--;
        }
        i++;
    }

    i = 0;
    while(i < 26){
        while(cnt[i] >= 4){
            if (g4 == 0) break;
            cnt[i] -= 4;
            g4--;
        }
        i++;
    }

    i = 0;
    while(i < 26){
        while(cnt[i] >= 2){
            if (g2 == 0) break;
            cnt[i] -= 2;
            g2--;
        }
        i++;
    }

    rep(i, 26){
        if (cnt[i] != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}