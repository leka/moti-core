#include "Int3Test.h"

namespace common {

	Int3::testOperatorEqual()
	{
		Int3 a(1, 2, 3);
		Int3 b(3, 4, 5);
		
		a = b;
		
		CPPUNIT_ASSERT_EQUAL(a._x, b._x);
		CPPUNIT_ASSERT_EQUAL(a._y, b._y);
		CPPUNIT_ASSERT_EQUAL(a._z, b._z);
	}
	
	
	testOperatorPlus()
	{}

}
