#pragma once

#include "Common.h"
#include "DistanceMap.h"
#include "Unit.h"
#include <map>
#include <vector>

class CCBot;

class BaseLocation
{
    CCBot &                     m_bot;
    DistanceMap                 m_distanceMap;

	CCTilePosition				m_turretPosition;
    CCTilePosition              m_depotPosition;
    CCPosition                  m_centerOfResources;
    std::vector<Unit>           m_geysers;
    std::vector<Unit>           m_minerals;
	Unit						m_resourceDepot;
	bool						m_isUnderAttack;

	CCTilePosition				m_centerOfMinerals;

    std::vector<CCPosition>     m_mineralPositions;
    std::vector<CCPosition>     m_geyserPositions;

    std::map<CCPlayer, bool>    m_isPlayerOccupying;
    std::map<CCPlayer, bool>    m_isPlayerStartLocation;
        
    int                         m_baseID;
    CCPositionType              m_left;
    CCPositionType              m_right;
    CCPositionType              m_top;
    CCPositionType              m_bottom;
    bool                        m_isStartLocation;
	bool						m_snapshotsRemoved = false;
    
public:

    BaseLocation(CCBot & bot, int baseID, const std::vector<Unit> & resources);
    
    int getGroundDistance(const CCPosition & pos) const;
    int getGroundDistance(const CCTilePosition & pos) const;
    bool isStartLocation() const;
    bool isPlayerStartLocation(CCPlayer player) const;
    bool isMineralOnly() const;
    bool containsPosition(const CCPosition & pos) const;
	const CCTilePosition & getTurretPosition() const;
    const CCTilePosition & getDepotPosition() const;
	const Unit & getDepot() const;
	int getOptimalMineralWorkerCount() const;
    const CCPosition & getPosition() const;
    const std::vector<Unit> & getGeysers() const;
    const std::vector<Unit> & getMinerals() const;
	const Unit& getResourceDepot() const { return m_resourceDepot; }
	void setResourceDepot(Unit resourceDepot) { m_resourceDepot = resourceDepot; }
	bool isUnderAttack() const { return m_isUnderAttack; }
	void setIsUnderAttack(bool isUnderAttack) { m_isUnderAttack = isUnderAttack; }
	const CCTilePosition getCenterOfMinerals() const;
    bool isOccupiedByPlayer(CCPlayer player) const;
    bool isExplored() const;

    void setPlayerOccupying(CCPlayer player, bool occupying);

    const std::vector<CCTilePosition> & getClosestTiles() const;

    void draw();
};
