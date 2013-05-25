#ifndef __COMMON_INT2_H_
#define __COMMON_INT2_H_

namespace common {

	class Int2 {
	public:
		// Let public, so they can take any value they want
		int x;
		int y;
		
		Int2() : _x(0), _y(0);
		Int2(const int x, const int y) : _x(x), _y(y);



	};

}

#endif // __COMMON_INT2_H_
