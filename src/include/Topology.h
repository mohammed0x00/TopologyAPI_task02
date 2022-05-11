/*******************************************************************************
 * @file    Topology.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Topology Class
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
*******************************************************************************/

#ifndef TOPOLOGY_H_
#define TOPOLOGY_H_

/* ------ Include ------ */
#include <vector>
#include "Devices/Device.h"
#include "Devices/Nmos.h"
#include "Devices/Resistor.h"

/**
 * @brief   Represent a topology of a group of devices.
 */
class Topology {
public:

	/* define required data-types */
	
	/**
	 * @brief  A pointer to a device
	 */
	typedef Device * DeviceListElement;
	
	/**
	 * @brief  Topology ID data type.
	 * @note You can cast it to string.
	 */
	typedef std::string TopologyIdType;
	
	/**
	 * @brief  Devices list data type.
	 * @note The member list is a pointer to an array of pointers to the devices
	 * to access devices use operator ([] and ->)    eg. list[2]->getId();
	 */
	typedef struct DeviceListStruct {
		DeviceListElement * list;
		size_t size;
	} DeviceList;

	/* Public functions */
	
	/**
	 * @brief  Constructor of Topology class.
	 * @param  id: ID of the topology.
	 */
	Topology(TopologyIdType id);
	
	/**
	 * @brief  Destructor of Topology class.
	 * It deallocates the memory allocated by the topology and the included devices.
	 * @note The devices that are pointed by the topology will be deleted also.
	 */
	virtual ~Topology();
	
	/**
	 * @brief  Set the topology ID.
	 * @param  id: ID of the topology.
	 * @retval None
	 */
	void setId(TopologyIdType id);

	/**
	 * @brief  Get the topology ID.
	 * @param  None
	 * @retval Id of the Topology
	 */
	TopologyIdType getId();

	/**
	 * @brief  Add device to the topology.
	 * @param  dev_ptr: A pointer to the device (Class Device).
	 * @retval None
	 */
	void addDevice(Device * dev_ptr);
	
	/**
	 * @brief  Add device to the topology.
	 * @param  dev_ptr: A pointer to the device (Class Nmos).
	 * @retval None
	 */
	void addDevice(Nmos * dev_ptr);
	
	/**
	 * @brief  Add device to the topology.
	 * @param  dev_ptr: A pointer to the device (Class Resistor).
	 * @retval None
	 */
	void addDevice(Resistor * dev_ptr);

	/**
	 * @brief  Get the devices inside the topology.
	 * @param  None
	 * @retval A list of devices in the topology.
	 * @note See data-type DeviceList
	 */
	DeviceList getDevices();


private:
	/** object of type TopologyIdType to store the topology id */
	TopologyIdType id;

	/** Vector to store pointer to the devices in the topology */
	std::vector<DeviceListElement> components;

};

#endif /* TOPOLOGY_H_ */
