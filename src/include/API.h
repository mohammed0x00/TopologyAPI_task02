/*
 * API.h
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

#ifndef API_H_
#define API_H_

/* ------ Include ------ */
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"
#include "Topology.h"
#include "Devices/Device.h"
#include "Devices/Resistor.h"

class API {
public:
	/* define required data-types */

	/* Types of errors that can happen */
	enum Result {Done, Failed, TopologyExists, TopologyNotExists};

	/* Type of files name */
	typedef std::string FileName;

	/* A pointer to the topology used to reach it */
	typedef Topology * TopologyListElement;

	/* List of topologies
	 * the member list is a pointer to an array of pointers to the topologies
	 * to access devices use operator ([] and ->)    eg. list[2]->getId();
	 * */
	typedef struct {
			const TopologyListElement * list;
			size_t size;
	} TopologyList;


	/* Read a .json file, parse the topology and add it to out list
	 *
	 * Parameters: 1- file: json file name.
	 *
	 * Return: Result of the Read, Parse and Add operations. See the following cases:
	 * 		   * Done: Operation done. The topology added to the list
	 * 		   * Failed: Unexpected error happen. It may be file system error.
	 * 		   * TopologyExists: There is a topology with the same ID in the list.
	 * */
	static Result readJSON(FileName file);


	/* Write a topology to a .json file.
	 *
	 * Parameters: 1- id: ID of the topology you want to write.
	 *
	 * Return: Result of the Query and Write operations. See the following cases:
	 * 		   * Done: Operation done. The topology written to the file.
	 * 		   * Failed: Unexpected error happen. It may be file system error.
	 * 		   * TopologyNotExists: The topology does not exist in the topology list.
	 * */
	static Result writeJSON(Topology::TopologyIdType id);


	/* List the topologies exists in the system.
	 *
	 * Parameters: No Parameters.
	 *
	 * Return: A list of topologies. See TopologyList data type.
	 * */
	static TopologyList queryTopologies();


	/* Delete a topology from the system.
	 *
	 * Parameters: 1- id: ID of the topology you want to delete.
	 *
	 * Return: Result of the Query and Write operations. See the following cases:
	 * 		   * Done: Operation done. The topology deleted successfully.
	 * 		   * TopologyNotExists: The topology does not exist in the topology list.
	 * */
	static Result deleteTopology(Topology::TopologyIdType id);


	/* List the devices exists in the a topology.
	 *
	 * Parameters: 1- id: ID of the topology to list its devices.
	 *
	 * Return: A list of devices. See DeviceList data type.
	 * */
	static Topology::DeviceList queryDevices(Topology::TopologyIdType id);


	/* List the devices connected to a netlist node.
	 *
	 * Parameters: 1- topology_id: ID of the topology to search for the node in.
	 *             2- node_id: ID of the node to search for.
	 *
	 * Return: A list of devices. See DeviceList data type.
	 * */
	static Topology::DeviceList queryDevicesWithNetlistNode(Topology::TopologyIdType topology_id, Device::NetlistNode node_id);

private:

	/* Static vector to store the pointers of the topologies */
	static std::vector<TopologyListElement> topologies;
};

#endif /* API_H_ */
