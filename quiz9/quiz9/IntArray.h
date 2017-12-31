#pragma once
#include <cassert>
#include <iostream>

class IntArray
{
	int *m_array;
	int m_length;

public:
	IntArray(int length):m_length(length)
	{
		assert(length > 0 && "length must be bigger than 0");
		m_array = new int[m_length] {0};
	}

	IntArray(const IntArray& array)
	{
		m_length = array.m_length;
		m_array = new int[m_length] {0};
		for (int i = 0; i < m_length; ++i)
		{
			m_array[i] = array.m_array[i];
		}
	}

	~IntArray()
	{
		delete[] m_array;
	}

	int& operator[](int index);
	IntArray& operator=(const IntArray &array);
	friend std::ostream& operator<<(std::ostream &out, IntArray &array);
};