#include "stdafx.h"
#include "FixPoint2.h"

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &point)
{
	
	out << static_cast<double>(point);
	return out;
}


FixedPoint2::operator double() const
{
	double doubleTemp = static_cast<double>(m_base) + static_cast<double>(m_decimal) / 100;
	return doubleTemp;
}

bool FixedPoint2::operator==(const FixedPoint2 &p2)
{
	if (m_base == p2.m_base && m_decimal == p2.m_decimal)
		return true;
	else
		return false;
}

FixedPoint2 operator+(FixedPoint2 &p1, FixedPoint2 &p2)
{
	return FixedPoint2(static_cast<double>(p1) + static_cast<double>(p2));
}

FixedPoint2& FixedPoint2::operator-()
{
	m_base = -m_base;
	m_decimal = -m_decimal;
	return *this;
}

std::istream& operator >> (std::istream&in, FixedPoint2 &point)
{
	double temp;
	in >> temp;
	point = FixedPoint2(temp);
	return in;
}