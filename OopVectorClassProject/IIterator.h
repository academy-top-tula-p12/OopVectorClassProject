#pragma once
#include "Vector.h"

template <class T>
class IIterator
{
public:
	virtual void Set() = 0;
	virtual bool Next() = 0;
	virtual T Current() = 0;
};

template <class T>
class VectorIterator : public IIterator
{
	Vector<T>* vector;
	int indexCurrent;
public:
	VectorIterator(Vector<T>* vector) 
		: vector{ vector }, indexCurrent{ 0 } {};
	
	void Set() override;
	bool Next() override;
	T Current() override;
};

