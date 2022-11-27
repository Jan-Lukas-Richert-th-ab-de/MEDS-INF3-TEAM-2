#ifndef ER_ROOM_H
#define ER_ROOM_H
#include <string>

class ER_Room
{
public:
    ER_Room() = delete;
    ER_Room(std::string rd, std::string rn);
    ER_Room(unsigned int id, std::string rd, std::string rn);
    unsigned int get_room_id() const;
    std::string get_room_description() const;
    std::string get_room_number() const;
    std::string get_full_name() const;
    void set_room_description(std::string rd);
    void set_room_number(std::string rn);

private:
    unsigned int room_id{0};
    std::string room_description{};
    std::string room_number{};
};

#endif /* ER_ROOM_H */
