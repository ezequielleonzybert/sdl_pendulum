#include <SDL3/SDL.h>
#include "geometry.hpp"
#include "vec2.hpp"

class Player
{
public:
  glm::vec2 position;
  glm::vec2 velocity;
  glm::vec2 acceleration;
  float radius;
  int segments;
  // Circle circle;

  Player();
  void setup(glm::vec2 position);
  void update(float deltaTime);
  void render(SDL_Renderer *renderer);
};