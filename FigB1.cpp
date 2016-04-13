
#include "stdafx.h"
#include "point.h"
#include "objectB1.h"
#include <iostream>
#include <math.h>

void InOrOutInfo(const CMy2DObjectB1& funct, const CMy2DPoint& par) {
    std::cout << par;
    funct.IsInside(par) ? std::cout << " внутри\n" : std::cout << " снаружи\n";
}

void InOrOutInfo(const CMy2DObjectB1& funct, double x, double y) {
    std::cout << "(" << x << ", " << y << ")";
    funct.IsInside(x, y) ? std::cout << " внутри\n" : std::cout << " снаружи\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Автор: Валентин Левченко\n";
    std::cout << "Группа: БПМ-143\n";
    std::cout << "Вариант: B1\n\n";
    std::cout << "Принятые константы:\n";
    std::cout << "2 / sqrt(5) = " << NUM_C << "\n";
    std::cout << "1 радиан = " << RAD << " градусов\n\n";
    std::cout << "Нажмите:\n";
    std::cout << "'0' - чтобы запустить проверку арифметических операций класса CMy2DPoint;\n";
    std::cout << "'1' - чтобы построить фигуру F1 (используя метод IsInside(double, double));\n";
    std::cout << "'2' - чтобы построить фигуру F2 (используя метод IsInside(const CMy2DPoint&),\n";
    std::cout << "      все методы типа Set(), а также методы Move(double, double) и Rotate());\n";
    std::cout << "'3' - чтобы построить фигуру G (используя методы IsInside(double, double)),\n";
    std::cout << "      Move(const CMy2DPoint&) и Rotate();\n";
    std::cout << "любую другую клавишу - чтобы вручную построить фигуру и проверить пять точек: ";
    
    CMy2DPoint a(3, 5), b(8.2, -6), d(-2.4, 1.1);
    CMy2DPoint t0(4, 3), t1(4, 2.99999), t2(4 + 1 / sqrt(2) , 2 + 1/sqrt(2)), t3(3.99999 + 1 / sqrt(2) , 2 + 1/sqrt(2));
    CMy2DPoint t4(6, 6), t5(6.00001, 6.00001), t6(7.99999, 6.00001), t7(8,6), t8(6, 8), t9(8, 8), t10(7.99999, 8.00001);
    CMy2DPoint t11(4, 8), t12(3.99999, 8.00001), t13(10, 8), t14(10.00001, 8.00001);
    CMy2DPoint t15(10, 5), t16(10, 4.99999), t17(7, 2), t18(7.00001, 2), t19(7, 1.99999), t20(9.99999 - sqrt(4.5), 2 + sqrt(4.5));
    CMy2DPoint t21(1, 5), t22(6, 4), t23(9, 7), t24(5, 7), t25(9, 3), t26(4, 2), t27(7, 7);
    
    CMy2DPoint delta(-3.5, -2.2);
	try{

	CMy2DObjectB1 f(8, 2, 4, 3, 4, 4, 0);
	CMy2DObjectB1 g(6, 2, 2, 1, 5.5, 4.2, 0);
  
    CMy2DObjectB1 myFigure(1, 0, 0, 0, 0.5, 0.5, 0);
    double myA, myA1, myA2, myA3, myAngle;
    CMy2DPoint myCentre, myPointsArray[5];
    
    char key;
    std::cin >> key;
    std::cout << "-----------------------------------------\n";
    switch (key) {
        case '0':
            std::cout << "\nCASE 0\n";
            std::cout << "\na:\t" << a << "\n";
            std::cout << "b:\t" << b << "\n";
            std::cout << "a * b:\t" << a * b << "\n";
            std::cout << "Введите вектор d: ";
            std::cin >> d;
            std::cout << std::endl << "Итак, вектор d:\t" << d << "\n";
            std::cout << "a + d * 5:\t" << a + d * 5 << "\n";
            std::cout << "b / 2 - a:\t" << b / 2 - a << "\n";
            std::cout << "-9 * a:\t\t" << -9 * a << "\n\n";
            break;
        case '1':
            std::cout << "\nCASE 1\n";
            std::cout << "\nФункция F1:\n" << f;
            
            InOrOutInfo(f, 4, 4);
            InOrOutInfo(f, 8, 8);
            std::cout << "\n";
            InOrOutInfo(f, sqrt(4.5), sqrt(4.5));
            InOrOutInfo(f, sqrt(4.5) + 0.00001, sqrt(4.5));
            InOrOutInfo(f, 1, sqrt(8) - 0.00001);
            InOrOutInfo(f, sqrt(8), 1);
            std::cout << "\n";
            InOrOutInfo(f, 0, 4);
            InOrOutInfo(f, 0, 4.00001);
            InOrOutInfo(f, sqrt(8), 8 - sqrt(8));
            InOrOutInfo(f, sqrt(8) - 0.00001, 8 - sqrt(8));
            InOrOutInfo(f, 4, 8);
            InOrOutInfo(f, 3.99999, 8);
            std::cout << "\n";
            InOrOutInfo(f, 6, 3);
            InOrOutInfo(f, 6.00001, 3.00001);
            InOrOutInfo(f, 6, 5);
            InOrOutInfo(f, 6.00001, 4.9999);
            InOrOutInfo(f, 8, 4);
            std::cout << "\n";
            InOrOutInfo(f, 10, 4.5);
            InOrOutInfo(f, -9, 3.5);
            break;
        case '2':
            std::cout << "\nCASE 2\n";
            f.SetA1(2);
            f.SetA2(1);
            f.SetA3(3);
            f.SetA(6);
            f.Move(3, 1);
            f.Rotate(90);
            std::cout << "\nФункция F2:\n" << f;
    
            InOrOutInfo(f, t0);
            InOrOutInfo(f, t1);
            InOrOutInfo(f, t2);
            InOrOutInfo(f, t3);
            std::cout << "\n";
            InOrOutInfo(f, t4);
            InOrOutInfo(f, t5);
            InOrOutInfo(f, t6);
            InOrOutInfo(f, t7);
            InOrOutInfo(f, t8);
            InOrOutInfo(f, t9);
            InOrOutInfo(f, t10);
            std::cout << "\n";
            InOrOutInfo(f, t11);
            InOrOutInfo(f, t12);
            InOrOutInfo(f, t13);
            InOrOutInfo(f, t14);
            std::cout << "\n";
            InOrOutInfo(f, t15);
            InOrOutInfo(f, t16);
            InOrOutInfo(f, t17);
            InOrOutInfo(f, t18);
            InOrOutInfo(f, t19);
            InOrOutInfo(f, t20);
            std::cout << "\n";
            InOrOutInfo(f, t21);
            InOrOutInfo(f, t22);
            InOrOutInfo(f, t23);
            InOrOutInfo(f, t24);
            InOrOutInfo(f, t25);
            InOrOutInfo(f, t26);
            InOrOutInfo(f, t27);
            break;
        case '3':
            std::cout << "\nCASE 3\n";
            g.Move(delta);
            g.Rotate(-135);
            std::cout << "\nФункция G:\n" << g;
        
            InOrOutInfo(g, 0, 0);
            InOrOutInfo(g, -1, -1);
            std::cout << "\n";
            InOrOutInfo(g, 2, 2 - 3 * sqrt(2));
            InOrOutInfo(g, 2, 1.99999 - 3 * sqrt(2));
            InOrOutInfo(g, 2.00001 - 3 * sqrt(2), 2);
            InOrOutInfo(g, 1.99999 - 3 * sqrt(2), 2);
            std::cout << "\n";
            InOrOutInfo(g, 3 * sqrt(2), 0);
            InOrOutInfo(g, 3 * sqrt(2) + 0.00001, 0);
            InOrOutInfo(g, 0, 3 * sqrt(2) - 0.00001);
            InOrOutInfo(g, 0, 3 * sqrt(2) + 0.00001);
            std::cout << "\n";                                              //A1 check
            InOrOutInfo(g, 2 - 1/sqrt(2), 2 - 1/sqrt(2));
            InOrOutInfo(g, 1.99999 - 1/sqrt(2), 1.99999 - 1/sqrt(2));
            std::cout << "\n";                                              //A2 check
            InOrOutInfo(g, 2, 1.99999 + 3 * sqrt(2) - 1);
            InOrOutInfo(g, 2, 2.00001 + 3 * sqrt(2) - 1);
            std::cout << "\n";                                              //A3 check
            InOrOutInfo(g, 1.99999 + 3 * sqrt(2) - 2, 2);
            InOrOutInfo(g, 2.00001 + 3 * sqrt(2) - 2, 2);
            break;
        default:
            std::cout << "\nВВОД ВРУЧНУЮ\n";
            std::cout << "Введите A: ";
            std::cin >> myA;
            myFigure.SetA(myA);
        
            std::cout << "Введите A1: ";
            std::cin >> myA1;
            myFigure.SetA1(myA1);
        
            std::cout << "Введите A2: ";
            std::cin >> myA2;
            myFigure.SetA2(myA2);
        
            std::cout << "Введите A3: ";
            std::cin >> myA3;
            myFigure.SetA3(myA3);
            
            std::cout << "Введите координаты центра: ";
            std::cin >> myCentre;
            myFigure.SetCentre(myCentre);
        
            std::cout << "Введите угол наклона: ";
            std::cin >> myAngle;
            myFigure.SetAngle(myAngle);
            
            std::cout << "\nИнформация о введенной фигуре:\n" << myFigure;
            for (int i = 0; i < 5; i++) {
                std::cout << "Введите точку " << i + 1 << " (осталось " << 4 - i << "): ";
                std::cin >> myPointsArray[i];
                InOrOutInfo(myFigure, myPointsArray[i]);
            }
            break;
    }
        std::cout << "-----------------------------------------\n";
    }
    catch (Error e) {
        std::cout << "Ошибка-исключение " << e.val << ": ";
        switch (e.val) {
            case 0:
                std::cout << "одним из размеров фигуры отрицателен.\n";
                break;
            case 1:
                std::cout << "самоперечение фигуры.\n";
                break;
        }
    }

    std::cout << "Для выхода нажмите любую клавишу: ";
    char x;
    std::cin >> x;

    return 0;
    }