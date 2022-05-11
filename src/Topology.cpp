/*******************************************************************************
 * @file    Topology.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Topology Class source file
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
#include "Topology.h"

/* ------ Functions ------ */
/* Initialize ID of the topology */
Topology::Topology(TopologyIdType id) {
	this->id = id;
}

/* Deallocate memory space allocated by all devices in the topology */
Topology::~Topology() {
	for(DeviceListElement dev : components)
	{
		delete dev;
	}
}

/* Set the topology ID, returns void */
void Topology::setId(TopologyIdType id)
{
	this->id = id;
}

/* Returns the device ID of type DeviceIdType */
Topology::TopologyIdType Topology::getId()
{
	return id;
}

/* Add Device to the topology */
void Topology::addDevice(Device * dev_ptr)
{
	/* push the device pointer to the vector */
	components.push_back((DeviceListElement)dev_ptr);
}

/* Add Nmos to the topology */
void Topology::addDevice(Nmos * dev_ptr)
{
	/* push the device pointer to the vector */
	components.push_back((DeviceListElement) dev_ptr);
}

/* Add Resistor to the topology */
void Topology::addDevice(Resistor * dev_ptr)
{
	/* push the device pointer to the vector */
	components.push_back((DeviceListElement) dev_ptr);
}

/* Returns a list of devices in the topology
 * Note : see data-type DeviceList
 * */
Topology::DeviceList Topology::getDevices()
{
	/* Read vector data and size then return them as a struct */
	return {components.data(), components.size()};
}
