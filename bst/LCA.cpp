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
	T lca(Node<T> *h, T key1 ,T key2);
	void eularTour(Node<T> *h);
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
T Bst<T>::lca(Node<T> *h,T key1,T key2)
{
	vector<T> v1,v2;
	int i;
	Node<T> *p = h;
	// fill v1 for key1
	while(1)
	{
		if(h->data == key1)
		{
			v1.push_back(key1);
			break;
		}	
		else if(h->data > key1)
		{
			v1.push_back(h->data);
			h = h->left;
		}
		else
		{
			v1.push_back(h->data);
			h = h->right;
		}
	}

	//fill v2 for key2
	while(1)
	{
		if(p->data == key2)
		{
			v2.push_back(key2);
			break;
		}	
		else if(p->data > key2)
		{
			v2.push_back(p->data);
			p = p->left;
		}
		else
		{
			v2.push_back(p->data);
			p = p->right;
		}
	}
	int ans = 0;
	for(i=0;i<v1.size();i++)
	{
		if(v1[i]!=v2[i])
			break;
		else
			ans=v1[i];
	}
	return ans;
}

//For finding Lca using range minimum query by Applying eular Tour
vector<int> v;
template <class T>
void Bst<T>::eularTour(Node<T> *h)
{
	if(h->left==NULL)
	{
	    v.push_back(h->data);
	    return;
	}
	
	v.push_back(h->data);
	eularTour(h->left);
	v.push_back(h->data);
	if(h->right == NULL)
	{
	    v.push_back(h->data);
	    return;
	}
	eularTour(h->right);
	v.push_back(h->data);
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
	cout << obj.lca(root,3,1) << endl;
	obj.eularTour(root);
	for(int i=0;i<v.size();i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}