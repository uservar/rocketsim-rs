#include <array>

#include "RocketSim.h"

// extra vec stuff

std::array<float, 3> btVector3ToArray(const btVector3& v);

std::unique_ptr<btVector3> arrayToBtVector3(const std::array<float, 3>& a);

// extra car config stuff

const CarConfig& getOctane();
const CarConfig& getDominus();
const CarConfig& getPlank();
const CarConfig& getBreakout();
const CarConfig& getHybrid();
const CarConfig& getMerc();

// extra car stuff

struct ECarState {
	std::unique_ptr<Vec> pos;
	Angle angles;
	std::unique_ptr<Vec> vel;
	std::unique_ptr<Vec> angVel;
	bool isOnGround;
	bool hasJumped, hasDoubleJumped, hasFlipped;
	std::unique_ptr<Vec> lastRelDodgeTorque;
	float jumpTimer, flipTimer;
	bool isJumping;
	float airTimeSinceJump;
	float boost;
	float timeSpentBoosting;
	bool isSupersonic;
	float supersonicTime;
	float handbrakeVal;
	CarControls lastControls;

};

std::unique_ptr<ECarState> getCarState(Arena& arena, uint32_t carID);

/// @brief Sets the state of a car in the arena
/// @param arena 
/// @param state 
/// @param carID 
/// @return True if the car was found and the state was set, false otherwise
bool setCarState(Arena& arena, uint32_t carID, const ECarState& state);

uint32_t addCar(Arena& arena, Team team, const CarConfig& config);

/// @brief Sets the controls of a car for the next tick
/// @param arena 
/// @param state 
/// @param carID 
/// @return True if the car was found and the state was set, false otherwise
bool setCarControls(Arena& arena, uint32_t carID, const CarControls& controls);

// extra ball stuff

struct EBallState {
    std::unique_ptr<Vec> pos;
    std::unique_ptr<Vec> vel;
    std::unique_ptr<Vec> angvel;
};

std::unique_ptr<EBallState> getBallState(const Arena& arena);

void setBallState(Arena& arena, const EBallState& state);

// boost pad stuff

uint32_t numBoostPads(const Arena& arena);

std::unique_ptr<BoostPad> getBoostPad(const Arena& arena, uint32_t id);

bool boostPadIsBig(const BoostPad& pad);

struct EBoostPadState {
	uint32_t id;
	bool isActive;
	float cooldown;
};

void setBoostPadState(Arena& arena, const EBoostPadState& state);

EBoostPadState getBoostPadState(const Arena& arena, uint32_t id);
