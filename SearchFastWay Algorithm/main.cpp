#include <iostream>
#include <list>
#include "Point.h"
#include <cmath>

using namespace std;
double generate_random_number(){
     return 1 + rand() % 45;
}

Point generate_random_point(){

        double x ,y , z ;

        //get random position
        x = generate_random_number();
        y = generate_random_number();
        z = generate_random_number();
        //create point
        Point point;
        point.set_position(x,y,z);
        // add point in  list


        // null points
        x = 0 ;
        y = 0 ;
        z = 0 ;


        return point;

}

//generate random amount of points

void generate_points(list<Point> &lst , int amount_points){
    for(int i = 0 ; i <= amount_points ; i++){
        lst.push_front(generate_random_point());
    }
}
list<Point> accros_list(list<Point> &lst , Point point_start ,list<Point> &root , double fast_distance){
    //across all list to find fast distance.
    double distance ;
    double summ , summ_1 , summ_2 , summ_3;
    double temporal_x ;
    double temporal_y ;
    double temporal_z ;

    do {
    for (std::list<Point>::iterator i = lst.begin(); i != lst.end(); ++i){
     temporal_x = i->x_position;
     temporal_y = i->y_position;
     temporal_z = i->z_position;
     summ_1 =  temporal_x - point_start.x_position;
     summ_2 =  temporal_y - point_start.y_position;
     summ_3 =  temporal_z - point_start.z_position;
     summ_1 = pow(summ_1,2);
     summ_2 = pow(summ_2,2);
     summ_3 = pow(summ_3,2);
     summ = summ_1+summ_2+summ_3;
     distance = sqrt(summ);
     if(distance < fast_distance){
        fast_distance = distance; // we found closet point.
        Point point ;
        point.x_position = i->x_position ;
        point.y_position = i->y_position ;
        point.z_position = i->z_position ;
        root.push_front(point); // add in root .
        // current point is start point now.
        point_start.x_position = i->x_position ;
        point_start.y_position = i->y_position ;
        point_start.z_position = i->z_position ;


     }
    }



    }while(lst.size() >= 3);

    return root;
}
int main()
{
    double small_distance = 1000000; // number was taken to initialize search.
    Point point_A; // start point
    Point point_C; // end point
    double temporal_x;
    double temporal_y;
    double temporal_z;
    list <Point>root; // points are added in the root

    // create temporal object for searching a closet point.

    point_A.set_position(1,2,3);
    point_C.set_position(134,23,33);

    list<Point>points;
    // add start point in begin of root.
    root.push_back(point_A);
    generate_points(points ,45);
    //across all list to find fast distance.
    list<Point> full_root = accros_list(points ,point_A ,root ,small_distance);

    for (std::list<Point>::iterator i = full_root.begin(); i != root.end(); ++i){
     temporal_x = i->x_position;
     temporal_y = i->y_position;
     temporal_z = i->z_position;
     cout<<temporal_x<< " " << temporal_y << " " << temporal_z<<endl;
    }

    cout<<full_root.size()<<endl;
    system("pause");
    return 0;
}
