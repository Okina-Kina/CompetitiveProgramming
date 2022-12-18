#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

//-------------------------------------------------------
/// @brief 
class Vec2{
    public:
        double x, y;

        Vec2():x(0), y(0){}
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

//-------------------------------------------------------
/// @brief 
class Line{

    public:
        Vec2 begin, end;
        Line(){}
        Line(Vec2 begin, Vec2 end){
            this->begin = begin;
            this->end = end;
        }

        /// @brief 
        void show_points(){
            cout << "begin: " <<  begin.x << "/" << begin.y << endl; 
            cout << "end: " <<  end.x << "/" << end.y << endl; 
        }
};

//-------------------------------------------------------
/// @brief 内積
/// @param v1 
/// @param v2 
/// @return 
double calc_dot(Vec2 v1, Vec2 v2){
    return (v1.x * v2.x + v1.y * v2.y);
}

//-------------------------------------------------------
/// @brief 内積
/// @param l1 
/// @param l2 
/// @return 
double calc_product(Line l1, Line l2){
    Vec2 v1 = l1.end - l1.begin;
    Vec2 v2 = l2.end - l2.begin;
    return calc_dot(v1,v2);    
}

//-------------------------------------------------------
/// @brief 外積
/// @param v1 
/// @param v2 
/// @return 
double calc_cross(Vec2 v1, Vec2 v2){
    return (v1.x * v2.y - v1.y * v2.x);
}

//-------------------------------------------------------
/// @brief 外積
/// @param l1 
/// @param l2 
/// @return 
double calc_cross(Line l1, Line l2){
    Vec2 v1 = l1.end - l1.begin;
    Vec2 v2 = l2.end - l2.begin;
    return calc_cross(v1,v2);    
}

//-------------------------------------------------------
//-------------------------------------------------------
/// @brief 
/// @return 
int main(){
    int q;
    cin >> q;

    vector<vector<Line>> lines(q,vector<Line>(2));
    Vec2 begin(Vec2(0,0)), end(Vec2(0,0));

    for(int i = 0; i < q; i++){
        for(int j = 0; j < lines.at(i).size(); j++){
            cin >> begin.x >> begin.y >> end.x >> end.y;
            lines.at(i).at(j) = Line(begin, end);
        }
    }

    for(int i = 0; i < q; i++){        
        if(calc_product(lines.at(i).at(0), lines.at(i).at(1)) == 0) cout << "1" << endl;
        else {
            if(calc_cross(lines.at(i).at(0), lines.at(i).at(1)) == 0) cout << "2" << endl;
            else cout << "0" << endl;
        }
    }
    return 0;
}