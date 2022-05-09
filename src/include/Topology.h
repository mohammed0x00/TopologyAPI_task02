/*
 * Topology.h
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

#ifndef TOPOLOGY_H_
#define TOPOLOGY_H_

/* ------ Include ------ */
#include <vector>
#include "Devices/Device.h"
#include "Devices/Nmos.h"
#include "Devices/Resistor.h"

class Topology {
public:

	/* define required data-types */
	/* A pointer to a device */
	typedef Device * DeviceListElement;
	typedef std::string TopologyIdType;

	/* List of devices
	 * the member list is a pointer to an array of pointers to the devices
	 * to access devices use operator ([] and ->)    eg. list[2]->getId();
	 * */
	typedef struct {
		DeviceListElement * list;
		size_t size;
	} DeviceList;

	/* Public functions */
	Topology(TopologyIdType id);
	virtual ~Topology();

	/* Set the topology ID, returns void */
	void setId(TopologyIdType id);

	/* Returns the device ID of type DeviceIdType */
	TopologyIdType getId();

	/* Add device to the topology */
	void addDevice(Device * dev_ptr);
	void addDevice(Nmos * dev_ptr);
	void addDevice(Resistor * dev_ptr);

	/* Returns a list of devices in the topology
	 * Note : see data-type DeviceList
	 * */
	DeviceList getDevices();


private:
	/* object of type TopologyIdType to store the topology id */
	TopologyIdType id;

	/* Vector to store pointer to the devices in the topology */
	std::vector<DeviceListElement> components;

};

#endif /* TOPOLOGY_H_ */
