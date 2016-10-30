#include "primary_strategist.h"
#include "BWEM/bwem.h"

primary_strategist::primary_strategist() {
	power = 0;
	enemy_power = 0;
}

void primary_strategist::strategize() {
	BWEM::Map::Instance().FindBasesForStartingLocations();
	std::vector<BWAPI::TilePosition> possible_enemy_starting_locations;
	for ( auto starting_location : BWEM::Map::Instance().StartingLocations() ) {
		if ( starting_location != BWAPI::Broodwar->self()->getStartLocation() ) {
			possible_enemy_starting_locations.emplace_back(starting_location);
		}
	}
}

void primary_strategist::add_expansion(BWAPI::TilePosition location) {
	expansions.emplace_back(location);
}