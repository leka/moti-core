#ifndef __ARDUINO_COMMUNICATION__COMMUNICATOR__
#define __ARDUINO_COMMUNICATION__COMMUNICATOR__

#include "IDataListener.h"
#include "DeviceDescriptor.h"

#include "common/Exception.h"

#include <boost/asio.hpp>

#include <vector>
#include <fstream>

namespace arduinocommunication {
	
	/*!
	 * \class Communicator
	 * \brief The communicator communicates with the arduino
	 *        through the usb port and notify the results to 
	 *        the notifiers.
	 */
	class Communicator {
	public:
	
		// Error codes
		
	
		/*!
		 * \fn      Communicator
		 * \brief   Constructor with a specified device descriptor.
		 * \param   deviceDescriptor Give a description of the device.
		 * \remarks The Constructor will iterate through the available
		 *          usb ports and will choose the good one.
		 */
		Communicator(const DeviceDescriptor & deviceDescriptor);
		
		/*!
		 * \fn    ~Communicator
		 * \brief Class destructor. Free the usb connection.
		 */
		~Communicator();
		
		/*!
		 * \fn      addListener
		 * \brief   Add a listener, so the results will be notified to
		 *          the listener.
		 * \remarks The listener must not be destructed before the destruction
		 *          of this class.
		 */
		void addListener(IDataListener * listener);
		
		void getData();
		
	
	private:
	
		/*!
		 * \fn    Communicator
		 * \brief Default constructor. We forbid the construction
		 *        of an empty communicator. It must be instanciated
		 *        with a device descriptor.
		 */
		Communicator();
		
		/*!
		 * The list of the listeners
		 */
		std::vector<IDataListener *> _listenerList;	
		
		/*!
		 * The io_service specific to the class
		 */
		boost::asio::io_service _ioService;
		
		/*!
		 * The serial port
		 */
		boost::asio::serial_port _serialPort;

		/*!
		 * \fn    notify
		 * \brief Notify the listeners
		 */
		void notify(const common::Int3 & acc, const common::Int3 & gyro);
		
	};
	
}


#endif // __ARDUINO_COMMUNICATION__COMMUNICATOR__

