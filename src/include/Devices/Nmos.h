/*
 * Nmos.h
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

#ifndef NMOS_H_
#define NMOS_H_

/* ------ Include ------ */
#include "Device.h"

/* ------ Define ------ */
#define NMOS_TYPE_STRING	(std::string) "nmos"
#define NMOS_NETLIST_NODES  3

/* Nmos class inherates the device class */
class Nmos : public Device{
public:

	/* define required data-types */
	typedef double MlNode;
	enum NetlistNodeIndex {drain, gate, source};

	typedef struct {
		MlNode def;
		MlNode min;
		MlNode max;
	} MlType;

	/* Public functions */
	Nmos();
	virtual ~Nmos();

	/* Set a node in the netlist. The node is pointed by NetlistNodeIndex node
	   The argument NetlistNode value can be casted to string
	   Note : Resistor has 3 nodes drain, gate and source.
	 */
	void setNetlistNode(NetlistNodeIndex node, NetlistNode value);

	/* Returns the node in of netlist that is pointed by NetlistNodeIndex node */
	NetlistNode getNetlistNode(NetlistNodeIndex node);

	/* Set M(l) of the Nmos */
	void setMl(MlNode def, MlNode min, MlNode max);

	/* Returns a struct of MlNode that represents M(l) */
	const MlType * getMl();

private:

	/* Netlist array of 3 elements min, max, default */
	NetlistNode netlist[NMOS_NETLIST_NODES];
	MlType ml;
};

#endif /* NMOS_H_ */
