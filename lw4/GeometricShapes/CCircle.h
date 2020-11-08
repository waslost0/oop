
#pragma once
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

#include "CPoint.h"
#include "Const.h"
#include "ISolidShape.h"
#include <cmath>

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint& center, const double radius, const std::string outlineColor, const std::string fillColor);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& iss) const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	double m_radius;

	std::string m_fillColor;
	std::string m_outlineColor;

	CPoint m_center;
};