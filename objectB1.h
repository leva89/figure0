
#pragma once

#include "point.h"
#include <iostream>
#include <math.h>

const double NUM_C = 2 / sqrt(5);
const double PI = 3.141592653589793;
const double RAD = 180 / PI;

class Error {
public:
    Error(int par) : val(par) {}
    int val;
};

class CMy2DObjectB1 {
public:
    CMy2DObjectB1(double a0 = 0, double a1 = 0, double a2 = 0, double a3 = 0, double xC = 0, double yC = 0, double ang = 0) : A(a0), A1(a1), A2(a2), A3(a3), m_centre(xC, yC), m_dAngle(ang) {
        if (A < 0 || A1 < 0 || A2 < 0 || A3 < 0) throw Error(0);
        if (A <= A2 + A3 || A <= A1 + A2 * NUM_C || A <= A1 + A3 * NUM_C) throw Error(1);
    }
    
    double GetA () const;
    double GetA1 () const;
    double GetA2 () const ;
    double GetA3 () const;
    CMy2DPoint GetCentre () const;
    double GetAngle () const;
    void SetA (double par);
    void SetA1 (double par);
    void SetA2 (double par);
    void SetA3 (double par);
    void SetCentre (CMy2DPoint par);
    void SetAngle (double par);
    void Move (double dX, double dY, double dAngle = 0);
    void Move (const CMy2DPoint& delta, double dAngle = 0);
    void Rotate (double dAngle);
    bool IsInside (const CMy2DPoint& point) const;
    bool IsInside (double x, double y) const;
    friend std::ostream& operator << (std::ostream& out, const CMy2DObjectB1& obj);
    
private:
    double A, A1, A2, A3;
    CMy2DPoint m_centre;
    double m_dAngle;
};
