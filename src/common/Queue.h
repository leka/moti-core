#ifndef __COMMON_QUEUE_H_
#define __COMMON_QUEUE_H_

#include <deque>
#include <boost/thread/shared_mutex.hpp>

namespace common {
	
	/*!
	 * \class Queue
	 * \brief Template representing a thread safe queue
	 */
	template<T>
	class Queue {
	public:
		/*!
		 * \brief  Constructor
		 */
		Queue() : _mutex(), _queue() {}

		/*!
		 * \brief  Pop an element from the list
		 * \return The first element pushed in the list
		 */
		T pop() {
			boost::lock_guard<boost:mutex> lock(_mutex);
			T element = _queue.front();
			_queue.pop_front();
			return element;
		}
		
		/*!
		 * \brief  Push an element in the list
		 */
		void push(T element) {
			boost::lock_guard<boost:mutex> lock(_mutex);
			_queue.push_back(element);
		}

		/*!
		 * \brief  Give the number of element in the queue
		 * \return The number of elements in the queue
		 */
		int size() {
			boost::lock_guard<boost::mutex> lock(_mutex);
			return _queue.size();
		}

	private:
		// Mutex protection for thread safety
		boost::mutex _mutex;
		// Objects in the queue
		std::deque<T> _queue;

		// Copy constructor, not needed
		Queue(const Queue &q);
	};

}

#endif // __COMMON_QUEUE_H_
