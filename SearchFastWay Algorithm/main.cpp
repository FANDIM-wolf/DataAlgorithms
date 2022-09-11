#include <iostream>
#include <vector>
#include "Point.h"
#include <cmath>

using namespace std;
double generate_random_number(){
    double result = 3 + rand() % 67;
     return result;
}

Point generate_random_point(){

        double x ,y , z ;
        int id = 1 + rand() % 452;
        //get random position
        x = generate_random_number();
        y = generate_random_number();
        z = generate_random_number();
        //create point
        Point point;
        point.set_position(x,y,z);
        // add point in  list
        point.id = id;
        return point;

}

void calculate_root_model(vector<Point> root , vector<Point> points , Point point_A , double fast_distance  ){


    //Point point_A; // start point
    //Point point_C; // end point
    double temporal_x;
    double temporal_y;
    double temporal_z;

    //across all list to find fast distance.

    double distance ;
    double summ , summ_1 , summ_2 , summ_3;



    for (int i = 0 ; i != points.size(); i++){
     cout<<root[i].x_position<<" "<<root[i].y_position<<endl;
     summ_1 =  points[i].x_position; - point_A.x_position;
     summ_2 =  points[i].y_position; - point_A.y_position;
     summ_3 =  points[i].z_position; - point_A.z_position;
     summ_1 = pow(summ_1,2);
     summ_2 = pow(summ_2,2);
     summ_3 = pow(summ_3,2);
     summ = summ_1+summ_2+summ_3;
     cout<<"Summ:"<<summ<<endl;
     cout<<"points:"<<points[i].y_position<<endl;
     distance = sqrt(summ);
     cout<<"Distance:"<<distance<<endl;

     distance = sqrt(summ);
     if(distance < fast_distance){

        fast_distance = distance; // we found closet point.

        cout<<"x:"<<points[i].x_position <<endl;

        root.push_back(points[i]); // add in root .
        cout<<"x root:"<<root[i].x_position <<endl;
        // current point is start point now.
        point_A.x_position = points[i].x_position ;
        point_A.y_position = points[i].y_position ;
        point_A.z_position = points[i].z_position ;
        //remove from points
        points.erase(points.begin() + points[i].id);

        calculate_root_model(root,points,point_A ,fast_distance );


     }

    }





}



int main()
{

    cout<<"SearchFastWay"<<endl;
    vector<Point> root; // points are added in the root

    // create temporal object for searching a closet point.

    double fast_distance = 1000000; // number was taken to initialize search.
    Point point_A;
    point_A.set_id(1);
    point_A.id =1 + rand() % 452324;

    vector<Point> points;
    // add start point in begin of root.
    root.push_back(point_A);
    //generate random amount of points

    for(int i = 0 ; i <= 45 ; i++){
        points.push_back(generate_random_point());

    }

    calculate_root_model(root,points,point_A , fast_distance);


    system("pause");
    return 0;
}
