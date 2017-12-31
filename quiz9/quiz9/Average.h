#pragma once
#include <cstdint>
#include <iostream>


class Average
{
	std::int32_t m_sum = 0;
	std::int8_t m_num = 0;
	double m_average = 0.0;

public:
	Average()
	{
	}

	Average& operator+= (int x);
	Average& operator= (const Average &average);
	friend std::ostream& operator<<(std::ostream &out,const Average &average);
};


