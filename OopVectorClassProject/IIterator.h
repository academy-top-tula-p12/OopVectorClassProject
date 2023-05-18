#pragma once
#include "Vector.h"

template <class T>
class IIterator
{
public:
	virtual void Set() = 0;
	virtual void Next() = 0;
	virtual bool IsEnd() = 0;
	virtual T Current() = 0;
};

template <class T>
class Vector;

template <class T>
class VectorIterator : public IIterator<T>
{
	Vector<T>* vector;
	int indexCurrent;
public:
	VectorIterator(Vector<T>* vector);
	
	void Set() override;
	void Next() override;
	bool IsEnd() override;
	T Current() override;
};

template<typename T>
VectorIterator<T>::VectorIterator(Vector<T>* vector)
	: vector{ vector }, indexCurrent{ 0 } {};

template<class T>
inline void VectorIterator<T>::Set()
{
	this->indexCurrent = 0;
}

template<class T>
void VectorIterator<T>::Next()
{
	if (this->indexCurrent < vector->Size())
		indexCurrent++;
}

template<class T>
bool VectorIterator<T>::IsEnd()
{
	return indexCurrent >= vector->Size();
}

template<class T>
T VectorIterator<T>::Current()
{
	return vector->At(indexCurrent);
}

