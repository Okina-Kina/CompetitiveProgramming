#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

class Vec2{
    public:
        double x, y;

        Vec2(double x, double y){
            this->x = x;
            this->y = y;
        }

        double get_norm(){
            return sqrt(pow(this->x,2) + pow(this->y,2));
        }

        Vec2 operator +(Vec2 v){
            return Vec2(this->x + v.x, this->y + v.y);
        }

        Vec2 operator -(Vec2 v){
            return Vec2(this->x - v.x, this->y - v.y);
        }

        Vec2 operator *(double value){
            return Vec2(this->x * value, this->y * value);
        }
};

/// @brief 内積
/// @param v1 
/// @param v2 
/// @return 
double calc_dot(Vec2 v1, Vec2 v2){
    return (v1.x * v2.x + v1.y * v2.y);
}

/// @brief 外積
/// @param v1 
/// @param v2 
/// @return 
double calc_cross(Vec2 v1, Vec2 v2){
    return (v1.x * v2.y - v1.y * v2.x);
}

int main(){

    Vec2 p1(Vec2(0,0)), p2(Vec2(0,0));

    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    int q;
    cin >> q;

    Vec2 p(Vec2(0,0));
    for(int i = 0; i < q; i++){
        double x,y;
        cin >> x >> y;
        p = Vec2(x,y);

        if(0 < calc_cross(p2-p1, p-p1)) cout << "COUNTER_CLOCKWISE" << endl;
        else if(calc_cross(p2-p1, p-p1) < 0) cout << "CLOCKWISE" << endl;
        else {
            if(calc_dot(p-p1,p2-p1) < 0) cout << "ONLINE_BACK" << endl;
            else{
                if( (p2-p1).get_norm() < (p-p1).get_norm() ) cout << "ONLINE_FRONT" << endl;
                else cout << "ON_SEGMENT" << endl;
            }
        }
    }

    return 0;
}