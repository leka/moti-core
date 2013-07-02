#ifndef __ARDUINO_COMMUNICATION_CONSOLE__DEBUG_DATA_LISTENER__
#define __ARDUINO_COMMUNICATION_CONSOLE__DEBUG_DATA_LISTENER__

#include "arduino-communication/IDataListener.h"

namespace arduinocommunicationconsole {

	class DebugDataListener : public arduinocommunication::IDataListener {
	public:

		/*!
		 * \fn    DebugDataListener
		 * \brief Constructor
		 */
		DebugDataListener();

		/*!
		 * \fn    virtual ~DebugDataListener
		 * \brief Destructor
		 */
		virtual ~DebugDataListener();

		/*!
		 * \fn virtual void setAcceleration(const common::Int3 & acceleration)
		 */
		virtual void setAcceleration(const common::Int3 & acceleration);
		
		/*!
		 * \fn    virtual void setVolume(const int volume)
		 */
		virtual void setVolume(const int volume);
		
		/*!
		 * \fn    virtual void setGyro(const common::Int3 & gyro)
		 */
		virtual void setGyro(const common::Int3 & gyro);
		
		/*!
		 * \fn    virtual void notify()
		 */
		virtual void notify();
	private:

	};

}

#endif // __ARDUINO_COMMUNICATION_CONSOLE__DEBUG_DATA_LISTENER__