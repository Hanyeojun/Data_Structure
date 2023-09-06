#include <iostream>
#include <string>
using namespace std;

class phoneData {
public:
	phoneData(string name, string phoneNumber, string address);
	void printPD();
	// private:
	string name_;
	string phoneNumber_;
	string address_;
};

class phoneNode {
public:
	phoneNode(phoneData* data, phoneNode* next);
	phoneNode* next_;
	phoneData* data_;
};

class phoneBook {	//만들어진 노드로 리스트를 구성
public:
	phoneBook();
	bool Insert(phoneData* data);
	phoneData* Delete(string name);
	phoneData* Find(string name);
private:
	phoneNode* lst_;
};
//
phoneData::phoneData(string name, string phoneNumber, string address) {	//입력받은 값으로 초기화
	name_ = name;
	phoneNumber_ = phoneNumber;
	address_ = address;
}

void phoneData::printPD() {	//phoneData에 들어있는 값을 화면에 출력
	cout << " name : " << name_ << " phone number : " << phoneNumber_ << " address : " << address_;
}

phoneNode::phoneNode(phoneData* data, phoneNode* next) {
	data_ = data;
	next_ = next;
}

phoneBook::phoneBook() {
	lst_ = 0;
}

bool phoneBook::Insert(phoneData* data) {
	if (lst_ == 0) {
		lst_ = new phoneNode(data,0);	//맨처음은 next가 가리키는게 없으므로 0임
		return true;
	}
	phoneNode * ptr = lst_;
	while (ptr->next_ != 0 && ptr->next_->data_ < data) {	//ptr이 가리키는 next_가 0이 아니고, ptr->next_->data_의 주소값이 집어넣은 data의 주소값보다 작을 때 반복
		ptr = ptr->next_;	//전진
	}
	ptr->next_ = new phoneNode(data, ptr -> next_);	//ptr->next에 새로운 node를 만드는데 그 안에 data와 ptr->next_가 들어감
	return true;
}

phoneData* phoneBook::Delete(string name) {
	phoneNode* ptr = lst_;	//phoneNode의 포인터 ptr은 lst_와 같은 곳을 가리킴
	if (lst_ == 0) {	//지울게 없으므로 끝냄
		return 0;
	}
	if (lst_->data_->name_ == name) {	//lst_->data_->name_이 name과 같으면
		lst_ = lst_->next_;		//lst_는 lst_->next_가 가리키는 곳과 같은 곳을 가리킴
		delete ptr;		//ptr을 삭제
		return 0;		//기존에 lst_가 가리키던 노드(=ptr이 가리키는 노드) 삭제
	}
	while (ptr->next_ != 0 && ptr->next_->data_->name_ != name) {	//ptr->next_가 0이 아니고, ptr->next_->data_->name_가 name과 다를 때 
		ptr = ptr->next_;											//전진
	}
	if (ptr->next_ == 0) {	//전진하다가 ptr->next_가 0이 되면 끝
		return 0;
	}
	phoneNode* dptr = ptr->next_;	//phoneNode의 포인터 dptr을 새로 선언 후 ptr->next_와 같은 곳을 가리키도록 함
	ptr->next_ = ptr->next_->next_;	//ptr->next_는 ptr->next_->next_와 같은 곳을 가리키도록 함
	delete dptr;	//dptr 삭제
	return 0;
}

phoneData* phoneBook::Find(string name) {
	phoneNode* ptr = lst_;
	if (lst_ == 0) {	//맨처음인 경우
		return 0;
	}
	if (lst_->data_->name_ == name) {	
		return lst_->data_;				//lst_->data_->name_이 name과 같으면
	}									//lst_->data_를 반환
	while (ptr->next_ != 0 && ptr->next_->data_->name_ != name) {	
		ptr = ptr->next_;	//전진
	}
	if (ptr->next_ == 0) {
		return 0;
	}
	return ptr->next_->data_;
}
//
int main() {
	phoneBook* pb = new phoneBook();
	phoneData* pd = new phoneData("someone", "010-2345-6789", "DEU");
	pb->Insert(pd);
	pd = new phoneData("nobody", "010-9876-5432", "DEU");
	pb->Insert(pd);

	pd = pb->Find("someone");
	if (pd) pd->printPD();

	pd = pb->Find("nobody");
	if (pd) pd->printPD();

	pb->Delete("nobody");

	pd = pb->Find("someone");
	if (pd) pd->printPD();
	pd = pb->Find("nobody");
	if (pd) pd->printPD(); 
}
/*
name : someone phone number : 010-2345-6789 address : DEU 
name : nobody phone number : 010-9876-5432 address : DEU 
name : someone phone number : 010-2345-6789 address : DEU
*/
//73라인 출력, 76라인 출력, nobody 삭제 후 someone검색 후 출력, nobody검색 후 출력하지만 삭제됐으므로 출력 내용 x