#pragma once
#include<iostream>

#define PI acos(-1)

namespace el
{
	class Parallelogram
	{
	public:
		Parallelogram(double bottom, double side, double angle)
		{
			m_bottom = bottom;
			m_side = side;
			m_angle = angle;
			if (m_bottom <= 0 || m_side <= 0 || m_angle <= 0)
			{
				std::cout << "bottom <= 0 or side <= 0 or angle <= 0" << std::endl;
				m_bottom = 1;
				m_side = 1;
				m_angle = 2 * PI / 3;
			}
		}

		~Parallelogram()
		{
		}

		double Perimetr();

		double Square();

	private:
		double m_angle, m_side, m_bottom;
	};
}
