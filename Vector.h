#include <array>
#include <initializer_list>
#include <cstddef>

template <typename T, size_t N>
class Vector : public std::array<T, N>
{
public:
	Vector() {}

	Vector(const std::initializer_list<T> &other)
	{
		for (size_t i = 0; i < N; i++)
		{
			this->_M_elems[i] = *(other.begin() + i);
		}
	}

	Vector(const Vector &other)
	{
		std::copy(std::begin(other), std::end(other), std::begin(this->_M_elems));
	}

	T &operator[](size_t index)
	{
		return this->_M_elems[index];
	}

	Vector &operator=(const std::initializer_list<T> &other)
	{

		for (size_t i = 0; i < N; i++)
		{
			this->_M_elems[i] = other[i];
		}
		return this;
	}

	Vector &operator=(const Vector &other)
	{

		for (size_t i = 0; i < N; i++)
		{
			this->_M_elems[i] = other[i];
		}
		return this;
	}

	Vector operator+(const Vector &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] + other._M_elems[i];
		}
		return result;
	}

	Vector operator-(const Vector &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] - other._M_elems[i];
		}
		return result;
	}

	Vector operator*(const Vector &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] * other._M_elems[i];
		}
		return result;
	}

	Vector operator/(const Vector &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] / other._M_elems[i];
		}
		return result;
	}

	Vector operator+(const T &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] + other;
		}
		return result;
	}

	Vector operator-(const T &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] - other;
		}
		return result;
	}

	Vector operator*(const T &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] * other;
		}
		return result;
	}

	Vector operator/(const T &other) const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = this->_M_elems[i] / other;
		}
		return result;
	}

	Vector operator-() const
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = -(this->_M_elems[i]);
		}
		return result;
	}

	friend Vector operator+(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value + other[i];
		}
		return result;
	}

	friend Vector operator-(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value - other[i];
		}
		return result;
	}

	friend Vector operator*(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value * other[i];
		}
		return result;
	}

	friend Vector operator/(T value, Vector &other)
	{
		Vector<T, N> result;
		for (size_t i = 0; i < N; i++)
		{
			result[i] = value / other[i];
		}
		return result;
	}
};
