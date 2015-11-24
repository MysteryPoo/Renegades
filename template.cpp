// Includes
#include "template.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	agk::SetVirtualResolution(1024, 768);
	//agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetClearColor(0, 0, 0);
	agk::SetSyncRate(60, 0);
	agk::SetScissor(0, 0, 0, 0);

	id = new ImageDatabase();
	ships = new std::unordered_map<int, std::unique_ptr<Ship>>;
	GUID = 1;
	lastFrame = agk::Timer();

	for (int s = 0; s < 10; ++s)
	{
		NewShip();
	}

	//camera = new Camera2D();
	camera = new Camera2D(ships->begin()->second->t);

	for (int x = 0; x < 20; ++x)
	{
		for (int y = 0; y < 20; ++y)
		{
			int index = agk::CreateSprite(id->getImage("Media\\stars.png"));
			agk::SetSpriteDepth(index, 100);
			agk::SetSpritePosition(index, x * agk::GetSpriteWidth(index), y * agk::GetSpriteHeight(index));
		}
	}
	
}

void app::Loop (void)
{
	float thisFrame = agk::Timer();
	float diff = thisFrame - lastFrame;
	lastFrame = thisFrame;
	for (auto s = ships->begin(); s != ships->end(); ++s)
	{
		s->second->Update(diff);
	}
	camera->Update();
	agk::Print( agk::ScreenFPS() );
	agk::Sync();
}


void app::End (void)
{
	delete id;
	delete camera;
	ships->clear();
}

void app::NewShip()
{
	ships->insert(std::make_pair<int, std::unique_ptr<Ship>>(GUID++, std::unique_ptr<Ship>(new Ship(this))));
}
