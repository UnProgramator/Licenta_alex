#pragma once

#include <irrlicht.h>
#include <string>
#include "StaticObject.h"
#include "CommunicationInterface.h"

class SensorInterface { //not realy an interface after all...
	static std::list<StaticObject*> visibilityObject;
	static bool bRangeVisibility;
protected:
	std::string name;

public:

	static void setSensorsRangeVisibility(bool isVisible = true);
	static void toggleSensorsRangeVisibility();
	static void addEntityToRangeVisibilityList(StaticObject* obj);
	inline static bool getVisibilityStatus() { return SensorInterface::bRangeVisibility; }

	virtual void getDetectedValue(CommunicationInterface&) =0;
	virtual const std::string& getName() const { return name; }

	SensorInterface(const char* name);

	virtual ~SensorInterface() =default;
};

