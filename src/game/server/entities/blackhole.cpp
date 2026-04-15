/* (c) F-DDrace. Black Hole Grenade entity */
#include <game/server/gamecontext.h>
#include <game/server/entities/character.h>
#include "blackhole.h"

CBlackHole::CBlackHole(CGameWorld *pGameWorld, vec2 Pos, int Owner)
	: CEntity(pGameWorld, CGameWorld::ENTTYPE_CHARACTER, Pos, 32)
{
	m_Pos = Pos;
	m_Radius = GameServer()->Tuning()->m_BlackholeAbsorbRadius;
	m_Owner = Owner;
	m_MaxTicks = (int)(50 * GameServer()->Tuning()->m_BlackholeLifetime);  // 5 seconds at 50 ticks per second
	m_LifeTick = m_MaxTicks;
}

void CBlackHole::Reset()
{
	Destroy();
}

void CBlackHole::Tick()
{
	m_LifeTick--;
	m_Pos = GetPos();
	SetPos(m_Pos);

	// Absorb players
	AbsorbPlayers();

	// Check if expired
	if (m_LifeTick <= 0)
		Destroy();
}

void CBlackHole::AbsorbPlayers()
{
	float PullForce = GameServer()->Tuning()->m_BlackholePullForce;
	float AbsorbRadius = m_Radius * 32;  // Convert from blocks to pixels
	float PullRadius = AbsorbRadius + 200;  // Pull range is larger than absorption range

	// Find all players near the black hole
	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		CCharacter *pChr = GameServer()->GetPlayerChar(i);
		if (!pChr || !pChr->IsAlive())
			continue;

		// Don't absorb admins
		if (Server()->GetAuthedState(i) >= AUTHED_ADMIN)
			continue;

		// Don't absorb the owner
		if (i == m_Owner)
			continue;

		vec2 CharPos = pChr->GetPos();
		float Dist = distance(m_Pos, CharPos);

		// If inside black hole, kill the player
		if (Dist < AbsorbRadius)
		{
			// Kill the player and give credit to owner
			pChr->TakeDamage(vec2(0, 0), m_Pos, 999, m_Owner, WEAPON_BLACKHOLE_GRENADE);

			// Increase black hole radius
			m_Radius += 0.5f;
		}
		else if (Dist < PullRadius)
		{
			// Pull the character towards the black hole
			vec2 Dir = normalize(m_Pos - CharPos);

			// Apply velocity towards center
			if (pChr->Core())
				pChr->Core()->m_Vel += Dir * PullForce;
		}
	}
}

void CBlackHole::Snap(int SnappingClient)
{
	// Snap as a character for visibility
	// We can render it as a special visual effect
}
