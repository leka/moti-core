#ifndef __ARDUINO_COMMUNICATION__COMMUNICATOR__
#define __ARDUINO_COMMUNICATION__COMMUNICATOR__

#include "IDataNotifier.h"
#include "DeviceDescriptor.h"

#include "common/Exception.h"

#include <vector>

// Declaration forward
struct libusb_context;
struct libusb_device;
struct libusb_device_handle;

typedef struct libusb_context        libusb_context;
typedef struct libusb_device         libusb_device;
typedef struct libusb_device_handle  libusb_device_handle;

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
		 * \fn      addNotifier
		 * \brief   Add a notifier, so the results will be notified to
		 *          the notifier.
		 * \remarks The notifier must not be destructed before the destruction
		 *          of this class.
		 */
		void addNotifier(IDataNotifier * notifier);
		
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
		 * The list of the notifiers
		 */
		std::vector<IDataNotifier *> _notifiers;	
		
		/*!
		 * The libusb context specific to the class
		 */
		libusb_context * _context;
		
		/*!
		 * The handle of the device
		 */
		libusb_device_handle * _handle;
		
		/*!
		 * \fn    checkDevice
		 * \brief Check if the device match the descriptor
		 */
		bool checkDevice(libusb_device * device, const DeviceDescriptor & deviceDescriptor);
		
	};
	
}


#endif // __ARDUINO_COMMUNICATION__COMMUNICATOR__

