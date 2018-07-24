#include "Vector4.h"
#include <iostream>

//constructor - with initialiser list that initialises x and y to zero
Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), t(0.0f)
{

}

//overloaded constructor takes in two floats to initialise x and y
Vector4::Vector4(float a_x, float a_y, float a_z, float a_t)
{
	x = a_x;
	y = a_y;
	z = a_z;
	t = a_t;
}

//destructor - does nothing because no memory allocated in class
Vector4::~Vector4()
{

}

Vector4 Vector4::operator+(const Vector4 &rhs) const
{
	Vector4 temp;

	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;
	temp.z = this->z + rhs.z;
	temp.t = this->t + rhs.t;

	return temp;
}

Vector4 Vector4::operator-(const Vector4 &rhs) const
{
	Vector4 temp;

	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;
	temp.z = this->z - rhs.z;
	temp.t = this->t - rhs.t;

	return temp;
}

//Comparison overload - checks to see if Positions are equal, returns true or false
bool Vector4::operator==(const Vector4 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->t == rhs.t)
	{
		return true;
	}

	return false;
}

//Inverse comparison overload - checks to see if Positions are m equal, returns true or false
bool Vector4::operator!=(const Vector4 &rhs) const
{
	return !(*this == rhs); //define != in terms of comparison overload - to avoid redefining the same logic
}

//Addition assignment operator - adds RHS to this, returns this as a reference to enable chaining
Vector4& Vector4::operator+=(const Vector4 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->t += rhs.t;
	return *this;
}

//Subtraction assignment operator - adds RHS to this, returns this as a reference to enable chaining
Vector4& Vector4::operator-=(const Vector4 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->t -= rhs.t;

	return *this;
}

//Multiplication operator overload - multiplies each member of the vector (x and y) by the float passed in
Vector4 Vector4::operator*(const float rhs) const
{
	Vector4 temp(0.0f, 0.0f, 0.0f, 0.0f);

	temp.x = this->x*rhs;
	temp.y = this->y*rhs;
	temp.z = this->z*rhs;
	temp.t = this->t*rhs;

	return temp;
}

//Multiplication assignment operator overload - multiplies (this * float) and assigns the result to this
Vector4& Vector4::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->t *= rhs;

	return *this;
}

//overload of reverse multiplication for instances when you want 10.0f*position
Vector4 operator*(const float lhs, const Vector4& rhs)
{
	return rhs*lhs; //implemented using multiplication operator
}

//overload of std::cout to print out the elements of x and y
std::ostream& operator<<(std::ostream & os, const Vector4 &rhs)
{
	os << "(" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.t << ")";
	return os;
}

//overload of std::cin to pass in user items into each element
std::istream& operator>>(std::istream &is, Vector4 &rhs)
{
	is >> rhs.x;
	is >> rhs.y;
	is >> rhs.z;
	is >> rhs.t;

	return is;
}

float Vector4::Magnitude() const
{
	return sqrt((x*x) + (y*y) + (z*z) + (t*t));
}

float Vector4::DotProduct(Vector4 a_first, Vector4 a_second)
{
	return ((a_first.x * a_second.x) + (a_first.y * a_second.y) + (a_first.z * a_second.z) + (a_first.t * a_second.t));
}

Vector4 Vector4::CrossProduct(const Vector4& rhs)
{
	Vector4 CrossProduct;

	CrossProduct.x = this->y * rhs.z - this->z * rhs.y;
	CrossProduct.y = this->z * rhs.x - this->x * rhs.z;
	CrossProduct.z = this->x * rhs.y - this->y * rhs.x;

	return CrossProduct;
}

Vector4 Vector4::Normalise(Vector4 vect) const
{
	vect.x = vect.x / Magnitude();
	vect.y = vect.y / Magnitude();
	vect.z = vect.z / Magnitude();
	vect.t = vect.t / Magnitude();

	return vect;
}

Vector4 operator*(float input, Vector4 &vInput)
{
	Vector4 vect;

	vect.x = vInput.x * input;
	vect.y = vInput.y * input;
	vect.z = vInput.z * input;
	vect.t = vInput.t * input;

	return vect;
}