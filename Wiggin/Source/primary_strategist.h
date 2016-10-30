#pragma once
#include <BWAPI.h>
#include "BWEM/bwem.h"
#include "tactician.h"

// Class used
class primary_strategist {
public:
	primary_strategist();
	~primary_strategist();
protected:
	// TBD: Make a map-sized (or some scaled size) grid of these?
	std::vector<objective> objectives;
	double power;
	double enemy_power;
	std::vector<BWAPI::TilePosition> expansions;
	std::vector<BWAPI::TilePosition> enemy_expansions;
public:
	void update_strategy();
	void strategize();
	void add_expansion(BWAPI::TilePosition);
	const std::vector<objective>& get_objectives(int);
};