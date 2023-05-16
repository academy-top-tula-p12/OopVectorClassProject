#include "Vector.h"

template<typename T>
inline Vector<T>::Vector()
{
	capacity = 2;
	size = 0;
	items = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(int size)
	: size{ size },
	capacity{ size + size / 2 },
	items{ new T[capacity] } {}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& v)
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->items = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->items[i] = v.items[i];
}

template<typename T>
inline Vector<T>::Vector(Vector<T>&& v) noexcept
{
	this->capacity = v.capacity;
	this->size = v.size;
	this->items = v.items;

	v.items = nullptr;
}

template<typename T>
inline Vector<T>::Vector(T array[], int size)
	: size{ size },
	capacity{ size + size / 2 },
	items{ new T[capacity] }
{
	for (int i = 0; i < this->size; i++)
		this->items[i] = array[i];
}

template<typename T>
Vector<T>::~Vector()
{
	if (this->items)
		delete[] this->items;
}
