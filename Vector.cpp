#include "Vector.h"
#include <iostream>
#include <algorithm>
#include <initializer_list>

template <typename T, size_t N>
Vector<T, N>::Vector()
{
}

template <typename T, size_t N>
Vector<T, N>::Vector(const std::initializer_list<T> &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = *(other.begin() + i);
	}
}

template <typename T, size_t N>
Vector<T, N>::Vector(const Vector &other)
{
	std::cout << 1 << std::endl;
	std::copy(std::begin(other), std::end(other), std::begin(this->_M_elems));
}

template <typename T, size_t N>
T &Vector<T, N>::operator[](size_t index)
{
	return this->_M_elems[index];
}

template <typename T, size_t N>
Vector<T, N>::Vector(Vector &&other)
{
	std::cout << "&&" << std::endl;
}

template <typename T, size_t N>
Vector<T, N> &Vector<T, N>::operator=(const std::initializer_list<T> &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = other[i];
	}
	return this;
}

template <typename T, size_t N>
Vector<T, N> &Vector<T, N>::operator=(const Vector &other)
{
	for (size_t i = 0; i < N; i++)
	{
		this->_M_elems[i] = other[i];
	}
	return this;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] + other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] - other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator*(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] * other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator/(const Vector &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] / other._M_elems[i];
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator+(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] + other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator-(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] - other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator*(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] * other;
	}
	return result;
}

template <typename T, size_t N>
Vector<T, N> Vector<T, N>::operator/(const float &other) const
{
	Vector<T, N> result;
	for (int i = 0; i < N; i++)
	{
		result[i] = this->_M_elems[i] / other;
	}
	return result;
}

int main()
{
	using namespace std;
	const size_t K = 3;
	Vector<int, K> a = {2, 4, 8};
	Vector<int, K> b = a;
	for (int i = 0; i < K; i++)
	{
		cout << a[i] << " " << b[i] << endl;
	}

	return 0;
}