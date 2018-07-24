#include "Vector3.h"
#include <iostream>

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{

}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

Vector3::~Vector3()
{

}

Vector3 Vector3::operator+(const Vector3 &rhs) const
{
	Vector3 temp;

	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;
	temp.z = this->z + rhs.z;

	return temp;
}

Vector3 Vector3::operator-(const Vector3 &rhs) const
{
	Vector3 temp;

	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;
	temp.z = this->z - rhs.z;

	return temp;
}

bool Vector3::operator==(const Vector3 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector3::operator!=(const Vector3 &rhs) const
{
	return !(*this == rhs);
}

Vector3& Vector3::operator+=(const Vector3 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

Vector3 Vector3::operator*(const float rhs) const
{
	Vector3 temp(0.0f, 0.0f, 0.0f);

	temp.x = this->x*rhs;
	temp.y = this->y*rhs;
	temp.z = this->z*rhs;

	return temp;
}

Vector3& Vector3::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;

	return *this;
}
Vector3 operator*(const float lhs, const Vector3& rhs)
{
	return rhs*lhs;
}

std::ostream& operator<<(std::ostream & os, const Vector3 &rhs)
{
	os << "(" << rhs.x << "," << rhs.y << "," << rhs.z << ")";
	return os;
}

std::istream& operator>>(std::istream &is, Vector3 &rhs)
{
	is >> rhs.x;
	is >> rhs.y;
	is >> rhs.z;

	return is;
}

float Vector3::Magnitude() const
{
	return sqrt((x*x) + (y*y) + (z*z));
}

float Vector3::DotProduct(Vector3 a_first, Vector3 a_second)
{
	return ((a_first.x * a_second.x) + (a_first.y * a_second.y) + (a_first.z * a_second.z));
}

Vector3 Vector3::CrossProduct(const Vector3& rhs)
{
	Vector3 CrossProduct;

	CrossProduct.x = this->y * rhs.z - this->z * rhs.y;
	CrossProduct.y = this->z * rhs.x - this->x * rhs.z;
	CrossProduct.z = this->x * rhs.y - this->y * rhs.x;

	return CrossProduct;
}

Vector3 Vector3::Normalise(Vector3 vect) const
{
	vect.x = vect.x / Magnitude();
	vect.y = vect.y / Magnitude();
	vect.z = vect.z / Magnitude();

	return vect;
}

Vector3 operator*(float input, Vector3 &vInput)
{
	Vector3 vect;

	vect.x = vInput.x * input;
	vect.y = vInput.y * input;
	vect.z = vInput.z * input;

	return vect;
}