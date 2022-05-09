/*
 * API_test.cpp
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

#include <gtest/gtest.h>
#include <fstream>
#include "API.h"

using namespace std;
bool equalFiles(ifstream& in1, ifstream& in2);

TEST(API, ReadJSONTest) {
	/* Simple test to read the return value of the readJSON function */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_EQ(res, API::Done);
}

TEST(API, TopologyListSizeTest) {
	/* Check the number of topologies */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_EQ(API::queryTopologies().size, 1);
}

TEST(API, SetAndGetIDTest) {
	/* Read topology ID, change it and read it again */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getId() == "top1");
	API::queryTopologies().list[0]->setId("topology2");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getId() == "topology2");
}

TEST(API, QueryDevicesTest) {
	/* Read list of devices in the topology "top1" */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getDevices().list[0]->getID() == "res1");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getDevices().list[1]->getID() == "m1");
}

TEST(API, SetAndGetDeviceIDTest) {
	/* Read a device ID, change it and read it again */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getDevices().list[0]->getID() == "res1");
	API::queryTopologies().list[0]->getDevices().list[0]->setID("res2");
	EXPECT_TRUE((string)API::queryTopologies().list[0]->getDevices().list[0]->getID() == "res2");
}

TEST(API, QueryDevicesAPITest) {
	/* Query Devices in "topology2", read a device ID, change it and read it again */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_TRUE((string)(API::queryDevices("top1").list[0]->getID()) == "res1");
	API::queryDevices("top1").list[0]->setID((Device::DeviceIdType)"res3");
	EXPECT_TRUE((string)(API::queryDevices("top1").list[0]->getID()) == "res3");
}

TEST(API, DeviceListSizeTest) {
	/* Query Devices in "topology2" and read number of devices */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_EQ(API::queryDevices("top1").size, 2);
}

TEST(API, QueryDevicesWithNetlistNode) {
	/* Query Devices in "topology2" that are connected to "vin", read a device ID */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_TRUE((string)(API::queryDevicesWithNetlistNode("top1", "vin").list[0]->getID()) == "m1");
}

TEST(API, WriteJSONTest) {
	/* Write topology "topology2" to a .json file */
	API::Result res = API::readJSON((API::FileName)"InitializeTestFile.json");
	EXPECT_EQ(API::writeJSON((Topology::TopologyIdType)"top1"), API::Done);
	
	/* Test if the file was written correctly */
	try {
	        ifstream in1("top1.json", ios::binary);
	        ifstream in2("compareTestFile.json", ios::binary);
	        
	        EXPECT_TRUE(equalFiles(in1, in2));

	    } catch (const exception& ex) {
	    	// Read file exception
	    	EXPECT_TRUE(false);
	    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

bool equalFiles(ifstream& in1, ifstream& in2)
{
    ifstream::pos_type size1, size2;

    size1 = in1.seekg(0, ifstream::end).tellg();
    in1.seekg(0, ifstream::beg);

    size2 = in2.seekg(0, ifstream::end).tellg();
    in2.seekg(0, ifstream::beg);

    if(size1 != size2)
        return false;

    static const size_t BLOCKSIZE = 4096;
    size_t remaining = size1;

    while(remaining)
    {
        char buffer1[BLOCKSIZE], buffer2[BLOCKSIZE];
        size_t size = std::min(BLOCKSIZE, remaining);

        in1.read(buffer1, size);
        in2.read(buffer2, size);

        if(0 != memcmp(buffer1, buffer2, size))
            return false;

        remaining -= size;
    }

    return true;
}
