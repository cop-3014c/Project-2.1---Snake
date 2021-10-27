/** Contains helper functions for the snake game.
@file snake_helper.cpp
@author YOUR NAME HERE
*/
// TODO: Fill in your name above.

#include "snake_helper.h"
#include <iostream>
#include <set>
#include <vector>
#include "lib/snake.h"
using namespace std;

void draw_walls(char board[HEIGHT + 2][WIDTH + 2]) {
  // TODO: Implement this function.
  return;
}

void draw_snake(char board[HEIGHT + 2][WIDTH + 2],
                const std::vector<Pos> snake) {
  // TODO: Implement this function.
  return;
}

void draw_food(char board[HEIGHT + 2][WIDTH + 2], const std::set<Pos> food) {
  // TODO: Implement this function.
  return;
}

bool collide_walls(const vector<Pos> snake, Move move) {
  // TODO: Implement this function.
  return false;
}

bool collide_snake(const vector<Pos> snake, Move move) {
  // TODO: Implement this function.
  return false;
}

bool collide_food(const vector<Pos> snake, Move move, const set<Pos> food) {
  // TODO: Implement this function.
  return false;
}