#ifndef __ALGO_MPDIR_H_
#define __ALGO_MPDIR_H_

#include <map>
#include "common/Int2.h"
#include "common/image/ImageIR.h"

// Algorithm definition interface

namespace algompdir {

	class AlgoMPDIR {
	public:
		// Default constructor
		AlgoMPDIR(const int threshold, const int maxElementSize, const int maxElementNumber);
		
		// Destructor
		~AlgoMPDIR();
		
		// execute the algorithm on the input image
		std::map<int, Int2> execute(const ImageIR& image);

		// reset algorithm data
		void reset();

		// Accessors
		int getThreshold();
		void setThreshold(const int threshold);

	private:
		// Cannot be an empty constructor
		AlgoMPDIR();

		// Copy constructor
		// Cannot be instanciated by copy
		AlgoMPDIR(const AlgoMPDIR&);
		
		// Internal constant for distance evaluation
		const int D = 2;
	};

}

#endif // __ALGO_IR_H_