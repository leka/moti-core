#include "arduino-communication/Communicator.h"

using namespace arduinocommunication;

int main(int argc, char * argv[])
{

	DeviceDescriptor desc("/dev/ttyACM0");

	Communicator comm(desc);
	
	comm.getData();
	comm.getData();
	comm.getData();
	
	return 0;
}
