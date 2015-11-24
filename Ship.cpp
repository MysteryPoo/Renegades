#include "Ship.h"
#include "template.h"

Ship::Ship(app *App)
{
	AppRef = App;
	ImageDatabase *id = AppRef->getImageDatabase();
	m_SpriteIndex = agk::CreateSprite(id->getImage("Media\\ship.png"));
	agk::SetSpriteOffset(m_SpriteIndex, agk::GetSpriteWidth(m_SpriteIndex) * 0.5f, agk::GetSpriteHeight(m_SpriteIndex) * 0.5f);
	float x = (float)agk::Random(0, agk::GetVirtualWidth());
	float y = (float)agk::Random(0, agk::GetVirtualHeight());
	float direction = (float)agk::Random(0, 360);
	float speed = (float)agk::Random(10, 50);
	t = new Transform(x, y, direction, speed);
	agk::SetSpritePositionByOffset(m_SpriteIndex, x, y);
}

Ship::~Ship()
{
	delete t;
	agk::DeleteSprite(m_SpriteIndex);
}

void Ship::Update(float time)
{
	t->Update(time);
	agk::SetSpriteAngle(m_SpriteIndex, t->getDirection() + 90.0f);
	agk::SetSpritePositionByOffset(m_SpriteIndex, t->getX(), t->getY());
	if (t->getX() < AppRef->getCamera()->getAssigned()->getX() - 100 || t->getX() > AppRef->getCamera()->getAssigned()->getX() + 100)
	{
		agk::SetSpriteVisible(m_SpriteIndex, 0);
	}
	else
	{
		agk::SetSpriteVisible(m_SpriteIndex, 1);
	}
}
