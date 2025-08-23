#include <fstream>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/* =========================
 * Part 1. Pascal Symbol Balance Checker
 * ========================= */

// 괄호 매칭 함수
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Pascal 심볼 밸런스 검사
bool isPascalBalanced(ifstream& in) {
    stack<string> st;
    string token;

    while (in >> token) {
        if (token == "begin") {
            st.push("begin");
        } else if (token == "end") {
            if (st.empty() || st.top() != "begin")
                return false;
            st.pop();
        } else {
            for (char ch : token) {
                if (ch == '(' || ch == '[' || ch == '{') {
                    st.push(string(1, ch));
                } else if (ch == ')' || ch == ']' || ch == '}') {
                    if (st.empty())
                        return false;
                    string top = st.top();
                    st.pop();
                    if (top.size() != 1 || !isMatching(top[0], ch)) {
                        return false;
                    }
                }
            }
        }
    }

    return st.empty();
}

int main() {
    string filename;
    cout << "Enter Pascal source filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: cannot open file " << filename << endl;
        return 1;
    }

    bool result = isPascalBalanced(fin);
    cout << (result ? "True" : "False") << endl;

    return 0;
}

/* =========================
 * Part 2. Queue with std::vector
 * ========================= */

template <class T>
class VectorQueue {
    vector<T> data;
    size_t head = 0;  // 현재 큐의 시작 위치

   public:
    bool empty() const { return head == data.size(); }

    size_t size() const { return data.size() - head; }

    void push(const T& val) { data.push_back(val); }

    T& front() { return data[head]; }

    void pop() {
        ++head;
        if (empty()) {  // 비면 reset
            data.clear();
            head = 0;
        }
    }
};
