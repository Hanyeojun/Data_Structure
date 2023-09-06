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

class phoneBook {	//������� ���� ����Ʈ�� ����
public:
	phoneBook();
	bool Insert(phoneData* data);
	phoneData* Delete(string name);
	phoneData* Find(string name);
private:
	phoneNode* lst_;
};
//
phoneData::phoneData(string name, string phoneNumber, string address) {	//�Է¹��� ������ �ʱ�ȭ
	name_ = name;
	phoneNumber_ = phoneNumber;
	address_ = address;
}

void phoneData::printPD() {	//phoneData�� ����ִ� ���� ȭ�鿡 ���
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
		lst_ = new phoneNode(data,0);	//��ó���� next�� ����Ű�°� �����Ƿ� 0��
		return true;
	}
	phoneNode * ptr = lst_;
	while (ptr->next_ != 0 && ptr->next_->data_ < data) {	//ptr�� ����Ű�� next_�� 0�� �ƴϰ�, ptr->next_->data_�� �ּҰ��� ������� data�� �ּҰ����� ���� �� �ݺ�
		ptr = ptr->next_;	//����
	}
	ptr->next_ = new phoneNode(data, ptr -> next_);	//ptr->next�� ���ο� node�� ����µ� �� �ȿ� data�� ptr->next_�� ��
	return true;
}

phoneData* phoneBook::Delete(string name) {
	phoneNode* ptr = lst_;	//phoneNode�� ������ ptr�� lst_�� ���� ���� ����Ŵ
	if (lst_ == 0) {	//����� �����Ƿ� ����
		return 0;
	}
	if (lst_->data_->name_ == name) {	//lst_->data_->name_�� name�� ������
		lst_ = lst_->next_;		//lst_�� lst_->next_�� ����Ű�� ���� ���� ���� ����Ŵ
		delete ptr;		//ptr�� ����
		return 0;		//������ lst_�� ����Ű�� ���(=ptr�� ����Ű�� ���) ����
	}
	while (ptr->next_ != 0 && ptr->next_->data_->name_ != name) {	//ptr->next_�� 0�� �ƴϰ�, ptr->next_->data_->name_�� name�� �ٸ� �� 
		ptr = ptr->next_;											//����
	}
	if (ptr->next_ == 0) {	//�����ϴٰ� ptr->next_�� 0�� �Ǹ� ��
		return 0;
	}
	phoneNode* dptr = ptr->next_;	//phoneNode�� ������ dptr�� ���� ���� �� ptr->next_�� ���� ���� ����Ű���� ��
	ptr->next_ = ptr->next_->next_;	//ptr->next_�� ptr->next_->next_�� ���� ���� ����Ű���� ��
	delete dptr;	//dptr ����
	return 0;
}

phoneData* phoneBook::Find(string name) {
	phoneNode* ptr = lst_;
	if (lst_ == 0) {	//��ó���� ���
		return 0;
	}
	if (lst_->data_->name_ == name) {	
		return lst_->data_;				//lst_->data_->name_�� name�� ������
	}									//lst_->data_�� ��ȯ
	while (ptr->next_ != 0 && ptr->next_->data_->name_ != name) {	
		ptr = ptr->next_;	//����
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
//73���� ���, 76���� ���, nobody ���� �� someone�˻� �� ���, nobody�˻� �� ��������� ���������Ƿ� ��� ���� x