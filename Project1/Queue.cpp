#include "Header.h"

Queue::Queue()
{
	next = tail = nullptr;
}

Queue::Queue(int a)
{
	next = new Node();
	next->next = next;
	tail = next;
	next->a = a;
}

Queue& Queue::operator=(Queue &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete next;
	next = other.next;
	other.next = nullptr;
}

int Queue::GetSize() const
{
	if (!HasElements()) { return 0; }
	return size;
}

bool Queue::Push(const int a)
{
	Node* newnode = new Node();
	newnode->a = a;
	if (HasElements())
	{	
		newnode->next = tail;
		next->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = next = tail = newnode;
	}
	size++;
	return true;
}

bool Queue::Pop(int &a)
{
	if (!HasElements()) { return false; };
	a = next->a;
	Node* temp = new Node();
	temp = tail;
	if (next == tail)
	{
		delete next;
		next = tail = nullptr;
		size = 0;
		return true;
	}
	while (temp->next != next)
	{
		temp = temp->next;
	}
	size--;
	next = temp;
	next->next = tail;
	return true;
}

bool Queue::Peek(int& a)
{
	if (!HasElements()) { return false; };
	a = next->a;
	return true;
}


bool Queue::HasElements() const
{
	if (this->next != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}