#ifndef __COMMON_INT3_H_
#define __COMMON_INT3_H_

namespace common {

	class Int3 {
	public:
		// Let public, so they can take any value they want
		int _x;
		int _y;
		int _z;
		
		Int3();
		Int3(const int x, const int y, const int z);

		Int3 & operator=(const Int3 & right);
		Int3 & operator+(const Int3 & right);
		Int3 & operator-(const Int3 & right);
		Int3 & operator*(const Int3 & right);
		Int3 & operator/(const Int3 & right);
		
		bool operator==(const Int3 & right);

	};

}

#endif // __COMMON_INT3_H_
