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
	objective_type type;
	int priority;
};

const auto determine_priority = [](const objective& left, const objective& right) { return left.priority < right.priority; };
class tactician {
public:
	tactician();
protected:
	std::priority_queue<objective, std::vector<objective>, decltype(determine_priority)> all_objectives;
	int execute_objectives();
	
public:
	void add_objective(const objective);
};