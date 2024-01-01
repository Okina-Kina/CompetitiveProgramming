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

        // 正射影ベクトルの係数
        double k = calc_dot(p-p1, p2-p1) / pow((p2-p1).get_norm(),2);

        // 射影後のベクトル
        Vec2 v = (p2 - p1) * k + p1;

        cout << fixed << setprecision(10)
             << v.x << " " << v.y << endl;
    }

    return 0;
}