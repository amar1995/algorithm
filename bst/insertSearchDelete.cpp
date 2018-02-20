#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
template <class T>
class Bst; 
template <class T>
class Node
{
    friend class Bst<T>;
protected:
	T data;
	Node<T> *left,*right;
public:
	Node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node(T val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
	~Node()
	{

	}
};

template <class T>
class Bst 
{
private:
    
public:
	Bst(){
	}
	~Bst(){
	}
	void insertBst(Node<T> **h,T data);
	bool searchBst(Node<T> *h,T key);
	void deleteBst(Node<T> *h); 
	T successorBst(Node<T> *h);
	T predecessorBst(Node<T> *h);
	void inorderBst(Node<T> *h);
	void preorderBst(Node<T> *h);
	void postorderBst(Node<T> *h);
	void levelorderBst(Node<T> *h);
};

template <class T>
void Bst<T>::insertBst(Node<T> **h,T data)
{
	if((*h) == NULL)
	{
		Node<T> *p = new Node<T>(data);
		*h=p;
		return;
	}
	else
	{
		if((*h)->data > data)
			insertBst(&((*h)->left),data);
		else
			insertBst(&((*h)->right),data);
	}
}
template <class T>
bool Bst<T>::searchBst(Node<T> *h,T key)
{
	if(h ==NULL)
		return false;
	if(key > h->data)
		searchBst(h->right,key);
	else if(key < h->data)
		searchBst(h->left,key);
	else if(key == h->data)
		return true;
}
template <class T>
void Bst<T>::inorderBst(Node<T> *h)
{
	if((h) == NULL)
		return;
	inorderBst(h->left);
	cout << h->data << " ";
	inorderBst(h->right);
}
template <class T>
void Bst<T>::preorderBst(Node<T> *h)
{
	if(h ==  NULL)
		return;
	cout << h->data << " ";
	preorderBst(h->left);
	preorderBst(h->right);
}
template <class T>
void Bst<T>::postorderBst(Node<T> *h)
{
	if(h == NULL)
		return;
	postorderBst(h->left);
	postorderBst(h->right);
	cout << h->data << " ";
}
template <class T>
void Bst<T>::levelorderBst(Node<T> *h)
{
	queue<Node<T> *> q;
	q.push(h);
	while(!q.empty())
	{
		Node<T> *p = q.front();
		q.pop();
		if(p != NULL)
		{
			q.push(p->left);
			q.push(p->right);
			cout << p->data << " ";
		}
	}
}
template <class T>
T Bst<T>::successorBst(Node<T> *h)
{
	if(h->right->left == NULL)
		return h->right->data;
	else
	{
		h=h->right;
		while(h->left !=NULL)
		{
			h=h->left;
		}
		return h->data;
	}
}
template <class T>
T Bst<T>::predecessorBst(Node<T> *h)
{
	if(h->left->right == NULL)
		return h->left->data;
	else
	{
		h=h->left;
		while(h->right !=NULL)
		{
			h=h->right;
		}
		return h->data;
	}
}
int main()
{
    Bst<int> obj;
	Node<int> *root = NULL;
	obj.insertBst(&root,4);
	obj.insertBst(&root,6);
	obj.insertBst(&root,2);
	obj.insertBst(&root,1);
	obj.insertBst(&root,7);
	obj.insertBst(&root,3);
	obj.insertBst(&root,5);
	obj.levelorderBst(root);
	cout << obj.searchBst(root,1) << endl;
	cout << obj.successorBst(root) << endl;
	cout << obj.predecessorBst(root) << endl;
	return 0;
}