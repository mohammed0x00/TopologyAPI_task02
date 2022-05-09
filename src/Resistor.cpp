/*
 * Resistor.cpp
 *
 *  Created on: May 5, 2022
 *      Author: mohammed
 */

/* ------ Include ------ */
#include "Devices/Resistor.h"

/* ------ Functions ------ */
/* Reinitialize the device type as resistor */
Resistor::Resistor() {
	type = resistor;
}

/* Empty destructor */
Resistor::~Resistor() {

}

/* Set a node in the netlist. The node is pointed by NetlistNodeIndex node */
/* The argument NetlistNode value can be casted to string */
void Resistor::setNetlistNode(NetlistNodeIndex node, NetlistNode value)
{
	/* store {T1, T2} in netlist array in the same order */
	switch(node)
	{
	case T1:
		netlist[0] = value;
		break;
	case T2:
		netlist[1] = value;
		break;
	}
}

/* Returns the node in of netlist that is pointed by NetlistNodeIndex node */
Resistor::NetlistNode Resistor::getNetlistNode(Resistor::NetlistNodeIndex node)
{
	/* read {T1, T2} from netlist array in the same order */
	NetlistNode toReturn;
	switch(node)
	{
	case T1:
		toReturn = netlist[0];
		break;
	case T2:
		toReturn = netlist[1];
		break;
	}
	return toReturn;
}

/* Set the resistance value of the resistor */
void Resistor::setResistance(ResistanceNode def, ResistanceNode min, ResistanceNode max)
{
	/* Write values to resistance struct of the class */
	resistance.def = def;
	resistance.min = min;
	resistance.max = max;
}

/* Returns a struct ResistanceNode that represents the resistance */
const Resistor::ResistanceType * Resistor::getResistance()
{
	/* Return the address of resistance struct as a pointer to a constant */
	return &resistance;
}
