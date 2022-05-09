/*
 * Device.cpp
 *
 *  Created on: May 5, 2022
 *      Author: mohammed
 */

/* ------ Include ------ */
#include "Devices/Device.h"

/* ------ Functions ------ */
/* Initialize device as undefined */
Device::Device() {
	type = undefined;
}

/* Empty destructor */
Device::~Device() {

}

/* Returns the device ID of type DeviceIdType */
Device::DeviceIdType Device::getID()
{
	return id;
}

/* Set the ID, returns void */
void Device::setID(DeviceIdType id)
{
	this->id = id;
}

/* Returns the type of the device Resistor, Nmos, ...*/
/* Return value is of type enum DeviceType */
Device::DeviceType Device::getType()
{
	return type;
}
