#include <BWAPI.h>
//#include "tactician.h"

// Can this be encapsulated within an attributes object? Finalize once
enum objective_type {
	EXPANSION,
	CHOKE,
	HIGH_GROUND,
	ENEMY_PRODUCTION_CENTER,
	BLIND_SPOT
};

struct objective {
	BWAPI::TilePosition location;
	double value;
	double intelligence;
	double defensibility;
	objective_type type;
};

// Class used
class primary_strategist {
	primary_strategist();
	~primary_strategist();
protected:
	// TBD: Make a map-sized (or some scaled size) of these?
	std::list<objective> objectives;


public:
	const std::list<objective>& get_objectives(int);
};