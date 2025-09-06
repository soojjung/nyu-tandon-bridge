#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

#define RED 0
#define BLACK 1

// ================== Node ==================
template <class T>
struct RBTNode {
    T data;
    int color;
    RBTNode* left;
    RBTNode* right;
    RBTNode* parent;

    RBTNode(const T& val)
        : data(val),
          color(RED),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}
};

// ================== Tree ==================
template <class T>
class RBT {
   private:
    RBTNode<T>* root;

    // 부모가 들고 있는 링크(루트 또는 부모의 left/right)를 참조로 돌려줌
    RBTNode<T>*& fromParentRef(RBTNode<T>* node) {
        if (node == nullptr)
            return root;  // 사용 안 하지만 시그니처 맞춤용
        if (node->parent == nullptr)
            return root;
        return (node->parent->left == node) ? node->parent->left
                                            : node->parent->right;
    }

    // 회전: point 는 "부모가 들고 있는 링크"의 참조여야 함!
    void singleCR(RBTNode<T>*& point) {  // Right rotation
        RBTNode<T>* g = point;
        RBTNode<T>* p = g->left;
        if (!p)
            return;

        g->left = p->right;
        if (p->right)
            p->right->parent = g;

        p->right = g;
        p->parent = g->parent;
        g->parent = p;

        point = p;  // 부모 링크(또는 root)가 새 루트 p를 가리키도록
    }

    void singleCCR(RBTNode<T>*& point) {  // Left rotation
        RBTNode<T>* g = point;
        RBTNode<T>* p = g->right;
        if (!p)
            return;

        g->right = p->left;
        if (p->left)
            p->left->parent = g;

        p->left = g;
        p->parent = g->parent;
        g->parent = p;

        point = p;
    }

    void doubleCR(RBTNode<T>*& point) {  // Left-Right
        singleCCR(point->left);
        singleCR(point);
    }
    void doubleCCR(RBTNode<T>*& point) {  // Right-Left
        singleCR(point->right);
        singleCCR(point);
    }

    // 삽입 (재귀 BST 삽입 + RBT Fix-up)
    void insert(const T& toInsert, RBTNode<T>*& point, RBTNode<T>* parent) {
        if (point == nullptr) {
            point = new RBTNode<T>(toInsert);
            point->parent = parent;

            // Fix-up 시작
            RBTNode<T>* curr = point;

            // 루트면 BLACK
            if (curr->parent == nullptr) {
                curr->color = BLACK;
                root = curr;
                return;
            }

            while (curr->parent && curr->parent->color == RED) {
                RBTNode<T>* par = curr->parent;
                RBTNode<T>* gp = par->parent;
                if (!gp)
                    break;  // 부모가 루트 -> 위반 없음

                // 부모가 조부의 왼쪽인가 오른쪽인가
                bool parentIsLeft = (gp->left == par);

                RBTNode<T>* uncle = parentIsLeft ? gp->right : gp->left;

                // Case 1: 삼촌 RED -> recolor 후 위로
                if (uncle && uncle->color == RED) {
                    par->color = BLACK;
                    uncle->color = BLACK;
                    gp->color = RED;
                    curr = gp;
                    continue;
                }

                // Case 2/3: 삼촌 BLACK
                if (parentIsLeft) {
                    // 왼쪽 서브트리
                    if (par->right == curr) {
                        // 안쪽(LR): 부모 기준 좌회전
                        singleCCR(fromParentRef(par));
                        // 포인터 갱신
                        curr = par;  // 회전 전 par가 내려가 curr의 위치로 이동
                        par = curr->parent;  // 새 부모
                    }
                    // 바깥쪽(LL): 조부 기준 우회전 + 색교환(par<->gp)
                    singleCR(fromParentRef(gp));
                    // 회전 후, par가 서브트리 루트가 됨 (gp의 부모 링크가
                    // 가리키는 노드)
                    RBTNode<T>* newSubRoot = fromParentRef(
                        gp);  // 회전 후 gp의 부모 링크가 가리키는 노드가 par
                    // 하지만 위 한 줄은 참조를 얻는 과정이라 값 사용이
                    // 애매하니, 안전하게:
                    RBTNode<T>* parNow = (gp->parent ? (gp->parent->left == gp
                                                            ? gp->parent->right
                                                            : gp->parent->left)
                                                     : root);
                    // 위 한 줄은 복잡해질 수 있으므로 확실하게 root에서 찾자:
                    parNow = (gp->parent ? (gp->parent->left) : root);
                    // 더 간단/안전: 회전 전 par가 올라오므로 par가
                    // fromParentRef(gp)로 교체된 노드임
                    par->color = BLACK;
                    gp->color = RED;
                } else {
                    // 오른쪽 서브트리 (대칭)
                    if (par->left == curr) {
                        // 안쪽(RL): 부모 기준 우회전
                        singleCR(fromParentRef(par));
                        curr = par;
                        par = curr->parent;
                    }
                    // 바깥쪽(RR): 조부 기준 좌회전 + 색교환
                    singleCCR(fromParentRef(gp));
                    par->color = BLACK;
                    gp->color = RED;
                }
            }

            // 루트 BLACK 보장
            while (root && root->parent) root = root->parent;
            if (root)
                root->color = BLACK;
            return;
        }

        // BST 내려가기
        if (toInsert < point->data)
            insert(toInsert, point->left, point);
        else
            insert(toInsert, point->right, point);
    }

    // 중위순회 (색상 표시)
    void inorder(RBTNode<T>* node) {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << "(" << (node->color == RED ? "R" : "B") << ") ";
        inorder(node->right);
    }

    // 검정 높이(모든 경로 동일해야 함)
    int blackHeight(RBTNode<T>* node) {
        if (!node)
            return 1;  // NIL은 BLACK으로 간주
        int left = blackHeight(node->left);
        int right = blackHeight(node->right);
        assert(left == right);
        return left + (node->color == BLACK ? 1 : 0);
    }

   public:
    RBT() : root(nullptr) {}

    void insert(const T& toInsert) { insert(toInsert, root, nullptr); }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    int height() { return blackHeight(root); }
};

// ================== Main (간단 테스트) ==================
int main() {
    RBT<int> tree;
    for (int i = 1; i <= 20; i++) {
        tree.insert(i);
    }
    tree.inorder();  // 색상이 R/B 섞여야 정상

    int h = tree.height();
    cout << "Black-Height = " << h << endl;
    assert(h <= 2 * log2(20));  // 느슨한 상한 체크

    cout << "All tests passed!" << endl;
    return 0;
}