// Last updated: 5/20/2026, 11:36:27 PM


enum class Direction { kNorth, kEast, kSouth, kWest };

Direction &operator++(Direction &dir) {
  switch (dir) {
  case Direction::kNorth:
    dir = Direction::kEast;
    break;
  case Direction::kEast:
    dir = Direction::kSouth;
    break;
  case Direction::kSouth:
    dir = Direction::kWest;
    break;
  case Direction::kWest:
    dir = Direction::kNorth;
    break;
  }
  return dir;
}

Direction &operator--(Direction &dir) {
  switch (dir) {
  case Direction::kNorth:
    dir = Direction::kWest;
    break;
  case Direction::kEast:
    dir = Direction::kNorth;
    break;
  case Direction::kSouth:
    dir = Direction::kEast;
    break;
  case Direction::kWest:
    dir = Direction::kSouth;
    break;
  }
  return dir;
}

class Solution {

public:
  enum class Move : char {

    kStraight = 'G',
    kLeft = 'L',
    kRight = 'R'

  };

  struct coordinates {
    int x, y;

    bool operator==(const coordinates &other) {
      return other.x == this->x && other.y == this->y;
    }
  };

  struct robot {
    coordinates coords{};
    Direction direction{};

    robot() {
      coords = {0, 0};
      direction = Direction::kNorth;
    }
  };

  constexpr void moveStraight(robot &rb) {
    switch (rb.direction) {

    case Direction::kNorth:
      ++rb.coords.y;
      break;
    case Direction::kEast:
      ++rb.coords.x;
      break;
    case Direction::kSouth:
      --rb.coords.y;
      break;
    case Direction::kWest:
      --rb.coords.x;
      break;
    }
  }

  void executeInstructions(const std::string &instructions, robot &rb) {

    for (const auto &instruction : instructions) {
      Move mv = static_cast<Move>(instruction);

      switch (mv) {

      case Move::kStraight:
        moveStraight(rb);
        break;
      case Move::kLeft:
        --rb.direction;
        break;
      case Move::kRight:
        ++rb.direction;
        break;
      }
    }
  }

  bool isRobotBounded(string instructions) {
    constexpr static coordinates origin{0, 0};
    robot rb{};
    int depth = 0;
    while (depth != 5) {

      executeInstructions(instructions, rb);

      if (rb.coords == origin) {
        return true;
      }

      ++depth;
    }

    return false;
  }
};
