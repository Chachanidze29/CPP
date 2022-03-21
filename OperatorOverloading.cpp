#include <iostream>
using namespace std;
class Vector {
	int x, y, z;
public:
	Vector(int a = 2, int b = 3, int c = 4) : x(a), y(b), z(c) {}
	/*Vector operator + (const Vector& vec) {
		Vector tmp;
		tmp.x = this->x + vec.x;
		tmp.y = this->y + vec.y;
		tmp.z = this->z + vec.z;
		return tmp;
	}*/
	friend Vector operator + (const Vector& vec1, const Vector& vec2) {
		Vector tmp;
		tmp.x = vec1.x + vec2.x;
		tmp.y = vec1.y + vec2.y;
		tmp.z = vec1.z + vec2.z;
		return tmp;
	}
	/*Vector operator - (const Vector& vec) {
		Vector tmp;
		tmp.x = this->x - vec.x;
		tmp.y = this->y - vec.y;
		tmp.z = this->z - vec.z;
		return tmp;
	}*/
	friend Vector operator - (Vector& vec1, const Vector& vec2) {
		Vector tmp;
		tmp.x = vec1.x - vec2.x;
		tmp.y = vec1.y - vec2.y;
		tmp.z = vec1.z - vec2.z;
		return tmp;
	}
	//Vector& operator ++ () {
	//	this->x++; this->y++; this->z++;
	//	return *this;
	//}
	friend Vector& operator ++ (Vector& vec) {
		vec.x++; vec.y++; vec.z++;
		return vec;
	}
	/*Vector operator ++ (int) {
		Vector tmp(*this);
		this->x++; this->y++; this->z++;
		return tmp;
	}*/
	friend Vector operator ++ (Vector& vec, int) {
		Vector tmp(vec);
		vec.x++; vec.y++; vec.z++;
		return tmp;
	}
	/*bool operator == (const Vector& vec) {
		return this->x == vec.x && this->y == vec.y && this->z == vec.z;
	}*/
	friend bool operator == (const Vector& vec1, const Vector& vec2) {
		return vec1.x == vec2.x && vec1.y == vec2.y && vec1.z == vec2.z;
	}
	/*ostream& operator << (ostream& out) {
		out << this->x<< ' ' << this->y<< ' ' << this->z << endl;
		return out;
	}*/
	friend ostream& operator << (ostream& out, const Vector& obj) {
		out << obj.x << ' ' << obj.y << ' ' << obj.z << endl;
		return out;
	}
	/*istream& operator >> (istream& in) {
		in >> this->x >> this->y >> this->z;
		return in;
	}*/
	friend istream& operator >> (istream& in, Vector& obj) {
		in >> obj.x >> obj.y >> obj.z;
		return in;
	}
	/*Vector& operator -=(const int& num) {
		this->x -= num;
		this->y -= num;
		this->z -= num;
		return *this;
	}*/
	friend Vector& operator -= (Vector& vec, const int& num) {
		vec.x -= num;
		vec.y -= num;
		vec.z -= num;
		return vec;
	}
	/*Vector& operator -= (const Vector& vec) {
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		return *this;
	}*/
	friend Vector& operator -= (Vector& vec1, const Vector& vec2) {
		vec1.x -= vec2.x;
		vec1.y -= vec2.y;
		vec1.z -= vec2.z;
		return vec1;
	}
	friend Vector& operator - (const Vector& vec) {
		Vector tmp;
		tmp.x = -vec.x;
		tmp.y = -vec.y;
		tmp.z = -vec.z;
		return tmp;
	}
	/*Vector& operator - () {
		Vector tmp;
		tmp.x = -this->x;
		tmp.y = -this->y;
		tmp.z = -this->z;
		return tmp;
	}*/

};
int main() {
	Vector a, b;
}