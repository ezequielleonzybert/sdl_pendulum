#include "player.hpp"
#include <SDL3/SDL.h>

Player::Player() {}

void Player::setup(glm::vec2 position)
{
  state = State::FLOATING;
  timer = 0;
  this->position = position;
  radius = 15;
  segments = 20;

  acceleration.y = GRAVITY;
}

void Player::update(float deltaTime)
{
  if (state == State::FLOATING)
  {
    position.y = sin(timer * 5) * 10 + HEIGHT / 2;
  }
  else if (state == State::FALLING)
  {
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;

    (bounce(deltaTime));
  }
  else if (state == State::SWINGING)
  {
  }
  timer += deltaTime;
}

void Player::render(SDL_Renderer *renderer)
{
  Circle circle(radius, position, segments);
  SDL_RenderGeometry(renderer, NULL, circle.vertices.data(), circle.vertices.size(), circle.indices.data(), circle.indices.size());
}

void Player::bounce(float deltaTime)
{
  if (position.y > HEIGHT - radius)
  {
    position -= velocity * deltaTime;
    velocity -= acceleration * deltaTime;
    velocity.y *= -1;
  }
}