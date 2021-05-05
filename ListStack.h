#pragma once
#include <iostream>
template<typename T>
class List // класс односв€зный список
{
private:
	class Node // класс хранилище
	{
	public:
		Node(T data = T(), Node* pNext = nullptr); 
		Node* pNext; // переменна€ адреса
		T data; // переменна€ информ
	};
	int size; 
	Node* head; 
	Node* tail; 
public:
	List(); // конструктор
	~List(); // деструктор
	void push_front(T data); // добавл€ет элемент в начало
	void insert(T data, int index); // добавл€ет элемент в указываемое место
	void push_back(T data); //добавл€ем элемент в конец
	T pop_front(); // удал€ет самый первый элемент
	T removeAT(int index); // удал€ет элемент в указываемом месте
	T pop_back(); 
	void clear(); 
	int getsize() const; 
	T sel_el(const int index) const; 
};
template<typename T>
List<T>::Node::Node(T data, Node* pNext)
{
	this->data = data;
	this->pNext = pNext;
}
template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
List<T>::~List() { clear(); }
template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr) // если ещЄ нет ни одного хранилища
	{
		head = tail = new Node(data); // создаЄм первое хранилище
	}
	else
	{
		head = new Node(data, head);
	}
	size++;
}
template<typename T>
void List<T>::insert(T data, int index)
{
	if (index > this->size - 1) 
	{
		std::cout << "”казанный индекс находитс€ вне границ!" << std::endl;
		return T();
	}
	else if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* newNode = new Node(data, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) // если ещЄ нет ни одного хранилища
	{
		head = tail = new Node(data); // создаЄм первое хранилище
	}
	else
	{
		Node* current = this->tail;
		current->pNext = new Node(data);
		tail = current->pNext;
	}
	size++;
}
template<typename T>
T List<T>::pop_front()
{
	Node* temp = head;
	T data = temp->data;
	head = head->pNext;
	delete temp;
	size--;
	return data;
}
template<typename T>
T List<T>::removeAT(int index)
{
	if (index > this->size - 1) 
	{
		std::cout << "”казанный индекс находитс€ вне границ!" << std::endl;
		return T();
	}
	else if (index == 0) 
	{
		return pop_front();
	}
	else
	{
		Node* previous = this->head;  
		for (int i = 0; i < index - 1; i++) 
		{
			previous = previous->pNext;

		}
		Node* toDelete = previous->pNext; // создаЄм указатель на хранилище, которое мы хотим удалить
		if (toDelete->pNext == nullptr)
			tail = previous;
		previous->pNext = toDelete->pNext;
		T data = toDelete->data;
		delete toDelete; // удал€ем хранилище, на которое указали
		size--;
		return data;
	}
}
template<typename T>
T List<T>::pop_back() {
	return removeAT(size - 1);
}
template<typename T>
void List<T>::clear()
{
	while (size) // пока не равно 0
	{
		pop_front();
	}
}
template<typename T>
int List<T>::getsize() const { return size; }
template<typename T>
T List<T>::sel_el(const int index) const
{
	if (index > this->size - 1) 
	{
		std::cout << "”казанный индекс находитс€ вне границ!" << std::endl;
		return T();
	}
	if (index == 0)
		return head->data;
	else if (index == this->size - 1)
		return tail->data;
	else
	{
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}
		return current->data;
	}
}