#include "stdafx.h"
#include "IntArray.h"


int& IntArray::operator[](int index)
{
	return m_array[index];
}

IntArray& IntArray::operator=(const IntArray &array)
{
	if (this == &array)
		return *this;

	delete[] m_array;

	m_array = new int[array.m_length];
	m_length = array.m_length;

	for (int i = 0; i < m_length; ++i)
	{
		m_array[i] = array.m_array[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, IntArray &array)
{
	for (int i = 0; i < array.m_length; ++i)
	{
		out << array.m_array[i]<<" ";
	}
	return out;
}