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
double calc_dot(Line l1, Line l2){
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
/// @brief 
/// @param v1 
/// @param v2 
/// @param v3 
/// @return 
int calc_counter_clock_wise(Vec2 v1, Vec2 v2, Vec2 v3){
    if(calc_cross(v2-v1, v3-v1) > 0) return 1;
    if(calc_cross(v2-v1, v3-v1) < 0) return -1;
    if(calc_dot(v2-v1, v3-v1) < 0) return 2;
    if((v2-v1).get_norm() < (v3-v1).get_norm()) return -2;
    return 0;
}

//-------------------------------------------------------
/// @brief 2直線の交点を求める
/// @param l1 
/// @param l2 
/// @return 
Vec2 calc_cross_point(Line l1, Line l2){
    double t = calc_cross(l1.begin - l2.begin, l2.end - l2.begin) / calc_cross(l2.end - l2.begin, l1.end - l1.begin);
    return l1.begin + (l1.end - l1.begin) * t;
}

//-------------------------------------------------------
/// @brief 正射影ベクトル
/// @return 
Vec2 calc_projection(Line l1, Line l2){
    if(calc_dot(l1,l2) != 0) return Vec2(0,0);
    Vec2 p = l1.end - l1.begin;

    double t = calc_dot(l2,l1)/pow(p.get_norm(),2);
    return p * t  + l1.begin;
}

//-------------------------------------------------------
/// @brief 
/// @param p1 
/// @param p2 
/// @return 
double calc_distance(Vec2 p1, Vec2 p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

//-------------------------------------------------------
double calc_distance(Line l1, Line l2){
    if(calc_counter_clock_wise(l1.begin, l1.end, l2.begin) * calc_counter_clock_wise(l1.begin, l1.end, l2.end) <= 0
    && calc_counter_clock_wise(l2.begin, l2.end, l1.begin) * calc_counter_clock_wise(l2.begin, l2.end, l1.end) <= 0)
        return 0;

    double min = 99999999;

    Vec2 p1 = l1.begin + (l1.end - l1.begin) * (calc_dot(l2.begin-l1.begin, l1.end - l1.begin)/ pow((l1.end - l1.begin).get_norm(),2));
    Vec2 p2 = l1.begin + (l1.end - l1.begin) * (calc_dot(l2.end-l1.begin, l1.end - l1.begin)/ pow((l1.end - l1.begin).get_norm(),2));

    // 垂線が下せる場合
    if(calc_dot((l1.end-l1.begin), (p1 - l2.begin)) == 0 
    || calc_dot((l1.end-l1.begin), (p2 - l2.end)) == 0){
        // 平行線上にあるか
        if(calc_cross(p1 - l1.begin, l2.begin-l1.begin) != 0
         ||calc_cross(p2 - l1.begin, l2.end-l1.begin) != 0){
            if(calc_distance(p1, l1.begin) < min) min = calc_distance(p1,l1.begin);
            if(calc_distance(p1, l2.begin) < min) min = calc_distance(p1,l2.begin);
            if(calc_distance(p2, l1.end) < min) min = calc_distance(p2,l1.end);
            if(calc_distance(p2, l2.end) < min) min = calc_distance(p2,l2.end);
        }
    }
    if(calc_distance(l1.begin,l2.begin) < min) min = calc_distance(l1.begin, l2.begin);
    if(calc_distance(l2.end, l1.end) < min) min = calc_distance(l2.end, l1.end);
    if(calc_distance(l2.end, l1.begin) < min) min = calc_distance(l2.end, l1.begin);
    if(calc_distance(l2.begin, l1.end) < min) min = calc_distance(l2.begin,l1.end);

    return min;
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
        Line l1 = lines.at(i).at(0);
        Line l2 = lines.at(i).at(1);

        double dist = calc_distance(l1,l2);
        
        cout << fixed << setprecision(10) << dist << endl;

    }
    return 0;
}