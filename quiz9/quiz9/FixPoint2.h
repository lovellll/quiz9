#pragma once
#include <cstdint>
#include <iostream>
#include <cassert>
#include <cmath>

class FixedPoint2
{
	std::int16_t m_base;
	std::int8_t m_decimal;

public:
	FixedPoint2(std::int16_t base=0, std::int8_t decimal=0) :m_base(base), m_decimal(decimal)
	{
		assert(!(decimal < -99 || decimal >99));
		if (m_base < 0 || m_decimal < 0)
		{
			if (m_base > 0)
				m_base = -m_base;
			else if (m_decimal > 0)
				m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double d_number)
	{
		m_base = static_cast<std::int16_t>(d_number);
		m_decimal = static_cast<std::int8_t>(round((d_number - m_base) * 100));
	}

	friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &point);
	friend std::istream& operator >> (std::istream&in, const FixedPoint2 &point);
	operator double() const;
	bool operator==(const FixedPoint2 &p2);
	friend FixedPoint2 operator+(FixedPoint2 &p1, FixedPoint2 &p2);
	FixedPoint2& operator-();
};