/* 다음의 main함수가 동작하도록 3차원 배열 자료구조를 구현하시오.
이때 입력의 색인(index)이 배열의 범위를 벗어나거나, 입력값이 0보다 작거나 같으면, 배열에 저장하지 않는다.
또한, 출력시 범위를 넘어서는 입력에 대해서는 -1을 출력하고 입력되지 않은 셀에 대해서는 0을 출력한다.

Sample Input
7 6 5
1 1 1 1
1 1 2 2
1 1 3 3
1 1 1

Sample Output
1													*/

#include <iostream>
using namespace std;

class arrInt3 {
public:
    arrInt3(int d1, int d2, int d3);
    int GetAt(int p1, int p2, int p3);
    void SetAt(int p1, int p2, int p3, int v);
private:
    int* arr_;	//동적할당
	int d1_ = 0;
	int d2_ = 0;
	int d3_ = 0;
};

void arrInt3::SetAt(int p1, int p2, int p3, int v) {	//입력된 좌표값(x,y,z)에 v값 저장
	int setf = p1 * (d2_ * d3_) + p2 * d3_ + p3;		//3차원 배열 공식
	arr_[setf] = v;
}

int arrInt3::GetAt(int p1, int p2, int p3) {		//좌표값을 계산하여 그에 맞는 v값 반환
	int getf = p1 * (d2_ * d3_) + p2 * d3_ + p3;
	return arr_[getf];
}

arrInt3::arrInt3(int d1, int d2, int d3) {		//생성자를 사용하여 클래스를 선언함과 동시에 함수 호출하여 배열 초기화
	int size = d1 * d2 * d3;					//3차원 배열의 전체 크기
	arr_ = new int[size];					//동적할당
	for (int i = 0; i < size; i++) {		//배열 arr_초기화
		arr_[i] = 0;
	}
}

int main() {
	int d1, d2, d3;	//3차원 배열의 크기
	int x, y, z, v;	//배열의 면,행,열,값

	cin >> d1 >> d2 >> d3;	//d1개의 면 안에 d2개의 행, d3개의 열 입력
	arrInt3 cube(d1, d2, d3);	//3차원 배열처럼 생성, cube = 클래스 변수

	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> z >> v;	
		cube.SetAt(x, y, z, v);
	}
	cin >> x >> y >> z;
	cout << cube.GetAt(x, y, z) << endl;
}