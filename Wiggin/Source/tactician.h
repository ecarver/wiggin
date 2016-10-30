#include <BWAPI.h>
#include "BWEM/bwem.h"

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
	int priority;
};

class tactician {
public:
	tactician();
protected:
	int determine_priority = [](objective left, objective right) { return left.priority < right.priority; };
	std::priority_queue<objective, std::vector<objective>, decltype(determine_priority)> all_objectives;
public:
	void add_objective(const objective);
};