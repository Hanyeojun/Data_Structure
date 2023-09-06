#include <iostream>
using namespace std;

class node {
public:
    node() {
        data_ = 0; lc_ = 0; rc_ = 0;
    }
    node(int data, node* lc = 0, node* rc = 0) {
        data_ = data;
        lc_ = lc;
        rc_ = rc;
    }
    int data_;
    node* lc_;
    node* rc_;
};

class binaryTree {
public:
    binaryTree(int root);
    ~binaryTree();
    bool Search(int el);    //el이 트리에 있는지 판별
    bool AddLeftChild(int parent, int child);   //parent의 왼쪽 자식노드로 child를 삽입
    bool AddRightChild(int parent, int child);  //parent의 오른쪽 자식노드로 child를 삽입
    int NumberOfEvenNumbers() { return Noen(root_); };  //짝수 노드의 개수 반환
    int MaxNumber() { return Maxn(root_); };    //최댓값 반환
    int Difference();   //최댓값-최솟값

private:
    void DeleteTree(node* ptr);
    node* Search(node* ptr, int el);
    int  Noen(node* ptr);   //짝수 개수 
    int  Maxn(node* ptr);   //최댓값
    int  Minn(node* ptr);   //최솟값

private:
    node* root_;
};
//
int binaryTree::Difference() {  //최대-최소 
    return (Maxn(root_) - Minn(root_));
}

int binaryTree::Noen(node* ptr) {    //짝수 개수
    if (ptr == 0) { //비었으면 0 반환
        return 0;
    }
    int cnt = 0;
    if (ptr->data_ % 2 == 0) {  //짝수면 cnt 카운트
        cnt++;                  //하위노드로 내려가면서 cnt 카운트
    }
    cnt += Noen(ptr->lc_);      //재귀호출하면서 카운트한 lc의 cnt를 더함
    cnt += Noen(ptr->rc_);      //재귀호출하면서 카운트한 rc의 cnt를 더함
    return cnt;                 //카운트된 모든 cnt의 합을 반환
}
/*재귀호출을 통하여( ex : Noen(ptr->lc_), Noen(ptr->rc_)
if(ptr==0) { return 0; }
int cnt = 0;
if(ptr->data_%2 == 0) { cnt++; }를 반복하다가
0이 나오면 상위노드로 올라가면서 내려오면서 카운트한 cnt의 합을 더하고 cnt 합을 반환
*/

int binaryTree::Maxn(node* ptr) {   //최댓값
    int lmax = 0, rmax = 0;
    if (ptr == 0) {
        return 0;
    }
    if (ptr->lc_ !=0 && ptr->data_ < ptr->lc_->data_) { //left
        lmax = Maxn(ptr->lc_);
    }
    else {
        lmax = ptr->data_;  //
    }
    if (ptr->rc_!=0 && ptr->data_ < ptr->rc_->data_) { //right
        rmax = Maxn(ptr->rc_);
    }
    else {
        rmax = ptr->data_;
    }
    return (lmax > rmax) ? lmax : rmax;
}

int binaryTree::Minn(node* ptr) {   //최솟값
    int lmin = 0, rmin = 0;
    if (ptr == 0) {
        return 0;
    }
    if (ptr->lc_!=0 && ptr->data_ > ptr->lc_->data_) { //left
        lmin = Minn(ptr->lc_);
    }
    else {
        lmin = ptr->data_;
    }
    if (ptr->rc_!=0 && ptr->data_ > ptr->rc_->data_) { //right
        rmin = Minn(ptr->rc_);
    }
    else {
        rmin = ptr->data_;
    }
    return (lmin < rmin) ? lmin : rmin;
}

binaryTree::binaryTree(int root) {
    root_ = new node(root);
};

binaryTree::~binaryTree() {
    DeleteTree(root_);
    root_ = 0;
};

void binaryTree::DeleteTree(node* ptr) {
    if (ptr == 0) return;
    DeleteTree(ptr->lc_);
    DeleteTree(ptr->rc_);
    delete ptr;
};

bool binaryTree::Search(int el) {
    if (Search(root_, el) == 0) return false;
    return true;
};

node* binaryTree::Search(node* ptr, int el) {
    if (ptr == 0) return 0;
    if (ptr->data_ == el) return ptr;
    node* tptr = Search(ptr->lc_, el);
    if (tptr) return tptr;
    tptr = Search(ptr->rc_, el);
    return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
    node* ptr = Search(root_, parent);
    if (ptr == 0) return false;
    if (ptr->lc_ != 0) return false;
    ptr->lc_ = new node(child);
    return true;
};

bool binaryTree::AddRightChild(int parent, int child) {
    node* ptr = Search(root_, parent);
    if (ptr == 0) return false;
    if (ptr->rc_ != 0) return false;
    ptr->rc_ = new node(child);
    return true;
};
//
int main() {
    int n, p, f, c;
    cin >> n;
    cin >> p;
    binaryTree* bt = new binaryTree(p);

    for (int i = 1; i < n; i++) {
        cin >> p >> f >> c;
        if (f == 0) bt->AddLeftChild(p, c);
        else bt->AddRightChild(p, c);
    }
    cout << bt->MaxNumber() << " ";
    cout << bt->Difference() << " ";
    cout << bt->NumberOfEvenNumbers() << " ";
    return 0;
};