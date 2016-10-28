#include "Wiggin.h"
#include "primary_strategist.h"

void Wiggin::onStart() {
	BWAPI::Broodwar->enableFlag(BWAPI::Flag::UserInput);
	BWAPI::Broodwar->setCommandOptimizationLevel(2);
	BWAPI::Broodwar->setLocalSpeed(0);
}

void Wiggin::onFrame() {
	if ( !BWAPI::Broodwar->self() || BWAPI::Broodwar->isReplay() || BWAPI::Broodwar->isPaused() ) {
		return;
	}
	if ( BWAPI::Broodwar->getFrameCount() % BWAPI::Broodwar->getLatencyFrames() != 0 ) {
		return;
	}
	for ( auto& unit : BWAPI::Broodwar->self()->getUnits() ) {
		if ( unit->exists() ) {
			// Group units by type
			
			if ( unit->getType().isWorker() ) {

			}
		}
	}
}