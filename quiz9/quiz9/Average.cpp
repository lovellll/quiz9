#include "stdafx.h"
#include "Average.h"

Average& Average::operator+= (int x)
{
	m_sum += x;
	++m_num;
	m_average = static_cast<double>(m_sum) / m_num;
	return *this;
}

Average& Average::operator= (const Average &average)
{
	m_sum = average.m_sum;
	m_num = average.m_num;
	m_average = average.m_average;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Average &average)
{
	out << average.m_average;
	return out;
}

