#include <bits/stdc++.h>
using namespace std;
class Sofa {
public:
    int fsr, fsc, ssr, ssc, moves;
    char dir;
    Sofa(int a, int b, int c, int d, char e, int f) {
        fsr = a;
        fsc = b;
        ssr = c;
        ssc = d;
        dir = e;
        moves = f;
    }
};
int r, c;
vector<vector<char>> arr;
set<string> vis;
bool canAdd(int fsr, int fsc, int ssr, int ssc) {
    if (fsr < 0 || fsr >= r || ssr < 0 || ssr >= r || fsc < 0 || fsc >= c || ssc < 0 || ssc >= c) {
        return false;
    }
    if (arr[fsr][fsc] == 'H' || arr[ssr][ssc] == 'H') {
        return false;
    }
    if (fsr > ssr|| (fsr == ssr && fsc > ssc)) {
        swap(fsr, ssr);
        swap(fsc, ssc);
    }
    string key=to_string(fsr)+"_"+to_string(fsc)+"_"+to_string(ssr)+"_" +to_string(ssc);
    if (vis.count(key)) {
        return false;
    }
    vis.insert(key);
    return true;
}
int main() {
    cin >> r >> c;
    arr.assign(r, vector<char>(c));
    int fsr=fsc=ssr=ssc=-1, fsf = 0;
    queue<Sofa> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 's') {
                if (fsf == 0) {
                    fsr = i;
                    fsc = j;
                    fsf++;
                } else {
                    ssr = i;
                    ssc = j;
                    if (fsr > ssr || (fsr == ssr && fsc > ssc)) {
                        swap(fsr, ssr);
                        swap(fsc, ssc);
                    }
                    q.push(Sofa(fsr, fsc, ssr, ssc,(fsr == ssr) ? 'H' : 'V', 0));
                    canAdd(fsr, fsc, ssr, ssc);
                }
            }
        }
    }
    while (!q.empty()) {
        Sofa s = q.front();
        q.pop();
        if (arr[s.fsr][s.fsc] == 'S' && arr[s.ssr][s.ssc] == 'S') {
            cout << s.moves;
            return 0;
        }
        auto add = [&](int a, int b, int d, int e, char dir) {
            if (canAdd(a, b, d, e)) {
                if (a > d || (a == d && b > e)) {
                    swap(a, d);
                    swap(b, e);
                }
                q.push(Sofa(a, b, d, e, dir, s.moves + 1));
            }
        };
        if (s.dir == 'H') {
            if (s.ssc < c - 1 && arr[s.ssr][s.ssc + 1] != 'H') {
                add(s.ssr, s.ssc, s.ssr, s.ssc + 1, 'H');
            }
            if (s.fsc > 0 && arr[s.fsr][s.fsc - 1] != 'H') {
                add(s.fsr, s.fsc - 1, s.fsr, s.fsc, 'H');
            }
            if (s.fsr > 0 && arr[s.fsr - 1][s.fsc] != 'H' && arr[s.ssr - 1][s.ssc] != 'H') {
                add(s.fsr - 1, s.fsc, s.ssr - 1, s.ssc, 'H');
            }
            if (s.fsr < r - 1 && arr[s.fsr + 1][s.fsc] != 'H' && arr[s.ssr + 1][s.ssc] != 'H') {
                add(s.fsr + 1, s.fsc, s.ssr + 1, s.ssc, 'H');
            }
            if (s.fsr > 0 && arr[s.fsr - 1][s.fsc] != 'H' && arr[s.ssr - 1][s.ssc] != 'H') {
                add(s.ssr - 1, s.ssc, s.ssr, s.ssc, 'V');
                add(s.fsr - 1, s.fsc, s.fsr, s.fsc, 'V');
            }
            if (s.fsr < r - 1 && arr[s.fsr + 1][s.fsc] != 'H' && arr[s.ssr + 1][s.ssc] != 'H') {
                add(s.ssr, s.ssc, s.ssr + 1, s.ssc, 'V');
                add(s.fsr, s.fsc, s.fsr + 1, s.fsc, 'V');
            }
        } else {
            if (s.ssr < r - 1 && arr[s.ssr + 1][s.ssc] != 'H') {
                add(s.ssr, s.ssc, s.ssr + 1, s.ssc, 'V');
            }
            if (s.fsr > 0 && arr[s.fsr - 1][s.fsc] != 'H') {
                add(s.fsr - 1, s.fsc, s.fsr, s.fsc, 'V');
            }
            if (s.fsc > 0 && arr[s.fsr][s.fsc - 1] != 'H' && arr[s.ssr][s.ssc - 1] != 'H') {
                add(s.fsr, s.fsc - 1, s.ssr, s.ssc - 1, 'V');
            }
            if (s.fsc < c - 1 && arr[s.fsr][s.fsc + 1] != 'H' && arr[s.ssr][s.ssc + 1] != 'H') {
                add(s.fsr, s.fsc + 1, s.ssr, s.ssc + 1, 'V');
            }
            if (s.fsc > 0 && arr[s.fsr][s.fsc - 1] != 'H' && arr[s.ssr][s.ssc - 1] != 'H') {
                add(s.fsr, s.fsc - 1, s.fsr, s.fsc, 'H');
                add(s.ssr, s.ssc - 1, s.ssr, s.ssc, 'H');
            }
            if (s.fsc < c - 1 && arr[s.fsr][s.fsc + 1] != 'H' && arr[s.ssr][s.ssc + 1] != 'H') {
                add(s.fsr, s.fsc, s.fsr, s.fsc + 1, 'H');
                add(s.ssr, s.ssc, s.ssr, s.ssc + 1, 'H');
            }
        }
    }
    cout << "Impossible";
    return 0;
}
