#include <SDL3/SDL.h>
#include <vector>
#include "vec2.hpp"

class Circle
{
public:
  glm::vec2 position;
  float radius;
  int segments;
  std::vector<SDL_Vertex> vertices;
  std::vector<int> indices;

  Circle(float radius, glm::vec2 position, int segments);
};