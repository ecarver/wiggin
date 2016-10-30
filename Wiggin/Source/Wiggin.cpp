#include "Wiggin.h"
#include "primary_strategist.h"
#include "BWEM/bwem.h"

void Wiggin::onStart() {
	BWAPI::Broodwar->enableFlag(BWAPI::Flag::UserInput);
	BWAPI::Broodwar->setCommandOptimizationLevel(2);
	BWAPI::Broodwar->setLocalSpeed(0);

	BWEM::Map::Instance().Initialize();
	BWEM::Map::Instance().EnableAutomaticPathAnalysis();
	strategist = new primary_strategist();
	strategist->add_expansion(BWAPI::Broodwar->self()->getStartLocation());
	strategist->strategize();
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

void Wiggin::onUnitDestroy(BWAPI::Unit destroyed_unit) {
	if ( destroyed_unit->getType().isMineralField() ) {
		BWEM::Map::Instance().OnMineralDestroyed(destroyed_unit);
	}
	else if ( destroyed_unit->getType().isSpecialBuilding() ) {
		BWEM::Map::Instance().OnStaticBuildingDestroyed(destroyed_unit);
	}
}