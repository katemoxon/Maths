#include "Vector2.h"
#include <iostream>

//constructor - with initialiser list that initialises x and y to zero
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

//overloaded constructor takes in two floats to initialise x and y
Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

//destructor - does nothing because no memory allocated in class
Vector2::~Vector2()
{

}

//Addition overload -  returns a new Vector2 that is equal to (THIS + RHS)
Vector2 Vector2::operator+(const Vector2 &rhs) const
{
	Vector2 temp;

	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;

	return temp; //return as a copy as P1 + P2 should return an entirely new Position
}

//Subtraction overload - returns a new Vector2 that is equal to (THIS - RHS)
Vector2 Vector2::operator-(const Vector2 &rhs) const
{
	Vector2 temp;

	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;

	return temp;
}

//Comparison overload - checks to see if Positions are equal, returns true or false
bool Vector2::operator==(const Vector2 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y)
	{
		return true;
	}

	return false;
}

//Inverse comparison overload - checks to see if Positions are m equal, returns true or false
bool Vector2::operator!=(const Vector2 &rhs) const
{
	return !(*this == rhs); //define != in terms of comparison overload - to avoid redefining the same logic
}

//Addition assignment operator - adds RHS to this, returns this as a reference to enable chaining
Vector2& Vector2::operator+=(const Vector2 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

//Subtraction assignment operator - adds RHS to this, returns this as a reference to enable chaining
Vector2& Vector2::operator-=(const Vector2 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

//Multiplication operator overload - multiplies each member of the vector (x and y) by the float passed in
Vector2 Vector2::operator*(const float rhs) const
{
	Vector2 temp(0.0f, 0.0f);

	temp.x = this->x*rhs;
	temp.y = this->y*rhs;

	return temp;
}

//Multiplication assignment operator overload - multiplies (this * float) and assigns the result to this
Vector2& Vector2::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;

	return *this;
}


//overload of std::cout to print out the elements of x and y
std::ostream& operator<<(std::ostream & os, const Vector2 &rhs)
{
	os << "(" << rhs.x << "," << rhs.y << ")";
	return os;
}

//overload of reverse multiplication for instances when you want 10.0f*position
Vector2 operator*(const float lhs, const Vector2& rhs)
{
	return rhs*lhs; //implemented using multiplication operator
}


float Vector2::Magnitude() const
{
	return sqrt((x*x) + (y*y));
}

Vector2 Vector2::Normalise(Vector2 vect) const
{
	vect.x = vect.x / Magnitude();
	vect.y = vect.y / Magnitude();

	return vect;
}

float Vector2::DotProduct(const Vector2 &rhs)
{
	return ((this->x * rhs.x) + (this->y * rhs.x));
}

Vector2 operator*(float input, Vector2 &vInput)
{
	Vector2 vect;
	
	vect.x = vInput.x * input;
	vect.y = vInput.y * input;

	return vect;
}