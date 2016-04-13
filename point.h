
#pragma once

#include <iostream>
#include <ostream>

class CMy2DPoint {
public:
    
    CMy2DPoint() : m_x(0), m_y(0) {}
    CMy2DPoint(double par_x, double par_y) : m_x(par_x), m_y(par_y) {}
    CMy2DPoint(const CMy2DPoint& obj) : m_x(obj.m_x), m_y(obj.m_y) {}
    
    CMy2DPoint operator + (const CMy2DPoint& obj) const;
    void operator += (const CMy2DPoint& obj);
    CMy2DPoint operator - (const CMy2DPoint& obj) const;
    double operator * (const CMy2DPoint& obj) const;
    CMy2DPoint operator * (const double par) const ;
    CMy2DPoint operator / (const double par) const;
    bool operator == (const CMy2DPoint& obj) const;
    bool operator != (const CMy2DPoint& obj) const;
    double GetX() const;
    double GetY() const;
    
	friend CMy2DPoint operator * (double par, const CMy2DPoint& obj);
    friend std::ostream& operator << (std::ostream& out, const CMy2DPoint& obj);
    friend std::istream& operator >> (std::istream& in, CMy2DPoint& obj);

public:
    double m_x;
    double m_y;
};
