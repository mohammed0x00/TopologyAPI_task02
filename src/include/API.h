/*******************************************************************************
 * @file    API.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Topology API
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

#ifndef API_H_
#define API_H_

/* ------ Include ------ */
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"
#include "Topology.h"
#include "Devices/Device.h"
#include "Devices/Resistor.h"

/**
 * @brief   Contain APIs required to read electronic devices topology from a Json file, modify it and write it back.
 */
class API {
public:
	/* define required data-types */

	/**
	 * @brief   Results of API operations
	 */
	enum Result {
			Done, /*!< Operation completed successfully */
			Failed, /*!< Operation Failed (Unexpected error happen) */
			TopologyExists, /*!< The topology already exists in the system topology list */
			TopologyNotExists /*!< The topology doesn't exist in the system topology list */
		};

	/** File name data type (can be casted from std::string) */
	typedef std::string FileName;

	/** A pointer to the topology used to reach it */
	typedef Topology * TopologyListElement;

	/** 
	 * @brief An array of pointers to topologies.
	 * List of topologies
	 * the member list is a pointer to an array of pointers to the topologies
	 * to access devices use operator ([] and ->)    eg. list[2]->getId();
	 */
	typedef struct TopologyListStruct {
			const TopologyListElement * list; /*!< @brief Array of pointers to topologies */
			size_t size; /*!< @brief Size of array */
	} TopologyList;
	
	
	/**
	 * @brief   Read a .json file, parse the topology and add it to out list
	 * @param   file: json file name.
	 * @retval  Result of the Read, Parse and Add operations. See the following cases:
	 * 		   * Done: Operation done. The topology added to the list
	 * 		   * Failed: Unexpected error happen. It may be file system error.
	 * 		   * TopologyExists: There is a topology with the same ID in the list.
	 */
	static Result readJSON(FileName file);
	
	
	/**
	 * @brief   Write a topology to a .json file.
	 * @param   id: ID of the topology you want to write.
	 * @retval  Result of the Query and Write operations. See the following cases:
	 * 		   * Done: Operation done. The topology written to the file.
	 * 		   * Failed: Unexpected error happen. It may be file system error.
	 * 		   * TopologyNotExists: The topology does not exist in the topology list.
	 */
	static Result writeJSON(Topology::TopologyIdType id);

	/**
	 * @brief   List the topologies exists in the system.
	 * @retval  A list of topologies. See TopologyList data type.
	 *
	 */
	static TopologyList queryTopologies();

	 /**
	 * @brief   Delete a topology from the system.
	 * @param   id: ID of the topology you want to delete.
	 * @retval  Result of the Query and Write operations. See the following cases:
	 * 		   * Done: Operation done. The topology deleted successfully.
	 * 		   * TopologyNotExists: The topology does not exist in the topology list.
	 */
	static Result deleteTopology(Topology::TopologyIdType id);

	/**
	 * @brief   List the devices exists in the a topology.
	 * @param   id: ID of the topology to list its devices.
	 * @retval  A list of devices. See DeviceList data type.
	 */
	static Topology::DeviceList queryDevices(Topology::TopologyIdType id);

	/**
	 * @brief   List the devices connected to a netlist node.
	 * @param   topology_id: ID of the topology to search for the node in.
	 * @param   node_id: ID of the node to search for.
	 * @retval  A list of devices. See DeviceList data type.
	 */
	static Topology::DeviceList queryDevicesWithNetlistNode(Topology::TopologyIdType topology_id, Device::NetlistNode node_id);

private:

	/** Static vector to store the pointers of the topologies */
	static std::vector<TopologyListElement> topologies;
};

#endif /* API_H_ */
