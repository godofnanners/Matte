#include <string>
#include <tga2d/engine.h>
#include <tga2d/error/error_manager.h>

#include <tga2d/input/XInput.h>
#include <tga2d/animation/SpineAnimation.h>
#include "../../TutorialCommon/TutorialCommon.h"
#include <tga2d/audio/audio.h>


// Making sure that DX2DEngine lib is linked
//
#ifdef _DEBUG
#pragma comment(lib,"TGA2D_Debug.lib")
#elif NDEBUG
#pragma comment(lib,"TGA2D_Release.lib")
#endif // _DEBUG
using namespace std::placeholders;
using namespace Tga2D;
void Go( void );
int main( const int /*argc*/, const char * /*argc*/[] )
{
    Go();
    return 0;
}

Tga2D::CAudio myFootstepAudios[4];
Tga2D::CAudio myShootAudio;

/* This function will trigger as soon as an animation is sending an event from spine, could be anything! Footsteps, something spawning, anything really
The animators will add these events in spine, and set what should be send, maybe a string, maybe a float or integer, thats why there are so many in the function.
As seen below, just the aCurrentAnimationString string and aStringEventName is used, no values
https://www.youtube.com/watch?v=gPj9ZkSb0gU
*/
void AnimCallback(int /*aTrack*/, std::string aCurrentAnimationString, std::string aStringEventName, int /*aNumInt*/, float /*aNumFloat*/, std::string /*aNumString*/)
{
	if (aCurrentAnimationString == "run" && aStringEventName == "footstep")
	{
		myFootstepAudios[rand() % 3].Play();
	}
	else if (aCurrentAnimationString == "shoot" && aStringEventName == "shoot")
	{
		myShootAudio.Play();
	}
}

// Run with  Left thumb stick, jump with A, shoot with X
void Go(void)
{
	TutorialCommon::Init(L"TGA2D: Tutorial 11");

	myFootstepAudios[0].Init("../source/tutorials/Tutorial11SpineAnim/data/audio/footstep_wood_run_01.wav");
	myFootstepAudios[1].Init("../source/tutorials/Tutorial11SpineAnim/data/audio/footstep_wood_run_02.wav");
	myFootstepAudios[2].Init("../source/tutorials/Tutorial11SpineAnim/data/audio/footstep_wood_run_03.wav");
	myFootstepAudios[3].Init("../source/tutorials/Tutorial11SpineAnim/data/audio/footstep_wood_run_04.wav");
	myShootAudio.Init("../source/tutorials/Tutorial11SpineAnim/data/audio/sci-fi_weapon_blaster_laser_boom_small_02.wav");
   
	// Create the sprite with the path to the image
	Tga2D::CSpineAnimation spineAnimation;
	CXInput myInput;

	spineAnimation.RegisterAnimationEventCallback(std::bind(&AnimCallback, _1, _2, _3, _4, _5, _6), 2);
	spineAnimation.Init("../source/tutorials/Tutorial11SpineAnim/data/spineboy-ess.atlas", "../source/tutorials/Tutorial11SpineAnim/data/spineboy-ess.json");

	spineAnimation.AddAnimationToQueue(0, "idle", true, 0.0f); // Provided by your animators


	spineAnimation.SetMixTimings("idle", "run", 0.1f); // Provided by your animators
	spineAnimation.SetMixTimings("run", "idle", 0.1f); // Provided by your animators
	spineAnimation.SetMixTimings("jump", "idle", 0.1f); // Provided by your animators
	spineAnimation.SetMixTimings("idle", "jump", 0.1f); // Provided by your animators
	spineAnimation.SetPosition({ 0.5f, 0.7f });

	bool myIsRunning = 0;
	float timer = 0;
	while (true)
	{
		timer += 1.0f / 60.0f;
		if (!Tga2D::CEngine::GetInstance()->BeginFrame())
		{
			break;
		}

		myInput.Refresh();

		bool doRun = false;
		if (myInput.leftStickX > 0.2f)
		{
			spineAnimation.SetFlipX(false);
			doRun = true;
		}
		else if (myInput.leftStickX < -0.2f)
		{
			spineAnimation.SetFlipX(true);
			doRun = true;
		}

		if (doRun && myIsRunning == 0)
		{

			const char* current = spineAnimation.GetCurrentAnimation(0);
			if (current)
			{
				if (std::string(current) == std::string("idle"))
				{
					myIsRunning = 1;
					spineAnimation.SetCurrentAnimation(0, "run", true);
				}
			}
		}
		else if (myIsRunning && !doRun)
		{
			const char* current = spineAnimation.GetCurrentAnimation(0);
			if (current)
			{
				if (std::string(current) == std::string("run"))
				{
					spineAnimation.SetCurrentAnimation(0, "idle", true);
					myIsRunning = 0;
				}
			}
		}

		if (myInput.IsPressed(XINPUT_GAMEPAD_A))
		{
			const char* current = spineAnimation.GetCurrentAnimation(0);
			if (current)
			{
				if (std::string(current) != std::string("jump"))
				{
					myIsRunning = 0;
					spineAnimation.SetCurrentAnimation(0, "jump", false);
					spineAnimation.AddAnimationToQueue(0, "idle", true, 0.0f);
				}
			}

		}
		if (myInput.IsPressed(XINPUT_GAMEPAD_X))
		{
			const char* current = spineAnimation.GetCurrentAnimation(1);
			if (current)
			{
				if (std::string(current) != std::string("shoot"))
				{
					spineAnimation.SetCurrentAnimation(1, "shoot", true);
				}
			}
			else
			{
				spineAnimation.SetCurrentAnimation(1, "shoot", true);
			}
		}
		else
		{
			const char* current = spineAnimation.GetCurrentAnimation(1);
			if (current)
			{
				if (std::string(current) == std::string("shoot"))
				{
					spineAnimation.SetCurrentAnimation(1, "", false);
				}
			}
		}
		spineAnimation.Update(1.0f / 60.0f);
		spineAnimation.Render();
		//spineAnimation.RenderDebug();

		Tga2D::CEngine::GetInstance()->EndFrame();
	}
	Tga2D::CEngine::GetInstance()->Shutdown();

}
