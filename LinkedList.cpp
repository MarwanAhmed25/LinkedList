// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<stdexcept>
using namespace std;
//class Node create nodes of list;
class Node
{
public:
	Node(int v, Node* n = nullptr)
	{
		value = v;
		next = n;
	}
	//setting vlaue of currnt node;
	void setValue(int v)
	{
		value = v;
	}
	//setting next of next node;
	void setNext(Node* n)
	{
		next = n;
	}
	//return vlaue of currnt node;
	int getValue()
	{
		return value;
	}
	//return address of next node;
	Node* getNext()
	{
		return next;
	}
private:
	int value;
	Node* next;
};
//class LinkedList create list of Nodes;
class LinkedList
{
public:
	//constractor of class whitch creat an obect of Node class (head);
	LinkedList(int v)
	{
		tail = new Node(v);
		if (!head)
			head = tail;
	}
	//destractor of class whitch remove all nodes of list;
	~LinkedList()
	{
		ClearAll();
	}
	//adding new node in the last of list;
	void Append(int value)
	{
		node = new Node(value);
		tail->setNext(node);
		tail = node;
	}
	//show all nodes value in list;
	void Display()
	{
		node = head;
		while (node)
		{
			cout << node->getValue() << " ";
			node = node->getNext();
		}
	}
	//insert new node in an indicate index;
	void Insert(int value, int index)
	{
		int counter = Counter();
		Node* insertedNode = new Node(value);
		node = head;
		if (index - 1 > counter)
			cout << "\nOut Of Range\n";
		else if (index - 1 == counter)
		{
			Append(value);
		}
		else
		{
			if (index == 1)
			{
				insertedNode->setNext(head);
				head = insertedNode;
			}
			else
			{
				while ((index - 2) > 0)
				{
					node = node->getNext();
					index--;
				}
				insertedNode->setNext(node->getNext());
				node->setNext(insertedNode);
			}
		}

	}
	//counter for numbers of nodes in list;
	int Counter()
	{
		count = 0;
		node = head;
		while (node)
		{
			count++;
			node = node->getNext();
		}
		return count;
	}
	//clear all node which value = the value send; 
	void Clear(int value)
	{
		node = head;
		while (node->getNext() != nullptr)
		{
			if (head->getValue() == value)
			{
				Node* willRemove = head;
				head = head->getNext();
				delete willRemove;
				return;
			}
			else if (node->getNext()->getValue() == value && node->getNext() != tail)
			{
				Node* willRemove = node->getNext();
				node->setNext(willRemove->getNext());
				delete willRemove;
				return;
			}
			else if (node->getNext()->getValue() == value && node->getNext() == tail)
			{
				Node* willRemove = node->getNext();
				tail = node;
				tail->setNext(nullptr);
				delete willRemove;
				return;
			}
			node = node->getNext();
		}
		cout << "\nnot founded number\n";
	}
	//remove all nodes in list;
	void ClearAll()
	{
		while (head)
		{
			node = head;
			head = head->getNext();
			delete node;
		}
	}
	
private:
	int count;
	Node* head;
	Node* tail;
	Node* node;
};


//main function;
int main()
{
	LinkedList* list1 = new LinkedList(2);
	list1->Append(7);
	list1->Append(3);
	list1->Append(4);
	list1->Append(5);
	//
	LinkedList* list2 = new LinkedList(3);
	list2->Append(1);
	list2->Append(6);
	//
	

}
