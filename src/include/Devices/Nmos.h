/*******************************************************************************
 * @file    Nmos.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Nmos Class
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

#ifndef NMOS_H_
#define NMOS_H_

/* ------ Include ------ */
#include "Device.h"

/* ------ Define ------ */

/**
 * @brief  String of nmos type device.
 */
#define NMOS_TYPE_STRING	(std::string) "nmos"

/**
 * @brief  Number of netlist nodes for each nmos object.
 */
#define NMOS_NETLIST_NODES  3

/**
 * @brief  Nmos class
 */
class Nmos : public Device{
public:

	/* define required data-types */
	
	/**
	 * @brief  A node in the MlType struct.
	 * @note It can be casted to std::string.
	 */
	typedef double MlNode;
	
	/**
	 * @brief   The index of a netlist node.
	 */
	enum NetlistNodeIndex {
		drain, /*!< Drain node index */
		gate, /*!< Gate node index */
		source /*!< Source node index */
	};
	
	/**
	 * @brief   M(l) values of the resistor.
	 */
	typedef struct {
		MlNode def; /*!< Default M(l) value. */
		MlNode min; /*!< Default M(l) value. */
		MlNode max; /*!< Default M(l) value. */
	} MlType;

	/* Public functions */
	
	/**
	 * @brief  Constructor of Nmos class.
	 * It initializes the Device type as Nmos device.
	 */
	Nmos();
	
	/**
	 * @brief  Destructor of Nmos class.
	 */
	virtual ~Nmos();

	/**
	 * @brief  Set a netlist node value.
	 * @param  node: The index of the netlist node
	 * @retval value: netlist node value
	 * @note Nmos has 2 nodes drain, gate and source.
	 * @note NetlistNode type can be casted to std::string.
	 */
	void setNetlistNode(NetlistNodeIndex node, NetlistNode value);

	/**
	 * @brief  Get a netlist node value.
	 * @param  node: The index of the netlist node
	 * @retval Node value
	 * @note Nmos has 2 nodes drain, gate and source.
	 * @note NetlistNode type can be casted to std::string.
	 */
	NetlistNode getNetlistNode(NetlistNodeIndex node);

	/**
	 * @brief  Set the M(l) value of the Nmos.
	 * @param  def: Default M(l) value
	 * @param  min: Minimum M(l) value
	 * @param  max: Maximum M(l) value
	 * @retval None
	 */
	void setMl(MlNode def, MlNode min, MlNode max);

	/**
	 * @brief  Get the M(l) values.
	 * @param  None
	 * @retval A pointer to the M(l) struct
	 * @note See MlType.
	 */
	const MlType * getMl();

private:

	/** Array of type NetlistNode to store the netlist nodes. */
	NetlistNode netlist[NMOS_NETLIST_NODES];
	
	/** object of MlType struct to store the M(l) values. */
	MlType ml;
};

#endif /* NMOS_H_ */
