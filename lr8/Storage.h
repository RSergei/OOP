#pragma once
#include "iostream"
#include "conio.h"
using namespace std;
template<typename T>
class Storage
{
public:
	virtual void Push(T element) = 0; //Вставка (добавление) элемента
	virtual T Pop() = 0; //Удаление (взятие) элемента
	virtual T Peek() = 0; //Просмотр (взятие без удаления) элемента
	virtual bool CheckNoEmptyQueue() = 0; //Проверка наличия элементов
};