#pragma once

#include "WorkerData.h"

class Building;
class CCBot;

class WorkerManager
{
    CCBot & m_bot;

    mutable WorkerData  m_workerData;
    Unit m_previousClosestWorker;

    void setMineralWorker(const Unit & unit);
    
	//void handleMineralWorkers();
    void handleGasWorkers();
	void handleIdleWorkers();
    void handleRepairWorkers();

public:

    WorkerManager(CCBot & bot);

    void onStart();
    void onFrame();

    void finishedWithWorker(const Unit & unit);
    void drawResourceDebugInfo();
    void drawWorkerInformation();
    void setScoutWorker(Unit worker);
    void setCombatWorker(Unit worker);
	void setBuildingWorker(Unit worker);
    void setBuildingWorker(Unit worker, Building & b);
    void setRepairWorker(Unit worker,const Unit & unitToRepair);
    void stopRepairing(Unit worker);

    int  getNumMineralWorkers();
    int  getNumGasWorkers();
    int  getNumWorkers();
	std::set<Unit> WorkerManager::getWorkers() const;
	WorkerData WorkerManager::getWorkerData() const;
    bool isWorkerScout(Unit worker) const;
    bool isFree(Unit worker) const;
    bool isBuilder(Unit worker) const;
	bool WorkerManager::isReturningCargo(Unit worker) const;

    Unit getBuilder(Building & b,bool setJobAsBuilder = true) const;
    Unit getClosestDepot(Unit worker) const;
    Unit getGasWorker(Unit refinery) const;
    Unit getClosestMineralWorkerTo(const CCPosition & pos) const;
    Unit getClosestMineralWorkerTo(const CCPosition & pos, CCUnitID workerToIgnore) const;
	Unit getClosest(const Unit unit, const std::list<Unit> units) const;
	std::list<Unit> WorkerManager::orderByDistance(const std::list<Unit> units, CCPosition pos, bool closestFirst);
};

