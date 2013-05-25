#include "DeviceDescriptor.h"

namespace arduinocommunication {

	DeviceDescriptor::DeviceDescriptor(const int idVendor, const int idProduct) :
		_idVendor(idVendor),
		_idProduct(idProduct)
	{}
	
	int DeviceDescriptor::getIdVendor() const
	{
		return _idVendor;
	}

	int DeviceDescriptor::getIdProduct() const
	{
		return _idProduct;
	}
	
}

