/*
 * Topology.cpp
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

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
