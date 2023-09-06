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
    bool Search(int el);    //el�� Ʈ���� �ִ��� �Ǻ�
    bool AddLeftChild(int parent, int child);   //parent�� ���� �ڽĳ��� child�� ����
    bool AddRightChild(int parent, int child);  //parent�� ������ �ڽĳ��� child�� ����
    int NumberOfEvenNumbers() { return Noen(root_); };  //¦�� ����� ���� ��ȯ
    int MaxNumber() { return Maxn(root_); };    //�ִ� ��ȯ
    int Difference();   //�ִ�-�ּڰ�

private:
    void DeleteTree(node* ptr);
    node* Search(node* ptr, int el);
    int  Noen(node* ptr);   //¦�� ���� 
    int  Maxn(node* ptr);   //�ִ�
    int  Minn(node* ptr);   //�ּڰ�

private:
    node* root_;
};
//
int binaryTree::Difference() {  //�ִ�-�ּ� 
    return (Maxn(root_) - Minn(root_));
}

int binaryTree::Noen(node* ptr) {    //¦�� ����
    if (ptr == 0) { //������� 0 ��ȯ
        return 0;
    }
    int cnt = 0;
    if (ptr->data_ % 2 == 0) {  //¦���� cnt ī��Ʈ
        cnt++;                  //�������� �������鼭 cnt ī��Ʈ
    }
    cnt += Noen(ptr->lc_);      //���ȣ���ϸ鼭 ī��Ʈ�� lc�� cnt�� ����
    cnt += Noen(ptr->rc_);      //���ȣ���ϸ鼭 ī��Ʈ�� rc�� cnt�� ����
    return cnt;                 //ī��Ʈ�� ��� cnt�� ���� ��ȯ
}
/*���ȣ���� ���Ͽ�( ex : Noen(ptr->lc_), Noen(ptr->rc_)
if(ptr==0) { return 0; }
int cnt = 0;
if(ptr->data_%2 == 0) { cnt++; }�� �ݺ��ϴٰ�
0�� ������ �������� �ö󰡸鼭 �������鼭 ī��Ʈ�� cnt�� ���� ���ϰ� cnt ���� ��ȯ
*/

int binaryTree::Maxn(node* ptr) {   //�ִ�
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

int binaryTree::Minn(node* ptr) {   //�ּڰ�
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