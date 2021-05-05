#pragma once
template <typename T>
class DequeBase
{
public:
	virtual int GetSize() const = 0; // Возвращения кол-ва элементов
	virtual void PushFront(const T& element) = 0; // Вставка (добавление) элемента
	virtual T PopFront() = 0; // Удаление элемента
	virtual void PushBack(const T& element) = 0; // Вставка (добавление) элемента
	virtual T PopBack() = 0; // Удаление элемента
	virtual T PeekFront() const = 0; // Просмотр (взятие без удаления) элемента 
	virtual T PeekBack() const = 0; // Просмотр (взятие без удаления) элемента 
};