// payments_amount_first_payersflag.cpp
// 형식: [금액] [이름(여러 단어 가능)]
//  예)  20 Alice
//      50 Bob Charles
// 빌드: g++ -std=c++11 -O2 -Wall payments_amount_first_payersflag.cpp -o
// payments 실행: ./payments

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// --------------------- 유틸 ---------------------
static inline string trim(const string& s) {
    const string ws = " \t\r\n";
    size_t a = s.find_first_not_of(ws);
    if (a == string::npos)
        return "";
    size_t b = s.find_last_not_of(ws);
    return s.substr(a, b - a + 1);
}

static inline bool parseStrictDouble(const string& s, double& out) {
    istringstream iss(s);
    iss >> out;
    return iss && iss.eof();
}

// --------------------- Linked List ---------------------
struct Node {
    string name;
    double paid;
    double owed;  // 이후 계산용
    Node* next;

    Node(const string& n, double p)
        : name(n), paid(p), owed(0.0), next(nullptr) {}
};

class LinkedList {
   private:
    Node* head;
    Node* tail;
    size_t sz;

   public:
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void push_back(const string& name, double paid) {
        Node* nd = new Node(name, paid);
        if (!head) {
            head = tail = nd;
        } else {
            tail->next = nd;
            tail = nd;
        }
        ++sz;
    }

    size_t size() const { return sz; }
    Node* begin() const { return head; }
};

// --------------------- 핵심 로직 ---------------------
struct Party {
    string name;
    double amount;  // debtor: 내야 하는 금액, creditor: 받아야 하는 금액
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter input filename: ";
    string filename;
    if (!getline(cin, filename)) {
        cerr << "Failed to read filename.\n";
        return 1;
    }
    filename = trim(filename);

    ifstream fin(filename);
    if (!fin) {
        cerr << "Cannot open file: " << filename << "\n";
        return 1;
    }

    LinkedList people;
    vector<string> allNames;  // 전체 이름 저장 (출력용)
    unordered_map<string, double>
        outPaid;  // 각 사람이 "얼마를 지불했는지" 누적 (0이면 pay 안함)

    string line;
    size_t lineNo = 0;
    while (getline(fin, line)) {
        ++lineNo;
        line = trim(line);
        if (line.empty())
            continue;

        // 형식: [금액 토큰] [공백] [이름 전체]
        istringstream iss(line);
        string amountTok;
        if (!(iss >> amountTok)) {
            cerr << "Invalid line (missing amount) at " << lineNo << ": "
                 << line << "\n";
            return 1;
        }

        double paid = 0.0;
        if (!parseStrictDouble(amountTok, paid)) {
            cerr << "Amount must come first and be numeric at line " << lineNo
                 << ": " << amountTok << "\n";
            return 1;
        }

        string nameRest;
        getline(iss, nameRest);        // 남은 부분 = 이름(여러 단어)
        string name = trim(nameRest);  // 앞 공백 제거

        if (name.empty()) {
            cerr << "Missing name after amount at line " << lineNo << "\n";
            return 1;
        }

        people.push_back(name, paid);
        allNames.push_back(name);
        outPaid.emplace(name, 0.0);  // 초기화: 아직 아무도 지불 X
    }

    if (people.size() < 2) {
        cerr << "Need at least 2 valid records.\n";
        return 1;
    }

    // 합계/평균
    double total = 0.0;
    size_t n = 0;
    for (Node* cur = people.begin(); cur; cur = cur->next) {
        total += cur->paid;
        ++n;
    }
    double target = total / static_cast<double>(n);

    // 채무자/채권자 분리
    const double EPS = 1e-9;
    vector<Party> debtors;    // pay only
    vector<Party> creditors;  // receive only

    for (Node* cur = people.begin(); cur; cur = cur->next) {
        double diff = cur->paid - target;
        if (diff > EPS) {
            creditors.push_back({cur->name, diff});
        } else if (diff < -EPS) {
            debtors.push_back({cur->name, -diff});
        } else {
            // 평균과 같으면 아무 조치 없음 (나중에 outPaid로 “pay 안함” 표시됨)
        }
    }

    cout << "--- Settlement Instructions ---\n";
    cout << fixed << setprecision(2);

    if (debtors.empty() && creditors.empty()) {
        cout << "No transfers needed.\n";
    } else {
        // 그리디 매칭
        size_t i = 0, j = 0;
        while (i < debtors.size() && j < creditors.size()) {
            double pay = min(debtors[i].amount, creditors[j].amount);
            cout << debtors[i].name << " pays " << creditors[j].name << " $"
                 << pay << "\n";

            // 이 줄에서 실제로 누가 "pay" 했는지 기록
            outPaid[debtors[i].name] += pay;

            debtors[i].amount -= pay;
            creditors[j].amount -= pay;
            if (debtors[i].amount <= EPS)
                ++i;
            if (creditors[j].amount <= EPS)
                ++j;
        }
    }

    // ── 추가 출력: "지불하지 않은 사람" 알림
    for (const auto& nm : allNames) {
        if (outPaid[nm] <= 0.0) {
            cout << nm << " doesn't need to pay anything\n";
        }
    }

    return 0;
}