#include "Matrix4.h"
#include <iostream>

Matrix4::Matrix4()
{
	float m_Array[4][4] {
		{ m00, m01, m02, m03 },
		{ m10, m11, m12, m13 },
		{ m20, m21, m22, m23 },
		{ m30, m31, m32, m33 }
	};

	m00 = 1;
	m01 = 0;
	m02 = 0;
	m03 = 0;

	m10 = 0;
	m11 = 1;
	m12 = 0;
	m13 = 0;

	m20 = 0;
	m21 = 0;
	m22 = 1;
	m23 = 0;

	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}

Matrix4::Matrix4(float a00, float a01, float a02, float a03,
	float a10, float a11, float a12, float a13,
	float a20, float a21, float a22, float a23,
	float a30, float a31, float a32, float a33)
{
	m00 = a00;
	m01 = a01;
	m02 = a02;
	m03 = a03;

	m10 = a10;
	m11 = a11;
	m12 = a12;
	m13 = a13;

	m20 = a20;
	m21 = a21;
	m22 = a22;
	m23 = a23;

	m30 = a30;
	m31 = a31;
	m32 = a32;
	m33 = a33;
}

Matrix4::~Matrix4()
{
}

//Matrix4 Matrix4::CreateTranslation(Vector3& a_rhs)
//{
//	Matrix4 temp;
//
//	temp.m03 = a_rhs.x;
//	temp.m13 = a_rhs.y;
//	temp.m23 = a_rhs.z;
//
//	return temp;
//}

void Matrix4::Translation(Vector3& a_rhs)
{
	Matrix4 mat;
	mat.m03 = a_rhs.x;
	mat.m13 = a_rhs.y;
	mat.m23 = a_rhs.z;

	Matrix4 mat2;
	for (int i = 0; i < 16; i++)
	{
		mat2.m[i] = m[i];
	}

	mat2 *= mat;
	for (int i = 0; i < 16; i++)
	{
		m[i] = mat2.m[i];
	}
}

void Matrix4::RotateX(float a_rhs)
{
	Matrix4 mat;
	Matrix4 matRot;

	mat.m11 = cos(a_rhs);
	mat.m12 = -sin(a_rhs);
	mat.m21 = sin(a_rhs);
	mat.m22 = cos(a_rhs);

	for (int i = 0; i <= 16; i++)
	{
		matRot.m[i] = m[i];
	}

	matRot *= mat;

	for (int i = 0; i < 16; i++)
	{
		m[i] = matRot.m[i];
	}
}

void Matrix4::RotateY(float a_rhs)
{
	Matrix4 mat;
	Matrix4 matRot;

	mat.m00 = cos(a_rhs);
	mat.m02 = sin(a_rhs);
	mat.m20 = -sin(a_rhs);
	mat.m22 = cos(a_rhs);

	for (int i = 0; i <= 16; i++)
	{
		matRot.m[i] = m[i];
	}

	matRot *= mat;

	for (int i = 0; i < 16; i++)
	{
		m[i] = matRot.m[i];
	}
}

void Matrix4::RotateZ(float a_rhs)
{
	Matrix4 mat;
	Matrix4 matRot;

	mat.m00 = cos(a_rhs);
	mat.m01 = -sin(a_rhs);
	mat.m10 = sin(a_rhs);
	mat.m11 = cos(a_rhs);

	for (int i = 0; i <= 16; i++)
	{
		matRot.m[i] = m[i];
	}

	matRot *= mat;

	for (int i = 0; i < 16; i++)
	{
		m[i] = matRot.m[i];
	}
}

void Matrix4::Scale(Vector3& a_rhs)
{
	m00 = a_rhs.x;
	m11 = a_rhs.y;
	m22 = a_rhs.z;
}

Matrix4 Matrix4::operator + (const Matrix4& a_rhs) const
{
	Matrix4 mat;

	for (int i = 0; i <= 16; i++)
	{
		mat.m[i] = this->m[i] + a_rhs.m[i];
	}

	return mat;
}

Matrix4 Matrix4::operator - (const Matrix4& a_rhs) const
{
	Matrix4 mat;

	for (int i = 0; i <= 16; i++)
	{
		mat.m[i] = this->m[i] - a_rhs.m[i];
	}

	return mat;
}

Matrix4 Matrix4::operator * (const Matrix4& a_rhs) const
{
	Matrix4 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10 + m02 * a_rhs.m20 + m03 * a_rhs.m30;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11 + m02 * a_rhs.m21 + m03 * a_rhs.m31;
	mat.m02 = m00 * a_rhs.m02 + m01 * a_rhs.m12 + m02 * a_rhs.m22 + m03 * a_rhs.m32;
	mat.m03 = m00 * a_rhs.m03 + m01 * a_rhs.m13 + m02 * a_rhs.m23 + m03 * a_rhs.m33;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10 + m12 * a_rhs.m20 + m13 * a_rhs.m30;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11 + m12 * a_rhs.m21 + m13 * a_rhs.m31;
	mat.m12 = m10 * a_rhs.m02 + m11 * a_rhs.m12 + m12 * a_rhs.m22 + m13 * a_rhs.m32;
	mat.m13 = m10 * a_rhs.m03 + m11 * a_rhs.m13 + m12 * a_rhs.m22 + m13 * a_rhs.m33;

	mat.m20 = m20 * a_rhs.m00 + m21 * a_rhs.m10 + m22 * a_rhs.m20 + m23 * a_rhs.m30;
	mat.m21 = m20 * a_rhs.m01 + m21 * a_rhs.m11 + m22 * a_rhs.m21 + m23 * a_rhs.m31;
	mat.m22 = m20 * a_rhs.m02 + m21 * a_rhs.m12 + m22 * a_rhs.m22 + m23 * a_rhs.m32;
	mat.m23 = m20 * a_rhs.m03 + m21 * a_rhs.m13 + m22 * a_rhs.m23 + m23 * a_rhs.m33;

	mat.m30 = m30 * a_rhs.m00 + m31 * a_rhs.m10 + m32 * a_rhs.m30 + m33 * a_rhs.m30;
	mat.m31 = m30 * a_rhs.m01 + m31 * a_rhs.m11 + m32 * a_rhs.m31 + m33 * a_rhs.m31;
	mat.m32 = m30 * a_rhs.m02 + m31 * a_rhs.m12 + m32 * a_rhs.m32 + m33 * a_rhs.m32;
	mat.m33 = m30 * a_rhs.m03 + m31 * a_rhs.m13 + m33 * a_rhs.m33 + m33 * a_rhs.m33;

	return mat;
}

Vector4 Matrix4::operator * (const Vector4& a_rhs) const
{
	Vector4 vect;

	vect.x = m00 * a_rhs.x + m01 * a_rhs.y + m02 * a_rhs.z + m03 * a_rhs.t;
	vect.y = m10 * a_rhs.x + m11 * a_rhs.y + m12 * a_rhs.z + m13 * a_rhs.t;
	vect.z = m20 * a_rhs.x + m21 * a_rhs.y + m22 * a_rhs.z + m23 * a_rhs.t;
	vect.t = m30 * a_rhs.x + m31 * a_rhs.y + m32 * a_rhs.z + m33 * a_rhs.t;

	return vect;
}

Matrix4 Matrix4::operator += (const Matrix4& a_rhs)
{
	for (int i = 0; i <= 16; i++)
	{
		this->m[i] += a_rhs.m[i];
	}

	return *this;
}

Matrix4 Matrix4::operator -= (const Matrix4& a_rhs)
{
	for (int i = 0; i <= 16; i++)
	{
		this->m[i] -= a_rhs.m[i];
	}

	return *this;
}

Matrix4 Matrix4::operator *= (const Matrix4& a_rhs)
{
	Matrix4 mat;

	mat.m00 = m00 * a_rhs.m00 + m01 * a_rhs.m10 + m02 * a_rhs.m20 + m03 * a_rhs.m30;
	mat.m01 = m00 * a_rhs.m01 + m01 * a_rhs.m11 + m02 * a_rhs.m21 + m03 * a_rhs.m31;
	mat.m02 = m00 * a_rhs.m02 + m01 * a_rhs.m12 + m02 * a_rhs.m22 + m03 * a_rhs.m32;
	mat.m03 = m00 * a_rhs.m03 + m01 * a_rhs.m13 + m02 * a_rhs.m23 + m03 * a_rhs.m33;

	mat.m10 = m10 * a_rhs.m00 + m11 * a_rhs.m10 + m12 * a_rhs.m20 + m13 * a_rhs.m30;
	mat.m11 = m10 * a_rhs.m01 + m11 * a_rhs.m11 + m12 * a_rhs.m21 + m13 * a_rhs.m31;
	mat.m12 = m10 * a_rhs.m02 + m11 * a_rhs.m12 + m12 * a_rhs.m22 + m13 * a_rhs.m32;
	mat.m13 = m10 * a_rhs.m03 + m11 * a_rhs.m13 + m12 * a_rhs.m22 + m13 * a_rhs.m33;

	mat.m20 = m20 * a_rhs.m00 + m21 * a_rhs.m10 + m22 * a_rhs.m20 + m23 * a_rhs.m30;
	mat.m21 = m20 * a_rhs.m01 + m21 * a_rhs.m11 + m22 * a_rhs.m21 + m23 * a_rhs.m31;
	mat.m22 = m20 * a_rhs.m02 + m21 * a_rhs.m12 + m22 * a_rhs.m22 + m23 * a_rhs.m32;
	mat.m23 = m20 * a_rhs.m03 + m21 * a_rhs.m13 + m22 * a_rhs.m23 + m23 * a_rhs.m33;

	mat.m30 = m30 * a_rhs.m00 + m31 * a_rhs.m10 + m32 * a_rhs.m30 + m33 * a_rhs.m30;
	mat.m31 = m30 * a_rhs.m01 + m31 * a_rhs.m11 + m32 * a_rhs.m31 + m33 * a_rhs.m31;
	mat.m32 = m30 * a_rhs.m02 + m31 * a_rhs.m12 + m32 * a_rhs.m32 + m33 * a_rhs.m32;
	mat.m33 = m30 * a_rhs.m03 + m31 * a_rhs.m13 + m33 * a_rhs.m33 + m33 * a_rhs.m33;

	for (int i = 0; i <= 16; i++)
	{
		this->m[i] = mat.m[i];
	}

	return *this;
}