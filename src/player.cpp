#include "player.hpp"
#include <SDL3/SDL.h>

Player::Player() {}

void Player::setup(glm::vec2 position)
{
  this->position = position;
  radius = 15;
  segments = 40;
  // circle.setup(radius, position, segments);

  acceleration.y = 1;
}

void Player::update(float deltaTime)
{
  velocity += acceleration * deltaTime;
  position += velocity * deltaTime;
  SDL_Log("%d", position.y);
}

void Player::render(SDL_Renderer *renderer)
{
  Circle circle(radius, position, segments);
  SDL_RenderGeometry(renderer, NULL, circle.vertices.data(), circle.vertices.size(), circle.indices.data(), circle.indices.size());
}