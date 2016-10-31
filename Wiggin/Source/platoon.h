#include <BWAPI.h>


class platoon {
public:
	platoon();
protected:
	std::vector<BWAPI::Unit> members;
public:
	
};

enum tactical_action { IDLE, SCOUT, MANEUVER, ATTACK, HOLD, WAIT_REINFORCEMENTS };

struct situation {
	int strength;
	tactical_action current_action;
};

//enum request_type { REINFORCE, ABORT };
//
//struct request {
//
//};

class platoon_leader {
public:
	platoon_leader();
protected:
	platoon platoon;
	// For now, just assign this guy an area to control
	// He doesn't need to know the exact reason
	// Later need to add more parameters like when it needs to be completed
	BWAPI::TilePosition objective_topleft;
	BWAPI::TilePosition objective_topright;
	double acceptable_risk;
	double risk;
	double risk_certainty;

public:
	void assign_objective(const BWAPI::TilePosition, const BWAPI::TilePosition, double acceptable_risk);
	const situation& sitrep();
};