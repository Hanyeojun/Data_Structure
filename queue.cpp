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
    if (!(q3->IsFull())) {      //q3가 꽉 차지않으면 q3의 InsertQ하고
        return q3->InsertQ(el);
    }
    else if (!(q2->IsFull())) {    //q2가 '' q2에 InsertQ
        return q2->InsertQ(el);
    }
    else if (!(q1.IsFull())) {   //q1가 '' q2에 InsertQ
        return q1.InsertQ(el);
    }
    return ERROR;                //다 아니면 ERROR
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
새로 오픈한 "작은병원"은 대기실의 의자가 3개 밖에 없습니다. 따라서 대기자가 3명일 경우 그 이후의 사람은 대기하지 못하고 돌아가게 됩니다. 
이 상황을 컴퓨터 프로그램으로 시뮬레이션 하고자 한다면, queue3를 이용하여 해결?할 수 있습니다.
이제 이 병원에서 새로 의자 6개를 추가해서 설치했습니다. 이를 시뮬레이션 하고자 한다면, 새로운 queue9가 필요한데, 
병원은 queue3 세개로 이 문제를 해결하고자 합니다. 입력으로 주어지는 양의 정수는 새로 병원에 도착하는 사람을 의미하며, 
0은 삭제를 의미하며, 음의 정수는 입력되지 않습니다. 큐는 오류의 경우 ERROR(-1)를 리턴합니다.

*Sample Intput 1
6 1 2 3 0 0 0 // 입력의 첫번째 수는 연산(또는 데이터)의 개수를 의미한다. 즉, 6개의 데이터 "1,2,3,0,0,0"를 읽어 프로그램을 실행한다.

*Sample Output 1
1 2 3 // 처음 3개는 입력으로 1과 2와 3이 큐에 들어간다. 다음 3개는 출력이므로 순서대로 1 2 3 이 출력된다.

*Sample Intput 2
13 1 2 3 4 5 6 0 0 0 0 0 0 0

*Sample Output 2
1 2 3 4 5 6 -1
*/

