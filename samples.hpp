#include "models.hpp"

namespace wtg {
    namespace dir {
        constexpr unsigned short int EAST = 101;
        constexpr unsigned short int NORTH = 102;
        constexpr unsigned short int SOUTH = 103;
        constexpr unsigned short int WEST = 104;

        const std::map<char, unsigned short int> char_to_dir = {
            {'d', EAST}, {'w', NORTH}, {'s', SOUTH}, {'a', WEST},
            {'D', EAST}, {'W', NORTH}, {'S', SOUTH}, {'A', WEST}
        };
    }


    class Player: public Object {
    public:
        unsigned short int direction;

        Player(): Object(10, 10, '$') {
            this->direction = dir::EAST;
        }
        Player(int x, int y, char skin): Object(x, y, skin) {
            this->direction = dir::EAST;
        };
        Player(unsigned int id, int x, int y, char skin): Object(id, x, y, skin) {
            this->direction = dir::EAST;
        };
        Player(unsigned int id, int x, int y, char skin, std::map<std::string, int> int_attributes, std::map<std::string, char> char_attributes): Object(id, x, y, skin, int_attributes, char_attributes) {
            this->direction = dir::EAST;
        };
        Player(int x, int y, char skin, std::map<std::string, int> int_attributes, std::map<std::string, char> char_attributes): Object(x, y, skin, int_attributes, char_attributes) {
            this->direction = dir::EAST;
        };

        void changeDirection(unsigned short int direction) {
            this->direction = direction;
        };
        void changeDirection(char direction) {
            if (std::string("wasdWASD").find(direction) != std::string::npos)
                this->changeDirection(dir::char_to_dir.at(direction));
        };

        void move() {
            this->previous_position = std::make_pair(this->x, this->y);
            switch (this->direction) {
                case dir::EAST:
                    this->x++;
                    break;
                case dir::NORTH:
                    this->y--;
                    break;
                case dir::SOUTH:
                    this->y++;
                    break;
                case dir::WEST:
                    this->x--;
                    break;
            }

            // TODO: pac-man effect
        }
    };
}