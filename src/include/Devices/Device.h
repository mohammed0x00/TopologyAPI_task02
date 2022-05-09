/*
 * Device.h
 *
 *  Created on: May 5, 2022
 *      Author: mohammed
 */

#ifndef DEVICE_H_
#define DEVICE_H_

/* ------ Include ------ */
#include <string>

class Device {
public:
	/* define required data-types */
	typedef std::string NetlistNode;
	typedef std::string DeviceIdType;
	enum DeviceType {undefined, resistor, nmos};

	/* Public functions */
	Device();
	virtual ~Device();

	/* Returns the device ID of type DeviceIdType */
	DeviceIdType getID();

	/* Set the device ID, returns void */
	void setID(DeviceIdType id);

	/* Returns the type of the device Resistor, Nmos, ...*/
	/* Return value is of type enum DeviceType */
	DeviceType getType();


protected:

	/* declare the netlist object */
	struct Netlist;

	/* Type of the device class */
	DeviceType type;

private:

	/* ID of the device */
	DeviceIdType id;


};

#endif /* DEVICE_H_ */
