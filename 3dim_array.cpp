/* ������ main�Լ��� �����ϵ��� 3���� �迭 �ڷᱸ���� �����Ͻÿ�.
�̶� �Է��� ����(index)�� �迭�� ������ ����ų�, �Է°��� 0���� �۰ų� ������, �迭�� �������� �ʴ´�.
����, ��½� ������ �Ѿ�� �Է¿� ���ؼ��� -1�� ����ϰ� �Էµ��� ���� ���� ���ؼ��� 0�� ����Ѵ�.

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
    int* arr_;	//�����Ҵ�
	int d1_ = 0;
	int d2_ = 0;
	int d3_ = 0;
};

void arrInt3::SetAt(int p1, int p2, int p3, int v) {	//�Էµ� ��ǥ��(x,y,z)�� v�� ����
	int setf = p1 * (d2_ * d3_) + p2 * d3_ + p3;		//3���� �迭 ����
	arr_[setf] = v;
}

int arrInt3::GetAt(int p1, int p2, int p3) {		//��ǥ���� ����Ͽ� �׿� �´� v�� ��ȯ
	int getf = p1 * (d2_ * d3_) + p2 * d3_ + p3;
	return arr_[getf];
}

arrInt3::arrInt3(int d1, int d2, int d3) {		//�����ڸ� ����Ͽ� Ŭ������ �����԰� ���ÿ� �Լ� ȣ���Ͽ� �迭 �ʱ�ȭ
	int size = d1 * d2 * d3;					//3���� �迭�� ��ü ũ��
	arr_ = new int[size];					//�����Ҵ�
	for (int i = 0; i < size; i++) {		//�迭 arr_�ʱ�ȭ
		arr_[i] = 0;
	}
}

int main() {
	int d1, d2, d3;	//3���� �迭�� ũ��
	int x, y, z, v;	//�迭�� ��,��,��,��

	cin >> d1 >> d2 >> d3;	//d1���� �� �ȿ� d2���� ��, d3���� �� �Է�
	arrInt3 cube(d1, d2, d3);	//3���� �迭ó�� ����, cube = Ŭ���� ����

	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> z >> v;	
		cube.SetAt(x, y, z, v);
	}
	cin >> x >> y >> z;
	cout << cube.GetAt(x, y, z) << endl;
}