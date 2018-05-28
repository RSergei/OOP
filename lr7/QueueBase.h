#pragma once

template<typename T>

class QueueBase

{

	virtual int GetSize() = 0;

	virtual void Push(T element) = 0;

	virtual T Pop() = 0;

	virtual T Peek() = 0;

};
