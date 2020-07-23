#pragma once

#include "engine.h"

struct AirmassResult {
	float CylinderAirmass = 0;
	float EngineLoadPercent = 100;
};

struct AirmassModelBase {
	DECLARE_ENGINE_PTR;

	AirmassModelBase(const ValueProvider3D& veTable);
	virtual AirmassResult getAirmass(int rpm) = 0;

protected:
	// Retrieve the user-calibrated volumetric efficiency from the table
	float getVe(int rpm, percent_t load) const;

private:
	const ValueProvider3D* const m_veTable;
};
