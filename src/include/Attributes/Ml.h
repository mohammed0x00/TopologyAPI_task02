/*******************************************************************************
 * @file    Ml.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Ml Class
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

#ifndef ML_H_
#define ML_H_

/* ------ Include ------ */

/**
 * @brief  Ml class
 */
class Ml {
public:

	/* Public functions */

	/**
	 * @brief  Constructor of Ml class.
	 */
	Ml();
	
	/**
	 * @brief  Constructor of Ml class.
	 * @param  def: Default ml value
	 * @param  min: Minimum ml value
	 * @param  max: Maximum ml value
	 */
	Ml(double def, double min, double max);

	/**
	 * @brief  Destructor of Ml class.
	 */
	virtual ~Ml();

	/**
	 * @brief  Set the default ml value.
	 * @param  value: Default ml value
	 * @retval None
	 */
	void setDefaultValue(double value);

	/**
	 * @brief  Set the minimum ml value.
	 * @param  value: Minimum ml value
	 * @retval None
	 */
	void setMinimumValue(double value);
	
	/**
	 * @brief  Set the maximum ml value.
	 * @param  value: Maximum ml value
	 * @retval None
	 */
	void setMaximumValue(double value);
	
	/**
	 * @brief  Get the default ml value.
	 * @param  None
	 * @retval Default ml value
	 */
	double getDefaultValue();

	/**
	 * @brief  Get the minimum ml value.
	 * @param  None
	 * @retval Minimum ml value
	 */
	double getMinimumValue();

	/**
	 * @brief  Get the maximum ml value.
	 * @param  None
	 * @retval Maximum ml value
	 */
	double getMaximumValue();

private:
	
	/** Object to store default value of ml */
	double def;

	/** Object to store minimum value of ml */
	double min;

	/** Object to store maximum value of ml */
	double max;
};

#endif /* ML_H_ */
