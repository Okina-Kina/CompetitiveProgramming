#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>

#define EPS (1e-10)

using namespace std;

//-------------------------------------------------------
/// @brief 
class Vec2 {
public:
	double x, y;

	Vec2() :x(0.0), y(0.0) {}
	Vec2(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double get_norm() {
		return (pow(this->x, 2) + pow(this->y, 2));
	}

	double get_abs(){
		return sqrt(get_norm());
	}

	Vec2 operator +(Vec2 v) {
		return Vec2(this->x + v.x, this->y + v.y);
	}

	Vec2 operator -(Vec2 v) {
		return Vec2(this->x - v.x, this->y - v.y);
	}

	Vec2 operator *(double value) {
		return Vec2(this->x * value, this->y * value);
	}
};

//-------------------------------------------------------
/// @brief 
class Line {

public:
	Vec2 begin, end;
	Line() {}
	Line(Vec2 begin, Vec2 end) {
		this->begin = begin;
		this->end = end;
	}

	/// @brief 
	void show_points() {
		cout << "begin: " << begin.x << "/" << begin.y << endl;
		cout << "end: " << end.x << "/" << end.y << endl;
	}
};

//-------------------------------------------------------
/// @brief 
enum CCW {
	COUNTER_CLOCKWISE = 1,
	CLOCKWISE = -1,
	ONLINE_BACK = 2,
	ONLINE_FRONT = -2,
	ON_SEGMENT = 0
};

//-------------------------------------------------------
//-------------------------------------------------------
// methods
//-------------------------------------------------------
/// @brief 内積
/// @param v1 
/// @param v2 
/// @return 
double calc_dot(Vec2 v1, Vec2 v2) {
	return (v1.x * v2.x + v1.y * v2.y);
}

//-------------------------------------------------------
/// @brief 内積
/// @param l1 
/// @param l2 
/// @return 
double calc_dot(Line l1, Line l2) {
	Vec2 v1 = l1.end - l1.begin;
	Vec2 v2 = l2.end - l2.begin;
	return calc_dot(v1, v2);
}

//-------------------------------------------------------
/// @brief 外積
/// @param v1 
/// @param v2 
/// @return 
double calc_cross(Vec2 v1, Vec2 v2) {
	return (v1.x * v2.y - v1.y * v2.x);
}

//-------------------------------------------------------
/// @brief 外積
/// @param l1 
/// @param l2 
/// @return 
double calc_cross(Line l1, Line l2) {
	Vec2 v1 = l1.end - l1.begin;
	Vec2 v2 = l2.end - l2.begin;
	return calc_cross(v1, v2);
}

//-------------------------------------------------------
/// @brief 
/// @param v1 
/// @param v2 
/// @param v3 
/// @return 
CCW calc_counter_clock_wise(Vec2 v1, Vec2 v2, Vec2 v3) {
	if (calc_cross(v2 - v1, v3 - v1) > EPS) return COUNTER_CLOCKWISE;  // v2に対してv3反時計回り（v1原点）
	if (calc_cross(v2 - v1, v3 - v1) < -EPS) return CLOCKWISE; // v2に対してv3時計回り（v1原点）
	if (calc_dot(v2 - v1, v3 - v1) < -EPS) return ONLINE_BACK; // v3 < v1 < v2
	if ((v2 - v1).get_abs() + EPS < (v3 - v1).get_abs()) return ONLINE_FRONT; // v1 < v2 < v3
	return ON_SEGMENT; // v1 < v3 < v2
}

//-------------------------------------------------------
/// @brief 2直線の交点を求める
/// @param l1 
/// @param l2 
/// @return 
Vec2 calc_cross_point(Line l1, Line l2) {
	double t = calc_cross(l1.begin - l2.begin, l2.end - l2.begin) / calc_cross(l2.end - l2.begin, l1.end - l1.begin);
	return l1.begin + (l1.end - l1.begin) * t;
}

//-------------------------------------------------------
/// @brief 正射影ベクトル
/// @return 
Vec2 calc_projection(Line line, Vec2 point) {
	Vec2 v = line.end - line.begin;
	double t = calc_dot(point - line.begin, v) / pow(v.get_abs(), 2);

	return v * t + line.begin;
}

//-------------------------------------------------------
/// @brief 交差判定
/// @return 
bool is_intersect(Line l1, Line l2) {
	if (0 < calc_counter_clock_wise(l1.begin, l1.end, l2.begin) * calc_counter_clock_wise(l1.begin, l1.end, l2.end)) return false;
	return calc_counter_clock_wise(l2.begin, l2.end, l1.begin) * calc_counter_clock_wise(l2.begin, l2.end, l1.end) <= 0;
}

//-------------------------------------------------------
/// @brief 直交判定（直線・直線）
/// @param l1 
/// @param l2 
/// @return 
bool is_orthogonal(Line l1, Line l2) {
	return (calc_dot(l1, l2) == 0);
}

//-------------------------------------------------------
/// @brief 直交判定（直線・点）
bool is_orthogonal(Line line, Vec2 point) {
	return (calc_dot(line.end - line.begin, point - line.begin) == 0);
}

//-------------------------------------------------------
/// @brief 平行判定
/// @return 
bool is_parallel(Line l1, Line l2) {
	if (is_orthogonal(l1, l2)) return false;
	return (calc_cross(l1, l2) == 0);
}

//-------------------------------------------------------
/// @brief 2点間の距離
/// @param p1 
/// @param p2 
/// @return 
double calc_distance(Vec2 p1, Vec2 p2) {
	double dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return dist;
}

//-------------------------------------------------------
/// @brief 線と点の距離
/// @param p1 
/// @param p2 
/// @return 
double calc_distance(Line line, Vec2 point) {
	// pointがlineの始点より左にある
	if (calc_dot(line.end - line.begin, point-line.begin) < 0.0) return (point - line.begin).get_abs();
	// pointがlineの始点より右にある
	if (calc_dot(line.begin - line.end, point - line.end) < 0.0) return (point - line.end).get_abs();
	
	Vec2 p = calc_projection(line, point);
	return calc_distance(p, point);
}

//-------------------------------------------------------
/// @brief 線分の端点同士の最小距離を求める
/// @param l1 
/// @param l2 
/// @return 
double calc_distance(Line l1, Line l2) {
	if (is_intersect(l1, l2)) return 0.0;

	return min(min(calc_distance(l1, l2.begin), calc_distance(l1, l2.end)),
		min(calc_distance(l2, l1.begin), calc_distance(l2, l1.end)));
}

//-------------------------------------------------------
//-------------------------------------------------------
/// @brief 
/// @return 
int main() {
	int q;
	cin >> q;

	vector<vector<Line>> lines(q, vector<Line>(2));
	Vec2 begin(Vec2(0, 0)), end(Vec2(0, 0));

	for (int i = 0; i < q; i++) {
		for (int j = 0; j < lines.at(i).size(); j++) {
			cin >> begin.x >> begin.y >> end.x >> end.y;
			lines.at(i).at(j) = Line(begin, end);
		}
	}

	for (int i = 0; i < q; i++) {
		Line l1 = lines.at(i).at(0);
		Line l2 = lines.at(i).at(1);

		double dist = calc_distance(l1, l2);

		cout << fixed << setprecision(10) << dist << endl;

	}
	return 0;
}