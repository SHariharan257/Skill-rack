class MinStack {
public:
vector<pair<int,int>> st;
    void push(int value) {
        int m=value;
        if(!st.empty()){
            m=min(m,getMin());
        }
        st.push_back(make_pair(value,m));
    }
    void pop() {
        st.pop_back();
    }
    int top() {
        return st.back().first;
    }
    int getMin() {
        return st.back().second;
    }
};
