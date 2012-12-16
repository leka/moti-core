#ifndef __IMAGE_H_
#define __IMAGE_H_

#include <cstring>

namespace common::image {

	// Template defining an image
	template <class T>
	class Image<T> {
	public:
		/**
		 * Default constructor, empty object
		 */
		Image() : _height(0), _width(0), _buffer(NULL);
		
		/**
		 * Copy constructor
		 */
		Image(const Image<T>& image) : _height(image.getHeight), _width(image.getWidth() {
			_buffer = new T[height*width];
			memcpy(_buffer, image.getBuffer(), height*width*sizeof(T));
		}
		
		/**
		 * Create an empty image with the specified size
		 */
		Image(const int height, const int width) : _height(height), _width(width), _buffer(new T[height*width]);

		/**
		 * Destructor
		 */
		~Image() {
			delete[] _buffer;
		}

		/**
		 * Get the height of the image
		 */
		int getHeight() const {
			return _height;
		}

		/**
		 * Get the width of the image
		 */
		int getWidth() const {
			return _width;
		}

		/**
		 * Get the value at coordinate (x, y)
		 */
		const T getValue(const int x, const int y) const {
			return _buffer[x * height + y];
		}

		/**
		 * Set the value at coordinate (x, y)
		 */
		void setValue(const int x, const int y, const T& value) {
			_buffer[x * height + y] = T(value);
		}

		/**
		 * Get the buffer of values
		 */
		const T * Image<T>::getBuffer() {
			return &_buffer;
		}

	private:
		int _height;
		int _width;
		T * _buffer;
	};

}

#endif __IMAGE_H_