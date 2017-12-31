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
	int m_base = p1.m_base + p2.m_base;
	int m_decimal = p1.m_decimal + p2.m_decimal;
	if ((p1.m_base > 0  || p1.m_decimal > 0) && (p2.m_base > 0 || p2.m_decimal  > 0))
	{
		if (m_decimal > 99)
		{
			m_decimal = m_decimal - 100;
			++m_base;
		}
		return FixedPoint2(m_base, m_decimal);
	}
	else if ((p1.m_base < 0 || p1.m_decimal < 0) && (p2.m_base < 0 || p2.m_decimal  < 0))
	{
		if (m_decimal < -99)
		{
			m_decimal = m_decimal + 100;
			--m_base;
		}
		return FixedPoint2(m_base, m_decimal);
	}
	else
	{
		int flag; //ÅÐ¶Ï×óÓÒË­´óË­Ð¡
		if (fabs(p1) > fabs(p2))
			flag = 0;
		else
			flag = 1;

		return FixedPoint2(m_base, m_decimal);
	}
	
}

FixedPoint2& FixedPoint2::operator-()
{
	-m_base;
	-m_decimal;
	return *this;
}