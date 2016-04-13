
#pragma once

#include "stdafx.h"
#include "point.h"

CMy2DPoint CMy2DPoint::operator + (const CMy2DPoint& obj) const {
    return CMy2DPoint(m_x + obj.m_x, m_y + obj.m_y);
}
    
void CMy2DPoint::operator += (const CMy2DPoint& obj) {
    m_x += obj.m_x;
    m_y += obj.m_y;
}
    
CMy2DPoint CMy2DPoint::operator - (const CMy2DPoint& obj) const {
    return CMy2DPoint(m_x - obj.m_x, m_y - obj.m_y);
}
    
double CMy2DPoint::operator * (const CMy2DPoint& obj) const {
    double res = m_x * obj.m_x + m_y * obj.m_y;
    return res;
}
    
CMy2DPoint CMy2DPoint::operator * (const double par) const {
    return CMy2DPoint(m_x * par, m_y * par);
}
    
CMy2DPoint CMy2DPoint::operator / (const double par) const {
    return CMy2DPoint(m_x / par, m_y / par);
}
    
bool CMy2DPoint::operator == (const CMy2DPoint& obj) const {
    return (m_x == obj.m_x && m_y == obj.m_y);
}
    
bool CMy2DPoint::operator != (const CMy2DPoint& obj) const {
    return (m_x != obj.m_x || m_y != obj.m_y);
}
    
double CMy2DPoint::GetX() const {
    return m_x;
}
    
double CMy2DPoint::GetY() const {
    return m_y;
}
   
CMy2DPoint operator * (double par, const CMy2DPoint& obj) {
    return CMy2DPoint(obj.m_x * par, obj.m_y * par);
}

std::ostream& operator << (std::ostream& out, const CMy2DPoint& obj) {
    out << "(" << obj.m_x << "; " << obj.m_y << ")";
    return out;
}

std::istream& operator >> (std::istream& in, CMy2DPoint& obj) {
    in >> obj.m_x >> obj.m_y;
    return in;
}
