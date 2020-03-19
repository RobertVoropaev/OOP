//
// Created by RobertVoropaev on 05.04.2016.
//

#include "Geometry.h"

/////////////////////////////////////// Vector ///////////////////////////////////////

Vector::Vector(Point s) {
    v_ = s;
}

Vector::Vector(double x1, double y1) {
    v_.x_ = x1;
    v_.y_ = y1;
}

double Vector::crossProduct(Vector A) {
    return v_.x_ * A.v_.y_ - v_.y_ * A.v_.x_;
}

double Vector::dotProduct(Vector A) {
    return v_.x_ * A.v_.x_ + v_.y_ * A.v_.y_;
}

double Vector::length() {
    return sqrt(v_.x_ * v_.x_ + v_.y_ * v_.y_);
}

/////////////////////////////////////// Segment ///////////////////////////////////////

Segment::Segment(Point a, Point b) {
    p1_.x_ = a.x_;
    p1_.y_ = a.y_;
    p2_.x_ = b.x_;
    p2_.y_ = b.y_;
}

Segment::Segment(double a, double b, double c, double d) {
    p1_.x_ = a;
    p1_.y_ = b;
    p2_.x_ = c;
    p2_.y_ = d;
}

bool Segment::belong(Point A) {
    if((A.x_ == p1_.x_ && A.y_ == p1_.y_) || (A.x_ == p2_.x_ && A.y_ == p2_.y_)) {
        return true;
    }
    return (A.x_ <= max(p1_.x_, p2_.x_)) && (A.x_ >= min(p1_.x_, p2_.x_)) && (A.y_ <= max(p1_.y_, p2_.y_)) &&
           (A.y_ >= min(p1_.y_, p2_.y_)) && (((A.x_ - p1_.x_) / (A.y_ - p1_.y_)) == ((p2_.x_ - p1_.x_) / (p2_.y_ - p1_.y_)));
}

bool Segment::belong(Segment A) {
    double x1 = min(p1_.x_, p2_.x_), y1 = min(p1_.y_, p2_.y_);
    double x2 = max(p1_.x_, p2_.x_), y2 = max(p1_.y_, p2_.y_);
    double x3 = min(A.p1_.x_, A.p2_.x_), y3 = min(A.p1_.y_, A.p2_.y_);
    double x4 = max(A.p1_.x_, A.p2_.x_), y4 = max(A.p1_.y_, A.p2_.y_);

    if(!((x2 >= x3) && (x4 >= x1) && (y2 >= y3) && (y4 >= y1))) {
        return false;
    }

    Vector O(p2_.x_ - p1_.x_, p2_.y_ - p1_.y_);
    Vector B(A.p1_.x_ - p1_.x_, A.p1_.y_ - p1_.y_);
    Vector C(A.p2_.x_ - p1_.x_, A.p2_.y_ - p1_.y_);

    if((O.crossProduct(B) * O.crossProduct(C)) <= 0) {
        Vector O(A.p2_.x_ - A.p1_.x_, A.p2_.y_ - A.p1_.y_);
        Vector B(p1_.x_ - A.p1_.x_, p1_.y_ - A.p1_.y_);
        Vector C(p2_.x_ - A.p1_.x_, p2_.y_ - A.p1_.y_);

        if((O.crossProduct(B) * O.crossProduct(C)) <= 0) {
            return true;
        }
    }
    return false;
}

double Segment::distance(Point A) {
    Vector B1(A.x_ - p1_.x_, A.y_ - p1_.y_);
    Vector B2(A.x_ - p2_.x_, A.y_ - p2_.y_);
    Vector C(p2_.x_ - p1_.x_, p2_.y_ - p1_.y_);

    if(B1.length() * B1.length() >= B2.length() * B2.length() + C.length() * C.length()) {
        return B2.length();
    }
    else if(B2.length() * B2.length() >= B1.length() * B1.length() + C.length() * C.length()) {
        return B1.length();
    }
    else {
        double p = (B1.length() + B2.length() + C.length()) / 2;
        double S = sqrt(p * (p - B1.length()) * (p - B2.length()) * (p - C.length()));
        return 2 * S / C.length();
    }
}

/////////////////////////////////////// Circle ///////////////////////////////////////

Circle::Circle(double a, double b, double c) {
    x0_ = a, y0_ = b;
    r_ = c;
}

bool Circle::belong(Point A) {
    return (pow(A.x_ - x0_, 2) + pow(A.y_ - y0_, 2)) == r_ * r_;
}

void Circle::belong(double x1, double y1, double r1) {
    if((x0_ == x1) && (y0_ == y1) && (r_ == r1))
        cout << "3";
    else {
        CircleAndStraight S(x0_, y0_, r_, 2 * (x0_ - x1), 2 * (y0_ - y1),
                            x1 * x1 - x0_ * x0_ + y1 * y1 - y0_ * y0_ + r_ * r_ - r1 * r1);
        S.belong();
    }
}

/////////////////////////////////////// Angle ///////////////////////////////////////

Angle::Angle(Point a, Point b, Point c) {
    a.x_ = a.x_;
    a.y_ = a.y_;
    o_.x_ = b.x_;
    o_.y_ = b.y_;
    b_.x_ = c.x_;
    b_.y_ = c.y_;
}

Angle::Angle(double a1, double a2, double o1, double o2, double b1, double b2) {
    a_.x_ = a1;
    a_.y_ = a2;
    o_.x_ = o1;
    o_.y_ = o2;
    b_.x_ = b1;
    b_.y_ = b2;
}

bool Angle::belong(Point C) {
    Vector N1(a_.x_ - o_.x_, a_.y_ - o_.y_);
    Vector N2(b_.x_ - o_.x_, b_.y_ - o_.y_);
    Vector M(C.x_ - o_.x_, C.y_ - o_.y_);
    return (M.crossProduct(N1) * M.crossProduct(N2) <= 0) && ((M.dotProduct(N1) >= 0) || (M.dotProduct(N2) >= 0)) &&
           (N1.crossProduct(N2) * N1.crossProduct(M) >= 0);
}

/////////////////////////////////////// Straight ///////////////////////////////////////

Straight::Straight(double a, double b, double c) : a_(a), b_(b), c_(c) {}

bool Straight::belong(Point a) {
    return a_ * a.x_ + b_ * a.y_ + c_ == 0;
}

/////////////////////////////////////// Polygon ///////////////////////////////////////

Polygon::Polygon(int a) {
    size_ = a;
    arr_ = new Point[size_];
}

Polygon::Polygon(const Polygon& obj) {
    size_ = obj.size_;
    arr_ = new Point[size_];

    for(int i = 0; i < size_; i++) {
        arr_[i].x_ = obj.arr_[i].x_;
        arr_[i].y_ = obj.arr_[i].y_;
    }
}

Polygon::~Polygon() {
    delete[] arr_;
}

void Polygon::set(int i, double x, double y) {
    arr_[i].x_ = x;
    arr_[i].y_ = y;
}

bool Polygon::convex() {
    bool sign = false;

    for(int i = 0; i < size_; i++) {
        Vector A(arr_[i + 1].x_ - arr_[i].x_, arr_[i + 1].y_ - arr_[i].y_);
        Vector B(arr_[i + 2].x_ - arr_[i + 1].x_, arr_[i + 2].y_ - arr_[i + 1].y_);

        if(A.crossProduct(B) < 0) {
            sign = false;
            break;
        }
        else if(A.crossProduct(B) > 0) {
            sign = true;
            break;
        }
    }

    for(int i = 0; i < size_ - 1; i++) {
        Vector A(arr_[i + 1].x_ - arr_[i].x_, arr_[i + 1].y_ - arr_[i].y_);
        Vector B(arr_[i + 2].x_ - arr_[i + 1].x_, arr_[i + 2].y_ - arr_[i + 1].y_);
        return !((sign && (A.crossProduct(B) < 0)) || (!sign && (A.crossProduct(B) > 0)));
    }

    Vector A(arr_[0].x_ - arr_[size_ - 1].x_, arr_[0].y_ - arr_[size_ - 1].y_);
    Vector B(arr_[1].x_ - arr_[0].x_, arr_[1].y_ - arr_[0].y_);
    return !((sign && (A.crossProduct(B) < 0)) || (!sign && (A.crossProduct(B) > 0)));
}

/////////////////////////////////////// CircleAndStraight ///////////////////////////////////////

CircleAndStraight::CircleAndStraight(double a1, double a2, double a3,
                  double a4, double a5, double a6) :
        Circle(a1, a2, a3),
        Straight(a4, a5, a6) {
}

void CircleAndStraight::belong() {
    if(r_ == 0) {
        if((abs(a_ * x0_ + b_ * y0_ + c_) / (sqrt(a_ * a_ + b_ * b_))) == 0) {
            cout << "1" << endl << x0_ << " " << y0_;
        }
        else {
            cout << "0";
        }
    } else {
        if(a_ == 0) {
            double y = -c_ / b_;
            double D = -y * y + 2 * y0_ * y - y0_ * y0_ + r_ * r_;

            if(D < 0) {
                cout << "0";
            }
            else if(D == 0) {
                cout << "1" << endl << x0_ << " " << y;
            }
            else {
                cout << "2" << endl << x0_ + sqrt(D) << " " << y << endl << x0_ - sqrt(D) << " " << y;
            }
        } else if(b_ == 0) {
            double x = -c_ / a_;
            double D = -x * x + 2 * x * x0_ - x0_ * x0_ + r_ * r_;

            if(D < 0) {
                cout << "0";
            }
            else if(D == 0) {
                cout << "1" << endl << x << " " << y0_;
            }
            else {
                cout << "2" << endl << x << " " << y0_ + sqrt(D) << endl << x << " " << y0_ - sqrt(D);
            }
        } else {
            double D = pow(a_ * c_ - b_ * b_ * x0_ + y0_ * b_ * a_, 2) -
                       (a_ * a_ + b_ * b_) * (c_ * c_ + 2 * y0_ * b_ * c_ - (r_ * r_ - x0_ * x0_ - y0_ * y0_) * b_ * b_);

            if(D < 0) {
                cout << "0";
            }
            else if(D == 0) {
                double x = (a_ * c_ - b_ * b_ * x0_ + y0_ * b_ * a_) / (a_ * a_ + b_ * b_);
                double y = -(a_ * x + c_) / b_;

                cout << "1" << endl << x << " " << y;
            }
            else {
                double x1 = (-(a_ * c_ - b_ * b_ * x0_ + y0_ * b_ * a_) + sqrt(D)) / (a_ * a_ + b_ * b_);
                double y1 = -(a_ * x1 + c_) / b_;
                double x2 = (-(a_ * c_ - b_ * b_ * x0_ + y0_ * b_ * a_) - sqrt(D)) / (a_ * a_ + b_ * b_);
                double y2 = -(a_ * x2 + c_) / b_;

                cout << "2" << endl << x1 << " " << y1 << endl << x2 << " " << y2;
            }
        }

    }
}