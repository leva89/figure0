
#pragma once

#include "stdafx.h"
#include "objectB1.h"
#include <iostream>
#include <math.h>


double mysin(double par) {
    double res = sin(par);
    if (res < pow(10, -10) && res > 0) return 0;
    if (res > -pow(10, -10) && res < 0) return 0;
    return res;
}

double mycos(double par) {
    double res = cos(par);
    if (res < pow(10, -10) && res > 0) return 0;
    if (res > -pow(10, -10) && res < 0) return 0;
    return res;
}

double CMy2DObjectB1::GetA () const {
    return A;
}
    
double CMy2DObjectB1::GetA1 () const {
    return A1;
}
    
double CMy2DObjectB1::GetA2 () const {
    return A2;
}
    
double CMy2DObjectB1::GetA3 () const {
    return A3;
}
    
CMy2DPoint CMy2DObjectB1::GetCentre () const {
    return m_centre;
}
    
double CMy2DObjectB1::GetAngle () const {
    return m_dAngle;
}
    
    
void CMy2DObjectB1::SetA (double par) {
    if (par <= 0) throw Error(0);
    if (par > A2 + A3 && par > A1 + A2 * NUM_C && par > A1 + A3 * NUM_C) A = par;
    else throw Error(1);
}
    
void CMy2DObjectB1::SetA1 (double par) {
    if (par < 0) throw Error(0);
    if (A > par + A2 * NUM_C && A > par + A3 * NUM_C) A1 = par;
    else throw Error(1);
}
    
void CMy2DObjectB1::SetA2 (double par) {
    if (par < 0) throw Error(0);
    if (A > par + A3 && A > A1 + par * NUM_C) A2 = par;
    else throw Error(1);
}
    
void CMy2DObjectB1::SetA3 (double par) {
    if (par < 0) throw Error(0);
    if (A > A2 + par && A > A1 + par * NUM_C) A3 = par;
    else throw Error(1);
}
    
void CMy2DObjectB1::SetCentre (CMy2DPoint par) {
    m_centre = par;
}
    
void CMy2DObjectB1::SetAngle (double par) {
    m_dAngle = par;
}
    
void CMy2DObjectB1::Move (double dX, double dY, double dAngle) {
    CMy2DPoint X(dX, 0), Y(0, dY);
    m_centre += X + Y;
    m_dAngle += dAngle;
}
    
void CMy2DObjectB1::Move (const CMy2DPoint& delta, double dAngle) {
    m_centre += delta;
    m_dAngle += dAngle;
}
    
void CMy2DObjectB1::Rotate (double dAngle) {
    m_dAngle += dAngle;
}
    
bool CMy2DObjectB1::IsInside (const CMy2DPoint& point) const {
    double cenX = m_centre.GetX(), cenY = m_centre.GetY();
    double leftX = cenX - A / 2, rightX = cenX + A / 2, lowY = cenY - A / 2, topY = cenY + A / 2;
    double pX = point.GetX(), pY = point.GetY();
        
    double radius = sqrt((pX - cenX) * (pX - cenX) + (pY - cenY) * (pY - cenY));
    if (radius == 0) return (A1 <= A / 2 && A2 <= A / sqrt(2) && A3 <= A / sqrt(2));
    double cosB = (pX - cenX) / radius, sinB = (pY - cenY) / radius;
    double ang = m_dAngle / RAD;
        
    double x = cenX + radius * (cosB * mycos(ang) + mysin(ang) * sinB);
    double y = cenY + radius * (sinB * mycos(ang) - mysin(ang) * cosB);
        
    if ((x < leftX) || (x > rightX) || (y > topY) || (y < lowY)) return false;              //go on if inside the A square
    if ((x > rightX - A1) && (y < cenY + A1 / 2) && (y > cenY - A1 / 2)) return false;      //go on if outside the A1 square
    if ((x - leftX) * (x - leftX) + (topY - y) * (topY - y) < A2 * A2) return false;        //go on if outside the A2 circle
    if ((x - leftX) * (x - leftX) + (y - lowY) * (y - lowY) < A3 * A3) return false;        //go on if outside the A3 circle
    return true;
}
    
bool CMy2DObjectB1::IsInside (double x, double y) const {
    double cenX = m_centre.GetX(), cenY = m_centre.GetY();
    double leftX = cenX - A / 2, rightX = cenX + A / 2, lowY = cenY - A / 2, topY = cenY + A / 2;
        
    double radius = sqrt((x - cenX) * (x - cenX) + (y - cenY) * (y - cenY));
    if (radius == 0) return (A1 <= A / 2 && A2 <= A / sqrt(2) && A3 <= A / sqrt(2));
    double cosB = (x - cenX) / radius, sinB = (y - cenY) / radius;
    double ang = m_dAngle / RAD;
        
    x = cenX + radius * (cosB * mycos(ang) + mysin(ang) * sinB);
    y = cenY + radius * (sinB * mycos(ang) - mysin(ang) * cosB);
        
    if ((x < leftX) || (x > rightX) || (y > topY) || (y < lowY)) return false;              //go on if inside the A square
    if ((x > rightX - A1) && (y < cenY + A1 / 2) && (y > cenY - A1 / 2)) return false;      //go on if outside the A1 square
    if ((x - leftX) * (x - leftX) + (topY - y) * (topY - y) < A2 * A2) return false;        //go on if outside the A2 circle
    if ((x - leftX) * (x - leftX) + (y - lowY) * (y - lowY) < A3 * A3) return false;        //go on if outside the A3 circle
    return true;
}
       

std::ostream& operator << (std::ostream& out, const CMy2DObjectB1& obj) {
    out << "Размеры: " << obj.A << " * " << obj.A1 << " * " << obj.A2 << " * " << obj.A3 << "\n";
    out << "Центр: " << obj.m_centre << "\nУгол: " << obj.m_dAngle << "\n\n";
    return out;
}

