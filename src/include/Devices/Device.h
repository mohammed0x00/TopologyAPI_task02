/*******************************************************************************
 * @file    Device.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Device Class
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

#ifndef DEVICE_H_
#define DEVICE_H_

/* ------ Include ------ */
#include <string>

/**
 * @brief  Device class
 */
class Device {
public:
	/* define required data-types */
	
	/**
	 * @brief  A netlist node data type
	 * @note It can be casted to std::string.
	 */
	typedef std::string NetlistNode;
	
	/**
	 * @brief  Device ID data type.
	 * @note It can be casted to std::string.
	 */
	typedef std::string DeviceIdType;
	
	/**
	 * @brief  Represent the type of the device.
	 */
	enum DeviceType {
		undefined, /*!< The device type is undefined. */
		resistor, /*!< The device is a resistor. */
		nmos /*!< The device is a nmos. */
	};

	/* Public functions */
	
	/**
	 * @brief  Constructor of Device class.
	 * It initializes the Device type as undefined.
	 */
	Device();

	/**
	 * @brief  Destructor of Device class.
	 */
	virtual ~Device();

	/**
	 * @brief  Get the ID of the device.
	 * @param  None
	 * @retval device ID
	 * @note DeviceIdType can be casted to std::string.
	 */
	DeviceIdType getID();

	/**
	 * @brief  Set the ID of the device.
	 * @param  id: device ID
	 * @retval None
	 * @note DeviceIdType can be casted to std::string.
	 */
	void setID(DeviceIdType id);

	/**
	 * @brief  Get the type of the device.
	 * @param  None
	 * @retval device type
	 * @note See DeviceType data type.
	 */
	DeviceType getType();


protected:

	/* declare the netlist object */
	struct Netlist;

	/** Type of the device class */
	DeviceType type;

private:

	/** object of DeviceIdType to store the device ID */
	DeviceIdType id;


};

#endif /* DEVICE_H_ */
