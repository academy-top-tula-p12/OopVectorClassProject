#pragma once
template <typename T>
class Vector
{
	int size;
	int capacity;
	T* items;
public:
	Vector();
	Vector(int size);
	
	Vector(const Vector<T>& v);
	Vector(Vector<T>&& v) noexcept;

	Vector(T array[], int size);

	T& operator[](int index);
	T& At(int index);

	int Size();

	~Vector();
};


