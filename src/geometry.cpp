#include "geometry.hpp"

Circle::Circle(float radius, glm::vec2 position, int segments)
{
  this->radius = radius;
  this->position = position;
  this->segments = segments;

  vertices.push_back({{position.x, position.y}, {0, 1, 0, 1}, {0, 0}});

  for (int i = 0; i < segments; i++)
  {
    float angle = i / float(segments) * SDL_PI_F * 2.0f;
    float x = radius * cos(angle) + position.x;
    float y = radius * sin(angle) + position.y;

    vertices.push_back({{x, y}, {0, 1, 0, 1}, {0, 0}});
  }

  for (int i = 0; i < segments; i++)
  {
    indices.push_back(0);
    indices.push_back(i + 1);
    indices.push_back((i + 1) % segments + 1);
  }
}