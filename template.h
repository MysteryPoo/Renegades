#ifndef _H_SMACKIT_
#define _H_SMACKIT_

// Link to GDK libraries
#include "agk.h"
#include "ImageDatabase.h"
#include "Ship.h"
#include <unordered_map>
#include <memory>
#include "Camera2D.h"

#define DEVICE_WIDTH 1024
#define DEVICE_HEIGHT 768
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

// Global values for the app
class app
{
	ImageDatabase *id;
	std::unordered_map<int, std::unique_ptr<Ship>> *ships;
	int GUID;
	float lastFrame;
	Camera2D *camera;
	//std::unordered_map<int, int> temp;
	public:

		// constructor
		app() { memset ( this, 0, sizeof(app)); }

		// main app functions - mike to experiment with a derived class for this..
		void Begin( void );
		void Loop( void );
		void End( void );

		ImageDatabase* getImageDatabase() { return id; }
		Camera2D* getCamera() { return camera; }
		void NewShip();
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif