#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
struct State {
    int len;
    int link;
    map<char, int> next;
    State() {
        len = 0;
        link = -1;
    }
};
class SuffixAutomaton {
private:
    vector<State> st;
    int last;
public:
    SuffixAutomaton() {
        st.push_back(State());
        last = 0;
    }
    void extend(char c) {
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next.count(c) == 0) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[c];

            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = clone;
                st[cur].link = clone;
            }
        }
        last = cur;
    }
    string longestCommonSubstring(string s, string t) {
        int i;
        for (i = 0; i < (int)s.size(); i++) {
            extend(s[i]);
        }
        int v = 0;
        int l = 0;
        int best = 0;
        int pos = 0;
        for (i = 0; i < (int)t.size(); i++) {
            char c = t[i];
            while (v && st[v].next.count(c) == 0) {
                v = st[v].link;
                l = st[v].len;
            }
            if (st[v].next.count(c)) {
                v = st[v].next[c];
                l++;
            }
            if (l > best) {
                best = l;
                pos = i;
            }
        }
        return t.substr(pos - best + 1, best);
    }
};
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    SuffixAutomaton sa;
    string ans = sa.longestCommonSubstring(s, t);
    cout << ans << endl;
    cout << "Length: " << ans.length() << endl;
    return 0;
}
