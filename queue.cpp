#include <iostream>
using namespace std;
#define ERROR -1;

class queue3 {
public:
    queue3() {
        rear = 0;
    }
    bool IsEmpty() { return (rear == 0); };
    bool IsFull() { return (rear == 3); };
    bool InsertQ(int el) {
        if (IsFull()) return false;
        arr[rear++] = el;
        return true;
    }
    int DeleteQ() {
        if (IsEmpty()) return ERROR;
        int el = arr[0];
        rear--;
        for (int i = 0; i < rear; i++) arr[i] = arr[i + 1];
        return el;
    }
private:
    int arr[3];
    int rear;
};

class queue9 {
public:
    queue9();
    bool IsEmpty();
    bool IsFull();
    bool InsertQ(int el);
    int DeleteQ();
private:
    queue3 q1;
    queue3* q2;
    queue3* q3;
};
//**********************************************************
queue9::queue9() {
    q1 = queue3();
    q2 = new queue3();
    q3 = new queue3();
}

bool queue9::IsEmpty() {
    return q1.IsEmpty();
}

bool queue9::IsFull() {
    return q1.IsFull();
}

bool queue9::InsertQ(int el) {
    if (!(q3->IsFull())) {      //q3�� �� ���������� q3�� InsertQ�ϰ�
        return q3->InsertQ(el);
    }
    else if (!(q2->IsFull())) {    //q2�� '' q2�� InsertQ
        return q2->InsertQ(el);
    }
    else if (!(q1.IsFull())) {   //q1�� '' q2�� InsertQ
        return q1.InsertQ(el);
    }
    return ERROR;                //�� �ƴϸ� ERROR
}

int queue9::DeleteQ() {
    if (!(q3->IsEmpty())) {
        return q3->DeleteQ();
    }
    else if (!(q2->IsEmpty())) {
        return q2->DeleteQ();
    }
    else if (!(q1.IsEmpty())) {
        return q1.DeleteQ();
    }
    return ERROR;
}
//**********************************************************
int main() {
    int n, i, a;
    queue9* q = new queue9();

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) cout << q->DeleteQ() << " ";
        else q->InsertQ(a);
    }
    return 0;
};
/*
* Description
���� ������ "��������"�� ������ ���ڰ� 3�� �ۿ� �����ϴ�. ���� ����ڰ� 3���� ��� �� ������ ����� ������� ���ϰ� ���ư��� �˴ϴ�. 
�� ��Ȳ�� ��ǻ�� ���α׷����� �ùķ��̼� �ϰ��� �Ѵٸ�, queue3�� �̿��Ͽ� �ذ�?�� �� �ֽ��ϴ�.
���� �� �������� ���� ���� 6���� �߰��ؼ� ��ġ�߽��ϴ�. �̸� �ùķ��̼� �ϰ��� �Ѵٸ�, ���ο� queue9�� �ʿ��ѵ�, 
������ queue3 ������ �� ������ �ذ��ϰ��� �մϴ�. �Է����� �־����� ���� ������ ���� ������ �����ϴ� ����� �ǹ��ϸ�, 
0�� ������ �ǹ��ϸ�, ���� ������ �Էµ��� �ʽ��ϴ�. ť�� ������ ��� ERROR(-1)�� �����մϴ�.

*Sample Intput 1
6 1 2 3 0 0 0 // �Է��� ù��° ���� ����(�Ǵ� ������)�� ������ �ǹ��Ѵ�. ��, 6���� ������ "1,2,3,0,0,0"�� �о� ���α׷��� �����Ѵ�.

*Sample Output 1
1 2 3 // ó�� 3���� �Է����� 1�� 2�� 3�� ť�� ����. ���� 3���� ����̹Ƿ� ������� 1 2 3 �� ��µȴ�.

*Sample Intput 2
13 1 2 3 4 5 6 0 0 0 0 0 0 0

*Sample Output 2
1 2 3 4 5 6 -1
*/

