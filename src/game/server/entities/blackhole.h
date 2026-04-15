/* (c) F-DDrace. Black Hole Grenade entity */
#ifndef GAME_SERVER_ENTITIES_BLACKHOLE_H
#define GAME_SERVER_ENTITIES_BLACKHOLE_H

#include <game/server/entity.h>

class CCharacter;

class CBlackHole : public CEntity
{
	vec2 m_Pos;
	float m_Radius;  // Current radius (starts at 1.5, increases by 0.5 per absorbed player)
	int m_LifeTick;  // Lifetime in ticks (5 seconds)
	int m_Owner;     // Owner (for kill credit)
	int m_MaxTicks;  // Max ticks (approximately 5 seconds)

public:
	CBlackHole(CGameWorld *pGameWorld, vec2 Pos, int Owner);

	virtual void Reset();
	virtual void Tick();
	virtual void Snap(int SnappingClient);

private:
	void AbsorbPlayers();
};

#endif // GAME_SERVER_ENTITIES_BLACKHOLE_H
