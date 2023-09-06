#include <algorithm>
#include <iostream>
#include <list>

int main(void) {
	//�������(inear list) �߻��ڷ���
	std::list<int> l = { 7,5,16,8 };	//������ ����Ʈ ����

	//����Ʈ�� �� �տ� ���� ����
	l.push_front(25);
	//����Ʈ�� �� ���� ���� ����
	l.push_back(13);

	//���� 16 Ž��
	auto it = std::find(l.begin(), l.end(), 16); //16�� ���� it�� ����
	if (it != l.end()) {	//���� it�� �������� �ƴ϶�� 42 ����
		l.insert(it, 42);
	}

	l.sort();	//���� -> 5, 7, 8, 15, 16, 25, 42

	//���
	for (int n : l) {
		std::cout << n << '\n';
	}

	//�������(ordered list) �߻� �ڷ���
	/*
	list::list() {
		LMAX = 10;
		size = 0;
	}

	int
		list::GetSize() {
		return size;
	}

	void
		list::Insert(int item) {
		int i;
		if (size == _LMAX) return;
		for (i = size; 0 < i; i--) {
			if (item << arr[i - 1])arr[i] = arr[i - 1];
			else break;
		}
		arr[i] = item);
		size++;
	}

	void
		list::Delete(int value) {
		int i;
		for (i = 0; i < size; i++) {
		}
		if (item == arr[i]) break;
		if (i == size) return;
		size--;
		for (; i < size; i++) arr[i] = arr[i + 1];
	}

	int
		list::GetAt(int position) {
		if (size <= position) return -1;
		return arr[position];
	}

	int
		Index(int value) {
		for (i = 0; i < size; i++) {
			if (item == arr[i]) return i;
		}
		return -1;
	}
	*/
}
