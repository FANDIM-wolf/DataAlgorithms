#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        virtual ~Point();
        int id;
        void set_id(int id){
            id = id;
        }
        void set_position(double x , double y , double z){
            x_position = x;
            y_position = y;
            z_position = z;
        }
        double x_position ;
        double y_position ;
        double z_position ;

    protected:

    private:

};

#endif // POINT_H
