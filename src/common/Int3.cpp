#include "Int3.h"


namespace common {

	Int3::Int3() : _x(0), _y(0), _z(0)
	{}
	
	Int3::Int3(const int x, const int y, const int z) : _x(x), _y(y), _z(z)
	{}

	Int3 & Int3::operator=(const Int3 & right)
	{
		_x = right._x;
		_y = right._y;
		_z = right._z;
		return *this;
	}

	Int3 & Int3::operator+(const Int3 & right)
	{
		_x += right._x;
		_y += right._y;
		_z += right._z;
		return *this;
	}
	
	Int3 & Int3::operator-(const Int3 & right)
	{
		_x -= right._x;
		_y -= right._y;
		_z -= right._z;
		return *this;
	}
	
	Int3 & Int3::operator*(const Int3 & right)
	{
		_x *= right._x;
		_y *= right._y;
		_z *= right._z;
		return *this;
	}
	
	Int3 & Int3::operator/(const Int3 & right)
	{
		_x /= right._x;
		_y /= right._y;
		_z /= right._z;
		return *this;
	}
	
	bool Int3::operator==(const Int3 & right)
	{
		return ((_x == right._x) && (_y == right._y) && (_z == right._z));
	}

}
