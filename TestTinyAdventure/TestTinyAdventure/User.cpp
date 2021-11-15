#include "User.h"

User::User(int level,
	int expCurrent,
	int expNext,
	int health,
	int healthMax,
	int magic,
	int magicMax,
	int damageMin,
	int damageMax,
	int accuracy,
	int defence) :

	m_level{ level },
	m_expCurrent{ expCurrent },
	m_expNext{ expNext },
	m_health{ health },
	m_healthMax{ healthMax },
	m_magic{ magic },
	m_magicMax{ magicMax },
	m_damageMin{ damageMin },
	m_damageMax{ damageMax },
	m_accuracy{ accuracy },
	m_defence{ defence }
{

}