#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point point_A;

    point_A.set_position(1,2,3);
    int x = point_A.get_position_x();
    cout << "Hello world!" << x << endl;
    return 0;
}
