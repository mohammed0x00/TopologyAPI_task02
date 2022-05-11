/*******************************************************************************
 * @file    Resistor.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Resistor Class
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

#ifndef RESISTOR_H_
#define RESISTOR_H_

/* ------ Include ------ */
#include "Device.h"

/**
 * @brief  String of resistor type device.
 */
#define RESISTOR_TYPE_STRING	(std::string) "resistor"

/**
 * @brief  Number of netlist nodes for each resistor object.
 */
#define RESISTOR_NETLIST_NODES  2

/**
 * @brief  Resistor class
 */
class Resistor : public Device {
public:

	/* define required data-types */
	
	/**
	 * @brief  A node in the ResistanceType struct.
	 * @note It can be casted to std::string.
	 */
	typedef unsigned int ResistanceNode;
	
	/**
	 * @brief   The index of a netlist node.
	 */
	enum NetlistNodeIndex {
		T1, /*!< T1 node index */
		T2 /*!< T2 node index */
	};

	/**
	 * @brief   Resistance values of the resistor.
	 */
	typedef struct {
		ResistanceNode def; /*!< Default resistance value. */
		ResistanceNode min; /*!< Minimum resistance value. */
		ResistanceNode max; /*!< Maximum resistance value. */
	} ResistanceType;

	/* Public functions */
	
	/**
	 * @brief  Constructor of Resistor class.
	 * It initializes the Device type as Resistor device.
	 */
	Resistor();
	
	/**
	 * @brief  Destructor of Resistor class.
	 */
	virtual ~Resistor();

	/**
	 * @brief  Set a netlist node value.
	 * @param  node: The index of the netlist node
	 * @param value: netlist node value
	 * @note Resistor has 2 nodes T1 and T2.
	 * @note NetlistNode type can be casted to std::string.
	 */
	void setNetlistNode(NetlistNodeIndex node, NetlistNode value);
	
	/**
	 * @brief  Get a netlist node value.
	 * @param  node: The index of the netlist node
	 * @retval Node value
	 * @note Resistor has 2 nodes T1 and T2.
	 * @note NetlistNode type can be casted to std::string.
	 */
	NetlistNode getNetlistNode(NetlistNodeIndex node);

	/**
	 * @brief  Set the resistance value of the resistor.
	 * @param  def: Default resistance value
	 * @param  min: Minimum resistance value
	 * @param  max: Maximum resistance value
	 * @retval None
	 */
	void setResistance(ResistanceNode def, ResistanceNode min, ResistanceNode max);

	/**
	 * @brief  Get the resistance values.
	 * @param  None
	 * @retval A pointer to the resistance struct. 
	 * @note See ResistanceType.
	 */
	const ResistanceType * getResistance();

private:
	/** Array of type NetlistNode to store the netlist nodes. */
	NetlistNode netlist[RESISTOR_NETLIST_NODES];
	
	/** object of ResistanceType struct to store the resistance values. */
	ResistanceType resistance;
};

#endif /* RESISTOR_H_ */
