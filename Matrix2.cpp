#include "Matrix2.h"
#include <iostream>

Matrix2::Matrix2()
{
	float m_Array[2][2]
	{
		{ m00, m01 },
		{ m10, m11 }
	};

	m_Array[0][0] = 1;
	m_Array[0][1] = 0;

	m_Array[1][0] = 0;
	m_Array[1][1] = 1;
}

Matrix2::Matrix2(float a00, float a01,
	float a10, float a11)
{
	m00 = a00;
	m01 = a01;

	m10 = a10;
	m11 = a11;
}

Matrix2::~Matrix2()
{
}

Matrix2 Matrix2::operator + (const Matrix2& a_rhs) const
{
	Matrix2 mat;

	for (int i = 0; i <= 4; i++)
	{
		mat.m[i] = this->m[i] + a_rhs.m[i];
	}

	return mat;
}

Matrix2 Matrix2::operator - (const Matrix2& a_rhs) const
{
	Matrix2 mat;

	for (int i = 0; i <= 4; i++)
	{
		mat.m[i] = this->m[i] - a_rhs.m[i];
	}

	return mat;
}

Matrix2 Matrix2::operator * (const Matrix2& a_rhs) const
{
	Matrix2 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11;

	return mat;
}

Vector2 Matrix2::operator * (const Vector2& a_rhs) const
{
	Vector2 vect;

	vect.x = m00 * a_rhs.x + m01 * a_rhs.y;
	vect.y = m10 * a_rhs.x + m11 * a_rhs.y;

	return vect;
}

Matrix2 Matrix2::operator += (const Matrix2& a_rhs)
{
	for (int i = 0; i <= 4; i++)
	{
		this->m[i] += a_rhs.m[i];
	}

	return *this;
}

Matrix2 Matrix2::operator -= (const Matrix2& a_rhs)
{
	for (int i = 0; i <= 4; i++)
	{
		this->m[i] -= a_rhs.m[i];
	}

	return *this;
}

Matrix2 Matrix2::operator *= (const Matrix2& a_rhs)
{
	Matrix2 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11;

	for (int i = 0; i <= 4; i++)
	{
		this->m[i] = mat.m[i];
	}

	return *this;
}