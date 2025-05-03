#include <SDL3/SDL.h>
#include "geometry.hpp"
#include "vec2.hpp"
#include "globals.hpp"
#include "hook.hpp"

class Player
{
public:
  enum class State
  {
    FALLING,
    SWINGING,
    FLOATING,
  } state;
  glm::vec2 position;
  glm::vec2 velocity;
  glm::vec2 acceleration;
  glm::vec2 angularVelocity;
  glm::vec2 angularAcceleration;
  float radius;
  int segments;
  float timer;
  Hook hook;

  Player();
  void setup(glm::vec2 position);
  void update(float deltaTime);
  void render(SDL_Renderer *renderer);
  void bounce(float deltaTime);
};