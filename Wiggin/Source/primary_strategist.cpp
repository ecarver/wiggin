#include "primary_strategist.h"
#include "BWEM/bwem.h"

primary_strategist::primary_strategist() {
	power = 0;
	enemy_power = 0;
}

void primary_strategist::strategize() {

	// Add possible enemy base locations to objective list
	BWEM::Map::Instance().FindBasesForStartingLocations();
	for ( auto starting_location : BWEM::Map::Instance().StartingLocations() ) {
		if ( starting_location != BWAPI::Broodwar->self()->getStartLocation() ) {
			objective enemy_base;
			enemy_base.intelligence = 0.0;
			enemy_base.location = starting_location;
			enemy_base.priority = 1;

		}

	}
}

void primary_strategist::add_expansion(BWAPI::TilePosition location) {
	// Defense of our own base is equal priority to enemy bases. However, it will be prioritized because we have perfect intelligence on it.
	expansions.emplace_back(location);
	objective defend_our_base;
	defend_our_base.intelligence = 1.0;
	defend_our_base.location = location;
	defend_our_base.priority = 1;
	defend_our_base.type = EXPANSION;
	defend_our_base.value = 1.0 - (0.1)*expansions.size(); // TODO: Update weight
	objectives.push_back(defend_our_base);
}