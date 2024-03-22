#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* pNext;
	Node();
	Node(T data);
	Node(T* data);
};

template <typename T>
struct LinkedList {
	Node<T>* pHead;
	LinkedList() {
		pHead = nullptr;
	}
	void insertAtHead(T x);
	void insertAtTail(T x);
	void insertOrdered(T x);
	void printList();
	Node<T>* findNode(T x);
	bool deleteNode(T x);
	void deallocate();
};

template <typename T>
Node<T>::Node() {
	this->pNext = nullptr;
}

template <typename T>
Node<T>::Node(T data) {
	this->data = data;
	this->pNext = nullptr;
}

template <typename T>
Node<T>::Node(T* data) {
	this->data = *data;
	this->pNext = nullptr;
}

template <typename T>
void LinkedList<T>::insertAtHead(T x) {
	if (!pHead) {
		pHead = new Node<T>;
		pHead->data = x;
	}
	else {
		Node<T>* cur = pHead;
		while (cur->pNext)
			cur = cur->pNext;
		cur->pNext = new Node<T>;
		cur->pNext->data = x;
	}
}

template <typename T>
void LinkedList<T>::insertAtTail(T x) {
	if (!pHead) {
		pHead = new Node<T>;
		pHead->data = x;
		return;
	}
	Node<T>* cur = pHead;
	while (cur->pNext)
		cur = cur->pNext;
	cur->pNext = new Node<T>;
	cur->pNext->data = x;
}

template <typename T>
void LinkedList<T>::insertOrdered(T x) {
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	if (!pHead) {
		pHead = newNode;
		return;
	}
	if (pHead->data > x) {
		newNode->pNext = pHead;
		pHead = newNode;
		return;
	}
	Node<T>* cur = pHead;
	while (cur->pNext && cur->pNext->data < x)
		cur = cur->pNext;
	newNode->pNext = cur->pNext;
	cur->pNext = newNode;
}

template <typename T>
void LinkedList<T>::printList() {
	Node<T>* cur = pHead;
	while (cur) {
		cout << cur->data << std::endl;
		cur = cur->pNext;
	}
}

template <typename T>
Node<T>* LinkedList<T>::findNode(T x) {
	Node<T>* cur = pHead;
	while (cur && cur->data != x)
		cur = cur->pNext;
	if (!cur)
		cout << "List doesn't have " << x;
	return cur;
}

template <typename T>
bool LinkedList<T>::deleteNode(T x) {
	if (!pHead) {
		return false;
	}
	if (pHead->data == x) {
		Node<T>* tmp = pHead;
		pHead = pHead->pNext;
		return true;
	}
	Node<T>* cur = pHead;
	while (cur->pNext && cur->pNext->data != x)
		cur = cur->pNext;
	if (!cur->pNext) {
		return false;
	}
	Node<T>* tmp = cur->pNext;
	cur->pNext = cur->pNext->pNext;
	delete tmp;
	return true;
}

template <typename T>
void LinkedList<T>::deallocate() {
	while (pHead) {
		Node<T>* delNode = pHead;
		pHead = pHead->pNext;
		delete delNode;
	}
}
