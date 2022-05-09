/*
 * Resistor.h
 *
 *  Created on: May 5, 2022
 *      Author: mohammed
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_

/* ------ Include ------ */
#include "Device.h"

/* ------ Define ------ */
#define RESISTOR_TYPE_STRING	(std::string) "resistor"
#define RESISTOR_NETLIST_NODES  2

/* Resistor class inherates the device class */
class Resistor : public Device {
public:

	/* define required data-types */
	typedef unsigned int ResistanceNode;
	enum NetlistNodeIndex {T1, T2};

	typedef struct {
		ResistanceNode def;
		ResistanceNode min;
		ResistanceNode max;
	} ResistanceType;

	/* Public functions */
	Resistor();
	virtual ~Resistor();

	/* Set a node in the netlist. The node is pointed by NetlistNodeIndex node
	   The argument NetlistNode value can be casted to string
	   Note : Resistor has 2 nodes T1 and T2.
	 */
	void setNetlistNode(NetlistNodeIndex node, NetlistNode value);

	/* Returns the node in of netlist that is pointed by NetlistNodeIndex node */
	NetlistNode getNetlistNode(NetlistNodeIndex node);

	/* Set the resistance value of the resistor */
	void setResistance(ResistanceNode def, ResistanceNode min, ResistanceNode max);

	/* Returns a struct ResistanceNode that represents the resistance */
	const ResistanceType * getResistance();

private:
	NetlistNode netlist[RESISTOR_NETLIST_NODES];
	ResistanceType resistance;
};

#endif /* RESISTOR_H_ */
