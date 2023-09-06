#include<iostream>
#include<stack>
using namespace std;

class Stack {
	public:
		Stack(int s = 100) {
			size = s;
			storage = new int[size];
			top = 0;
		}
		bool IsEmpty() { 
			return top == 0; 
		}
		bool IsFull() { 
			return top == size; 
		}
		bool Push(int el);
		int Pop();
		int Top();
	private:
		int* storage;
		int top;
		int size;
};

bool Stack::Push(int el) {
	 if (IsFull()) return false;
	 storage[top++] = el;
	 return true;
}
 
int Stack::Pop() {
	if (IsEmpty()) return 0;
	return storage[--top];
	
}
	
int Stack::Top() {
	if (IsEmpty()) return 0;
	return storage[top - 1];
}

int main(void) {
	Stack st1;	//음수
	Stack st2;	//양수
	int num1[10] = {};
	for (int i = 0; i < 10; i++) {
		cin >> num1[i];
		if (num1[i] >= 0) {
			st2.Push(num1[i]);
		}
		else {
			st1.Push(num1[i]);
		}
	}
	while(!st1.IsEmpty())
	{
		cout << st1.Pop() << " ";
	}
	while (!st2.IsEmpty())
	{
		cout << st2.Pop() << " ";
	}
}
/*
입력 : -1 1 2 3 -2 -5 -3 4 6 5
출력 : -3 -5 -2 -1 5 6 4 3 2 1
*/