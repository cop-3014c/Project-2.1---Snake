/** Contains tests for your code.
@file snake_helper_test.cpp
@author YOUR NAME HERE
*/
// TODO: Fill in your name above.

#include "snake_helper.h"
#include <gtest/gtest.h>
#include "lib/snake.h"
using namespace std;

void init_board(char board[HEIGHT + 2][WIDTH + 2]);
void EXPECT_BOARD(char board[HEIGHT + 2][WIDTH + 2], const string& image);

TEST(DrawWalls, Test1) {
  char board[HEIGHT + 2][WIDTH + 2];
  init_board(board);

  draw_walls(board);
  string expected = R"(
    ######################
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    ######################
  )";
  EXPECT_BOARD(board, expected);
}

// DO NOT MODIFY ANYTHING BEFORE THIS LINE

// TODO: Duplicate this test case to cover more scenarios.
TEST(DrawSnake, Test1) {
  char board[HEIGHT + 2][WIDTH + 2];
  init_board(board);
  // TODO: Modify the input argument to your function.
  vector<Pos> snake = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};

  draw_walls(board);
  draw_snake(board, snake);
  // TODO: Modify the expected board state after calling your function.
  string expected = R"(
    ######################
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    ######################
  )";
  EXPECT_BOARD(board, expected);
}

// TODO: Duplicate this test case to cover more scenarios.
TEST(DrawFood, Test1) {
  char board[HEIGHT + 2][WIDTH + 2];
  init_board(board);
  // TODO: Modify the input argument to your function.
  set<Pos> food = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};

  draw_walls(board);
  draw_food(board, food);
  // TODO: Modify the expected board state after calling your function.
  string expected = R"(
    ######################
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    #                    #
    ######################
  )";
  EXPECT_BOARD(board, expected);
}

// TODO: Duplicate this test case to cover more scenarios.
TEST(CollideWalls, Test1) {
  // TODO: Modify the input arguments to your function.
  vector<Pos> snake = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};
  Move move = UP;

  // TODO: Modify the expected output of your function.
  bool expected = false;
  EXPECT_EQ(collide_walls(snake, move), expected);
}

// TODO: Duplicate this test case to cover more scenarios.
TEST(CollideSnake, Test1) {
  // TODO: Modify the input arguments to your function.
  vector<Pos> snake = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};
  Move move = UP;

  // TODO: Modify the expected output of your function.
  bool expected = false;
  EXPECT_EQ(collide_snake(snake, move), expected);
}

// TODO: Duplicate this test case to cover more scenarios.
TEST(CollideFood, Test1) {
  // TODO: Modify the input arguments to your function.
  vector<Pos> snake = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};
  Move move = UP;
  set<Pos> food = {{.x = 0, .y = 0}, {.x = 0, .y = 0}, {.x = 0, .y = 0}};

  // TODO: Modify the expected output of your function.
  bool expected = false;
  EXPECT_EQ(collide_food(snake, move, food), expected);
}

// DO NOT MODIFY ANYTHING BEYOND THIS LINE

void init_board(char board[HEIGHT + 2][WIDTH + 2]) {
  for (int i = 0; i < HEIGHT + 2; i++) {
    for (int j = 0; j < WIDTH + 2; j++) {
      board[i][j] = ' ';
    }
  }
}

void fill_board(char board[HEIGHT + 2][WIDTH + 2], const string& image) {
  deque<deque<char>> d = {{}};
  for (char c : image) {
    if (c == '\n') {
      d.push_back({});
    } else if (!d.back().empty() || c != ' ') {
      d.back().push_back(c);
    }
  }
  while (d.front().empty()) {
    d.pop_front();
  }
  int i = 0;
  for (const deque<char>& row : d) {
    if (i >= HEIGHT + 2) {
      break;
    }
    int j = 0;
    for (char c : row) {
      if (j >= WIDTH + 2) {
        break;
      }
      board[i][j] = c;
      j++;
    }
    i++;
  }
}

string to_image(char board[HEIGHT + 2][WIDTH + 2]) {
  string out = "";
  for (int i = 0; i < HEIGHT + 2; i++) {
    for (int j = 0; j < WIDTH + 2; j++) {
      out += board[i][j];
    }
    out += '\n';
  }
  return out;
}

void EXPECT_BOARD(char board[HEIGHT + 2][WIDTH + 2], const string& image) {
  char expected[HEIGHT + 2][WIDTH + 2];
  fill_board(expected, image);
  for (int i = 0; i < HEIGHT + 2; i++) {
    for (int j = 0; j < WIDTH + 2; j++) {
      ASSERT_EQ(board[i][j], expected[i][j])
          << "expected:\n"
          << to_image(expected) << "\nactual:\n"
          << to_image(board) << "\n";
    }
  }
}