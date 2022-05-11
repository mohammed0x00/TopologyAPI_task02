/*******************************************************************************
 * @file    Device.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Device Class source file
 * @note
 *
@verbatim
Copyright (C) 2022

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*****************************************************************************


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
