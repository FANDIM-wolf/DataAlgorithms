#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        virtual ~Point();
        void set_position(int x , int y , int z){
            x_position = x;
            y_position = y;
            z_position = z;
        }
        int get_position_x(){
            return x_position;
        }
        int get_position_y(){
            return y_position;
        }
        int get_position_z(){
            return z_position;
        }
    protected:

    private:
        int x_position = 0;
        int y_position = 0;
        int z_position = 0;
};

#endif // POINT_H
