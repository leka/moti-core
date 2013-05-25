#include "arduino-communication/Communicator.h"

using namespace arduinocommunication;

int main(int argc, char * argv[])
{

	DeviceDescriptor desc(9025, 1);

	Communicator comm(desc);
	
	comm.getData();
	comm.getData();
	comm.getData();
	
	return 0;
}
