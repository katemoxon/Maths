#include "Matrix3.h"
#include "Vector2.h"
#include <iostream>

Matrix3::Matrix3()
{
	//float m_Array[3][3] {
	//						{ m00, m01, m02 },
	//						{ m10, m11, m12 },
	//						{ m20, m21, m22 }
	//					};

	m00 = 1;
	m01 = 0;
	m02 = 0;

	m10 = 0;
	m11 = 1;
	m12 = 0;

	m20 = 0;
	m21 = 0;
	m22 = 1;
}

Matrix3::~Matrix3()
{
}

Matrix3::Matrix3(float a00, float a01, float a02,
	float a10, float a11, float a12,
	float a20, float a21, float a22)
{
	m00 = a00;
	m01 = a01;
	m02 = a02;

	m10 = a10;
	m11 = a11;
	m12 = a12;

	m20 = a20;
	m21 = a21;
	m22 = a22;
}

Matrix3 Matrix3::CreateTranslation(Vector2& a_rhs)
{
	Matrix3 temp;

	temp.m02 = a_rhs.x;
	temp.m12 = a_rhs.y;

	return temp;
}

Matrix3 Matrix3::CreateRotation(float a_rot)
{
	Matrix3 temp;

	temp.m00 = cos(a_rot);
	temp.m01 = -sin(a_rot);
	temp.m10 = sin(a_rot);
	temp.m11 = cos(a_rot);

	return temp;
}

Matrix3 Matrix3::CreateScale(Vector2& a_scale)
{
	Matrix3 temp;

	temp.m00 = a_scale.x;
	temp.m11 = a_scale.y;

	return temp;
}

void Matrix3::Translation(Vector2& a_rhs)
{
	Matrix3 mat = CreateTranslation(a_rhs);

	*this *= mat;

	////mat.m02 = a_rhs.x;
	////mat.m12 = a_rhs.y;

	////return mat;
	//mat.m02 = a_rhs.x;
	//mat.m12 = a_rhs.y;

	//Matrix3 mat2;
	//for (int i = 0; i < 9; i++)
	//{
	//	mat2.m[i] = m[i];
	//}

	//mat2 *= mat;
	//for (int i = 0; i < 9; i++)
	//{
	//	m[i] = mat2.m[i];
	//}
}

void Matrix3::Rotate(float a_rhs)
{
	//Matrix3 mat = CreateRotation(a_rhs);

	//*this *= mat;

	Matrix3 mat;
	Matrix3 matRot;

	mat.m00 = cos(a_rhs);
	mat.m01 = -sin(a_rhs);
	mat.m10 = sin(a_rhs);
	mat.m11 = cos(a_rhs);

	for (int i = 0; i <= 9; i++)
	{
		matRot.m[i] = m[i];
	}

	matRot *= mat;

	for (int i = 0; i < 9; i++)
	{
		m[i] = matRot.m[i];
	}
}

void Matrix3::Scale(Vector2& a_rhs)
{
	m00 = a_rhs.x;
	m11 = a_rhs.y;
}

Matrix3 Matrix3::operator + (const Matrix3& a_rhs) const
{
	Matrix3 mat;

	for (int i = 0; i <= 9; i++)
	{
		mat.m[i] = this->m[i] + a_rhs.m[i];
	}

	return mat;
}

Matrix3	Matrix3::operator - (const Matrix3& a_rhs) const
{
	Matrix3 mat;

	for (int i = 0; i <= 9; i++)
	{
		mat.m[i] = this->m[i] - a_rhs.m[i];
	}

	return mat;
}

Matrix3 Matrix3::operator * (const Matrix3& a_rhs) const
{
	Matrix3 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10 + m02 * a_rhs.m20;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11 + m02 * a_rhs.m21;
	mat.m02 = m00 * a_rhs.m02 + m01 * a_rhs.m12 + m02 * a_rhs.m22;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10 + m12 * a_rhs.m20;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11 + m12 * a_rhs.m21;
	mat.m12 = m10 * a_rhs.m02 + m11 * a_rhs.m12 + m12 * a_rhs.m22;

	mat.m20 = m20 * a_rhs.m00 + m21 * a_rhs.m10 + m22 * a_rhs.m20;
	mat.m21 = m20 * a_rhs.m01 + m21 * a_rhs.m11 + m22 * a_rhs.m21;
	mat.m22 = m20 * a_rhs.m02 + m21 * a_rhs.m12 + m22 * a_rhs.m22;

	return mat;
}

Vector3 Matrix3::operator * (const Vector3& a_rhs) const
{
	Vector3 vect;

	vect.x = m00 * a_rhs.x + m01 * a_rhs.y + m02 * a_rhs.z;
	vect.y = m10 * a_rhs.x + m11 * a_rhs.y + m12 * a_rhs.z;
	vect.z = m20 * a_rhs.x + m21 * a_rhs.y + m22 * a_rhs.z;

	return vect;
}

Matrix3 Matrix3::operator += (const Matrix3& a_rhs)
{
	for (int i = 0; i <= 9; i++)
	{
		this->m[i] += a_rhs.m[i];
	}

	return *this;
}

Matrix3 Matrix3::operator -= (const Matrix3& a_rhs)
{
	for (int i = 0; i <= 9; i++)
	{
		this->m[i] -= a_rhs.m[i];
	}

	return *this;
}

Matrix3 Matrix3::operator *= (const Matrix3& a_rhs)
{
	Matrix3 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10 + m02 * a_rhs.m20;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11 + m02 * a_rhs.m21;
	mat.m02 = m00 * a_rhs.m02 + m01 * a_rhs.m12 + m02 * a_rhs.m22;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10 + m12 * a_rhs.m20;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11 + m12 * a_rhs.m21;
	mat.m12 = m10 * a_rhs.m02 + m11 * a_rhs.m12 + m12 * a_rhs.m22;

	mat.m20 = m20 * a_rhs.m00 + m21 * a_rhs.m10 + m22 * a_rhs.m20;
	mat.m21 = m20 * a_rhs.m01 + m21 * a_rhs.m11 + m22 * a_rhs.m21;
	mat.m22 = m20 * a_rhs.m02 + m21 * a_rhs.m12 + m22 * a_rhs.m22;

	for (int i = 0; i <= 9; i++)
	{
		this->m[i] = mat.m[i];
	}

	return *this;
}