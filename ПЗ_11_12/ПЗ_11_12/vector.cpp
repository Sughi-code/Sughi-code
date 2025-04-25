#include <iostream>
using namespace std;
#include <cmath>

/*class Dot {
private:
    double x;
    double y;
public:
    Dot(double x = 0, double y = 0) : x(x), y(y) {};
    ~Dot() = default;
    void SetX(double x) {
        this->x = x;
    }
    void SetY(double y) {
        this->y = y;
    }
    double GetX() { return x; }
    double GetY() { return y; }
};
class Segment {
private:
    Dot start;
    Dot end;
public:
    Segment(Dot p1, Dot p2) : start(p1), end(p2) {};
    ~Segment() = default;
    double Length() {
        double len = sqrt( pow( end.GetX() - start.GetX(), 2) + pow( end.GetY() - start.GetY(), 2));
        return len;
    }
    bool OnLine(Dot p3) {
        bool flag = ((end.GetX() - start.GetX()) / (end.GetX() - p3.GetX()) == (end.GetY() - start.GetY()) / (end.GetY() - p3.GetY()));
        Segment seg1( start, p3), seg2(p3, end);
        //if (seg1.Length() + seg2.Length() == this->Length()) return 1;
        if (flag) return 1;
        else return 0;
    }
};
#include <iostream>

int main() {
    Dot a(0, 0), b;
    double c1, c2, c3, c4;
    std::cin >> c1 >> c2 >> c3 >> c4;
    if (c1 != -1000)
        a.SetX(c1);
    if (c2 != -1000)
        a.SetY(c2);
    if (c3 != -1000)
        b.SetX(c3);
    if (c4 != -1000)
        b.SetY(c4);
    Segment seg(a, b);
    std::cout << seg.Length() << std::endl;
    double c5, c6;
    std::cin >> c5 >> c6;
    std::cout << seg.OnLine(Dot(c5, c6)) << std::endl;
} */