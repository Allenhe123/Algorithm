#pragma once

#include <vector>
#include <cassert>
#include <iostream>

class MyList
{
public:

	struct Node
	{
		Node(int x): data(x) {}
		int data;
		Node* next = nullptr;
	};

public:
	~MyList()
	{
		while (head_)
		{
			Node* p = head_->next;
			delete head_;
			head_ = p;
		}
	}

	void init(const std::vector<int>& v)
	{
		assert(!v.empty());
		head_ = new Node(v[0]);
		Node* cur = head_;
		for (int i=1; i<v.size(); i++)
		{
			Node* p = new Node(v[i]);
			cur->next = p;
			cur = p;
		}
		cur->next = nullptr;
	}

	friend ostream& operator << (ostream & os, const MyList& lst)
	{
		Node* p = lst.head_;
		while (p != nullptr)
		{
			os << p->data << " ";
			p = p->next;
		}

		return os;
	}
	

	Node* reverse()
	{
		if (head_ == nullptr) return nullptr;
		Node* p = nullptr;
		Node* q = nullptr;
		Node* r = nullptr;
		p = head_;
		q = head_->next;
		head_->next = nullptr;

		while (q)
		{
			r = q->next;
			q->next = p;
			p = q;
			q = r;
		}
		head_ = p;
		return head_;
	}

private:
	Node* head_ = nullptr;
};