#include <algorithm>
#include <iostream>
#include <list>

int main(void) {
	//선형목록(inear list) 추상자료형
	std::list<int> l = { 7,5,16,8 };	//정수형 리스트 선언

	//리스트의 맨 앞에 정수 삽입
	l.push_front(25);
	//리스트의 맨 위에 정수 삽입
	l.push_back(13);

	//정수 16 탐색
	auto it = std::find(l.begin(), l.end(), 16); //16에 색인 it을 지정
	if (it != l.end()) {	//만약 it이 마지막이 아니라면 42 삽입
		l.insert(it, 42);
	}

	l.sort();	//정렬 -> 5, 7, 8, 15, 16, 25, 42

	//출력
	for (int n : l) {
		std::cout << n << '\n';
	}

	//순서목록(ordered list) 추상 자료형
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
