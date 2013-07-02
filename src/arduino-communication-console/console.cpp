#include "arduino-communication/Communicator.h"
#include "DebugDataListener.h"

using namespace arduinocommunication;
using namespace arduinocommunicationconsole;

int main(int argc, char * argv[])
{

	DeviceDescriptor desc("/dev/ttyACM0");

	Communicator comm(desc);

	DebugDataListener debugDataListener;

	comm.addListener(&debugDataListener);
	
	comm.getData();
	comm.getData();
	comm.getData();
	
	return 0;
}
