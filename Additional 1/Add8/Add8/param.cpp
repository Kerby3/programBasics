#include "param.hpp"

namespace el
{
	double Parallelogram::Perimetr()
	{
		return 2 * (m_bottom + m_side);
	}

	double Parallelogram::Square()
	{
		return m_side * m_bottom * sin(m_angle);
	}
}
