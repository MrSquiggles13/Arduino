#pragma once

#include "Arduino.h"

template<typename T>
class Vector
{
private:

	unsigned m_cap;
	unsigned m_initialCap;
	unsigned m_numOfElem;
	T** m_arr;

	void expand();
	void initialize(unsigned from);

public:

	Vector(unsigned size = 5);
	Vector(const Vector& object);
	~Vector();

	T& operator[](const unsigned index);
	void operator=(const Vector& object);

	unsigned maxCap();
	unsigned size();
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);


};

template<typename T>
Vector<T>::Vector(unsigned size)
{
	m_initialCap = size;
	m_cap = size;
	m_numOfElem = 0;

	m_arr = new T * [m_cap];

	initialize(0);
}

template<typename T>
Vector<T>::Vector(const Vector& object)
{
	m_initialCap = object.m_initialCap;
	m_cap = object.m_cap;
	m_numOfElem = object.m_numOfElem;

	m_arr = new T * [m_cap];

	for (size_t element{ 0 }; element < m_numOfElem; element++)
	{
		m_arr[element] = new T(*object.m_arr[element]);
	}

	initialize(0);
}

template<typename T>
Vector<T>::~Vector()
{
	for (size_t element = 0; element < m_numOfElem; element++)
	{
		delete m_arr[element];
	}
	delete[] m_arr;
}

template<typename T>
T& Vector<T>::operator[](const unsigned index)
{
	if (index < 0 || index >= m_numOfElem)
		;

	return *m_arr[index];
}

template<typename T>
void Vector<T>::operator=(const Vector& object)
{
	for (size_t element = 0; element < m_numOfElem; element++)
	{
		delete m_arr[element];
	}
	delete[] m_arr;

	m_initialCap = object.m_initialCap;
	m_cap = object.m_cap;
	m_numOfElem = object.m_numOfElem;

	m_arr = new T * [m_cap];

	for (size_t element{ 0 }; element < m_numOfElem; element++)
	{
		m_arr[element] = new T(*object.arr[element]);
	}

	initialize(0);
}

template<typename T>
void Vector<T>::expand()
{
	m_cap *= 2;

	T** tempArr = new T * [m_cap];

	for (size_t element{ 0 }; element < m_numOfElem; element++)
	{
		tempArr[element] = m_arr[element];
	}

	delete[] m_arr;

	m_arr = tempArr;

	initialize(m_numOfElem);
}

template<typename T>
void Vector<T>::initialize(unsigned from)
{
	for (size_t element{ 0 }; element < m_cap; element++)
	{
		m_arr[element] = nullptr;
	}
}

template<typename T>
unsigned Vector<T>::maxCap()
{
	return m_cap;
}

template<typename T>
unsigned Vector<T>::size()
{
	return m_numOfElem;
}

template<typename T>
void Vector<T>::push(const T element)
{
	if (m_numOfElem >= m_cap)
		expand();

	m_arr[m_numOfElem++] = new T(element);
}

template<typename T>
void Vector<T>::remove(const unsigned index, bool ordered = false)
{
	if (index < 0 || index >= m_numOfElem)
		;
	if (ordered)
	{
		delete m_arr[index];
		for (size_t element{ 0 }; element < m_numOfElem; element++)
			m_arr[element] = m_arr[element + 1];

		m_arr[--m_numOfElem] = nullptr;
	}
	else
	{
		delete m_arr[index];

		m_arr[index] = m_arr[m_numOfElem - 1];

		m_arr[--m_numOfElem] = nullptr;
	}
}