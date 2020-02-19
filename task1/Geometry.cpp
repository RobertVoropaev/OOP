#include "Geometry.h"

double Vector::crossProduct(Vector A) {
    return vector.x * A.vector.y - vector.y * A.vector.x;
}

double Vector::dotProduct(Vector A) {
    return vector.x * A.vector.x + vector.y * A.vector.y;
}

double Vector::length() {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

bool Segment::belong(Point A) {
    if((A.x == a1.x && A.y == a1.y) || (A.x == a2.x && A.y == a2.y))
        return true;
    return (A.x <= max(a1.x, a2.x)) && (A.x >= min(a1.x, a2.x)) && (A.y <= max(a1.y, a2.y)) &&
           (A.y >= min(a1.y, a2.y)) && (((A.x - a1.x) / (A.y - a1.y)) == ((a2.x - a1.x) / (a2.y - a1.y)));
}

bool Segment::belong(Segment A) {
    double x1 = min(a1.x, a2.x), y1 = min(a1.y, a2.y);
    double x2 = max(a1.x, a2.x), y2 = max(a1.y, a2.y);
    double x3 = min(A.a1.x, A.a2.x), y3 = min(A.a1.y, A.a2.y);
    double x4 = max(A.a1.x, A.a2.x), y4 = max(A.a1.y, A.a2.y);
    if(!((x2 >= x3) && (x4 >= x1) && (y2 >= y3) && (y4 >= y1)))
        return false;
    Vector O(a2.x - a1.x, a2.y - a1.y);
    Vector B(A.a1.x - a1.x, A.a1.y - a1.y);
    Vector C(A.a2.x - a1.x, A.a2.y - a1.y);
    if((O.crossProduct(B) * O.crossProduct(C)) <= 0) {
        Vector O(A.a2.x - A.a1.x, A.a2.y - A.a1.y);
        Vector B(a1.x - A.a1.x, a1.y - A.a1.y);
        Vector C(a2.x - A.a1.x, a2.y - A.a1.y);
        if((O.crossProduct(B) * O.crossProduct(C)) <= 0)
            return true;
    }
    return false;
}

double Segment::distance(Point A) {
    Vector B1(A.x - a1.x, A.y - a1.y);
    Vector B2(A.x - a2.x, A.y - a2.y);
    Vector C(a2.x - a1.x, a2.y - a1.y);
    if(B1.length() * B1.length() >= B2.length() * B2.length() + C.length() * C.length())
        return B2.length();
    else if(B2.length() * B2.length() >= B1.length() * B1.length() + C.length() * C.length())
        return B1.length();
    else {
        double p = (B1.length() + B2.length() + C.length()) / 2;
        double S = sqrt(p * (p - B1.length()) * (p - B2.length()) * (p - C.length()));
        return 2 * S / C.length();
    }
}

bool Circle::belong(Point A) {
    if((pow(A.x - x0, 2) + pow(A.y - y0, 2)) == r * r)
        return true;
    else
        return false;
}

void Circle::belong(double x1, double y1, double r1) {
    if((x0 == x1) && (y0 == y1) && (r == r1))
        cout << "3";
    else {
        CircleAndStraight S(x0, y0, r, 2 * (x0 - x1), 2 * (y0 - y1),
                            x1 * x1 - x0 * x0 + y1 * y1 - y0 * y0 + r * r - r1 * r1);
        S.belong();
    }
}

bool Angle::belong(Point C) {
    Vector N1(A.x - O.x, A.y - O.y);
    Vector N2(B.x - O.x, B.y - O.y);
    Vector M(C.x - O.x, C.y - O.y);
    return (M.crossProduct(N1) * M.crossProduct(N2) <= 0) && ((M.dotProduct(N1) >= 0) || (M.dotProduct(N2) >= 0)) &&
           (N1.crossProduct(N2) * N1.crossProduct(M) >= 0);
}

bool Straight::belong(Point a) {
    return A * a.x + B * a.y + C == 0;
}

Polygon::Polygon(int A) {
    N = A;
    m = new Point[N];
}

Polygon::Polygon(const Polygon& obj) {
    N = obj.N;
    m = new Point[N];
    for(int i = 0; i < N; i++) {
        m[i].x = obj.m[i].x;
        m[i].y = obj.m[i].y;
    }
}

Polygon::~Polygon() {
    delete[]m;
}

void Polygon::set(int i, double x, double y) {
    m[i].x = x;
    m[i].y = y;
}

bool Polygon::convex() {
    bool sign;
    for(int i = 0; i < N; i++) {
        Vector A(m[i + 1].x - m[i].x, m[i + 1].y - m[i].y);
        Vector B(m[i + 2].x - m[i + 1].x, m[i + 2].y - m[i + 1].y);
        if(A.crossProduct(B) < 0) {
            sign = false;
            break;
        } else if(A.crossProduct(B) > 0) {
            sign = true;
            break;
        }
    }
    for(int i = 0; i < N - 1; i++) {
        Vector A(m[i + 1].x - m[i].x, m[i + 1].y - m[i].y);
        Vector B(m[i + 2].x - m[i + 1].x, m[i + 2].y - m[i + 1].y);
        if(sign && (A.crossProduct(B) < 0))
            return false;
        else if(!sign && (A.crossProduct(B) > 0))
            return false;
    }
    Vector A(m[0].x - m[N - 1].x, m[0].y - m[N - 1].y);
    Vector B(m[1].x - m[0].x, m[1].y - m[0].y);
    if(sign && (A.crossProduct(B) < 0))
        return false;
    else if(!sign && (A.crossProduct(B) > 0))
        return false;
    return true;
}

void CircleAndStraight::belong() {
    if(r == 0) {
        if((abs(A * x0 + B * y0 + C) / (sqrt(A * A + B * B))) == 0)
            cout << "1" << endl << x0 << " " << y0;
        else
            cout << "0";
    } else {
        if(A == 0) {
            double y = -C / B;
            double D = -y * y + 2 * y0 * y - y0 * y0 + r * r;
            if(D < 0)
                cout << "0";
            else if(D == 0)
                cout << "1" << endl << x0 << " " << y;
            else {
                cout << "2" << endl << x0 + sqrt(D) << " " << y << endl << x0 - sqrt(D) << " " << y;
            }
        } else if(B == 0) {
            double x = -C / A;
            double D = -x * x + 2 * x * x0 - x0 * x0 + r * r;
            if(D < 0)
                cout << "0";
            else if(D == 0)
                cout << "1" << endl << x << " " << y0;
            else {
                cout << "2" << endl << x << " " << y0 + sqrt(D) << endl << x << " " << y0 - sqrt(D);
            }
        } else {
            double D = pow(A * C - B * B * x0 + y0 * B * A, 2) -
                       (A * A + B * B) * (C * C + 2 * y0 * B * C - (r * r - x0 * x0 - y0 * y0) * B * B);
            if(D < 0)
                cout << "0";
            else if(D == 0) {
                double x = (A * C - B * B * x0 + y0 * B * A) / (A * A + B * B);
                double y = -(A * x + C) / B;
                cout << "1" << endl << x << " " << y;
            } else {
                double x1 = (-(A * C - B * B * x0 + y0 * B * A) + sqrt(D)) / (A * A + B * B);
                double y1 = -(A * x1 + C) / B;
                double x2 = (-(A * C - B * B * x0 + y0 * B * A) - sqrt(D)) / (A * A + B * B);
                double y2 = -(A * x2 + C) / B;
                cout << "2" << endl << x1 << " " << y1 << endl << x2 << " " << y2;
            }
        }

    }
}