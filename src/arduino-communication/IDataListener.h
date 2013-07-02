#ifndef __ARDUINO_COMMUNICATION__I_DATA_LISTENER__
#define __ARDUINO_COMMUNICATION__I_DATA_LISTENER__

#include "common/Int3.h"

namespace arduinocommunication {

	/*!
	 * \class IDataListener
	 * \brief This interface must be implemented by class who wants
	 *        to receive the data from the communication manager.
	 */
	class IDataListener {
	public:
	
		/*!
		 * \fn    setAcceleration
		 * \brief set the acceleration value
		 */
		virtual void setAcceleration(const common::Int3 & acceleration) = 0;
		
		/*!
		 * \fn    setVolume
		 * \brief set the volume value
		 */
		virtual void setVolume(const int volume) = 0;
		
		/*!
		 * \fn    setGyro
		 * \brief set the gyro value
		 */
		virtual void setGyro(const common::Int3 & gyro) = 0;
		
		/*!
		 * \fn    notify
		 * \brief Tells the data notifier that data have been set
		 *        and can therefore process the data
		 */
		virtual void notify() = 0;
	
	};



}

#endif // __ARDUINO_COMMUNICATION__I_DATA_LISTENER__

