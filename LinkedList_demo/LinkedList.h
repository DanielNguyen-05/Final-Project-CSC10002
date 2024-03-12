#pragma once
#include<iostream>

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
	void insertNode(T x); //insert at the end of list
	void printList();
	void deleteNode(T x);
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
void LinkedList<T>::insertNode(T x) {
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
void LinkedList<T>::printList() {
	Node<T>* cur = pHead;
	while (cur) {
		cout << cur->data << std::endl;
		cur = cur->pNext;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(T x) {

}

template <typename T>
void LinkedList<T>::deallocate() {
	while (pHead) {
		Node<T>* delNode = pHead;
		pHead = pHead->pNext;
		delete delNode;
	}
}
