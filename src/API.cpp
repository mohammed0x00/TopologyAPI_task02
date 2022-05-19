/*******************************************************************************
 * @file    API.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Topology API source file
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

#include <iostream>
#include <fstream>

/* ------ Include ------ */
#include "API.h"
#include "json/json.h"

/* ------ Variables ------ */
std::vector<Topology *> API::topologies;

/* ------ Functions ------ */
API::Result API::readJSON(FileName file)
{
	Topology * newTopology;
	Topology::TopologyIdType newTopologyId;
	Result status = Done;
    Json::Reader reader;
    Json::Value obj;

    std::ifstream ifs((std::string) file);
    if(reader.parse(ifs, obj))
    {
    	status = Done;
    	newTopologyId = (Topology::TopologyIdType)obj["id"].asString();
    }
    else
    {
    	status = Failed;
    }


    if(status == Done)
    {
    	for(Topology * t : topologies)
		{
			if(t->getId() == newTopologyId)
			{
				status = TopologyExists;
				break;
			}
		}
    }


    if(status == Done)
    {
    	newTopology = new Topology(newTopologyId);
    	newTopology->setId(newTopologyId);
    	topologies.push_back((TopologyListElement)newTopology);
    	const Json::Value& components = obj["components"]; // array of components
        for (Json::Value component : components){
        	std::string type = component["type"].asString();
        	if(type == RESISTOR_TYPE_STRING)
        	{
        		Resistor * newResistor = new Resistor();
        		unsigned int def = component["resistance"]["default"].asUInt();
        		unsigned int min = component["resistance"]["min"].asUInt();
        		unsigned int max = component["resistance"]["max"].asUInt();
        		std::string t1 = component["netlist"]["t1"].asString();
        		std::string t2 = component["netlist"]["t2"].asString();
        		newTopology->addDevice(newResistor);
        		newResistor->setID(component["id"].asString());
        		newResistor->setResistance(def, min, max);
        		newResistor->setNetlistNode(RESISTOR_NETLIST_NODE_T1, t1);
        		newResistor->setNetlistNode(RESISTOR_NETLIST_NODE_T2, t2);

        	}
        	else if(type == NMOS_TYPE_STRING)
        	{
        		Nmos * newNmos = new Nmos();
        		double def = component["m(l)"]["default"].asDouble();
        		double min = component["m(l)"]["min"].asDouble();
        		double max = component["m(l)"]["max"].asDouble();
        		std::string drain = component["netlist"]["drain"].asString();
        		std::string gate = component["netlist"]["gate"].asString();
        		std::string source = component["netlist"]["source"].asString();
        		newTopology->addDevice(newNmos);
        		newNmos->setID(component["id"].asString());
        		newNmos->setMl(def, min, max);
        		newNmos->setNetlistNode(NMOS_NETLIST_NODE_DRAIN, drain);
        		newNmos->setNetlistNode(NMOS_NETLIST_NODE_GATE, gate);
        		newNmos->setNetlistNode(NMOS_NETLIST_NODE_SOURCE, source);
        	}
        	else
        	{

        	}
        }
    }

    if(status == Done)
    {
    	ifs.close();
    }
    return status;
}

API::Result API::writeJSON(Topology::TopologyIdType id)
{
	Result status = Done;
	Json::Value jsonValueTopology;
	Topology * myTopology;
	std::ofstream ofs;

	if(status == Done)
	{
		status = TopologyNotExists;
		for(Topology * top : topologies)
		{
			if(top->getId() == id)
			{
				status = Done;
				myTopology = (Topology *)top;
				break;
			}
		}
	}

	if(status == Done)
	{
		ofs.open (((std::string) myTopology->getId()) + ".json");
		if(ofs.is_open())
		{
			status = Done;
		}
		else
		{
			status = Failed;
		}
	}

	if(status == Done)
	{
		Json::Value components(Json::arrayValue);
		jsonValueTopology["id"] = ((std::string)myTopology->getId());
		Topology::DeviceList myDevList = myTopology->getDevices();
		for(size_t i = 0; i < myDevList.size; i++)
		{
			Device * dev = myDevList.list[i];
			if(dev->getType() == Device::resistor)
			{
				Resistor * res = (Resistor *)dev;
				Json::Value jsonResistor, jsonNetlist, jsonResistance;
				Resistance resistance = res->getResistance();
				jsonResistor["type"] = RESISTOR_TYPE_STRING;
				jsonResistor["id"] = ((std::string)res->getID());
				jsonNetlist["t1"] = res->getNetlistNode(RESISTOR_NETLIST_NODE_T1);
				jsonNetlist["t2"] = res->getNetlistNode(RESISTOR_NETLIST_NODE_T2);
				jsonResistance["default"] = (int)(resistance.getDefaultValue());
				jsonResistance["min"] = (int)(resistance.getMinimumValue());
				jsonResistance["max"] = (int)(resistance.getMaximumValue());
				jsonResistor["resistance"] = jsonResistance;
				jsonResistor["netlist"] = jsonNetlist;
				components.append(jsonResistor);
			}
			else if(dev->getType() == Device::nmos)
			{
				Nmos * nmos = (Nmos *)dev;
				Json::Value jsonNmos, jsonNetlist, jsonMl;
				Ml ml = nmos->getMl();
				jsonNmos["type"] = NMOS_TYPE_STRING;
				jsonNmos["id"] = ((std::string)nmos->getID());
				jsonNetlist["drain"] = nmos->getNetlistNode(NMOS_NETLIST_NODE_DRAIN);
				jsonNetlist["gate"] = nmos->getNetlistNode(NMOS_NETLIST_NODE_GATE);
				jsonNetlist["source"] = nmos->getNetlistNode(NMOS_NETLIST_NODE_SOURCE);
				jsonMl["default"] = ml.getDefaultValue();
				jsonMl["min"] = ml.getMinimumValue();
				jsonMl["max"] = ml.getMaximumValue();
				jsonNmos["m(l)"] = jsonMl;
				jsonNmos["netlist"] = jsonNetlist;
				components.append(jsonNmos);
			}
		}
		jsonValueTopology["components"] = components;
	}

	if(status == Done)
	{
		ofs << jsonValueTopology << std::endl;
		ofs.close();
	}
	return status;
}

API::TopologyList API::queryTopologies()
{
	return {topologies.data(), topologies.size()};
}

API::Result API::deleteTopology(Topology::TopologyIdType id)
{
	Result status = TopologyNotExists;
	for(size_t i = 0; i < topologies.size(); i++)
	{
		if(topologies[i]->getId() == id)
		{
			delete topologies[i];
			topologies.erase(topologies.begin() + i);
			status = Done;
			break;
		}
	}
	return status;
}
Topology::DeviceList API::queryDevices(Topology::TopologyIdType id)
{
	for(Topology * top : topologies)
	{
		if(top->getId() == id)
		{
			return top->getDevices();
		}
	}
	return {NULL, 0};
}

Topology::DeviceList API::queryDevicesWithNetlistNode(Topology::TopologyIdType topology_id, std::string node_id)
{
	std::vector<Topology::DeviceListElement> * list = new std::vector<Topology::DeviceListElement>;
	Topology::DeviceList toReturn;
	toReturn.size = 0;
	for(Topology * top : topologies)
	{
		if(top->getId() == topology_id)
		{
			for(size_t i = 0; i < top->getDevices().size; i++)
			{
				Device * dev = top->getDevices().list[i];
				if(dev->getType() == Device::resistor)
				{
					if(((Resistor *)dev)->getNetlistNode(RESISTOR_NETLIST_NODE_T1) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Resistor *)dev)->getNetlistNode(RESISTOR_NETLIST_NODE_T2) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
				}
				else if(dev->getType() == Device::nmos)
				{
					if(((Nmos *)dev)->getNetlistNode(NMOS_NETLIST_NODE_DRAIN) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Nmos *)dev)->getNetlistNode(NMOS_NETLIST_NODE_GATE) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Nmos *)dev)->getNetlistNode(NMOS_NETLIST_NODE_SOURCE) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
				}
			}
		}
	}
	toReturn.list = list->data();
	return toReturn;
}

