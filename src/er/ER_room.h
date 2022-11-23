#ifndef ER_ROOM_H
#define ER_ROOM_H
#include <string>

class ER_Room
{
public:
    ER_Room() = delete;
    ER_Room(std::string rn);
    ER_Room(unsigned int rid, std::string rn);
    unsigned int get_room_id() const;
    std::string get_room_name() const;
    std::string get_full_name() const;
    void set_room_name(std::string rn);

private:
    unsigned int room_id{0};
    std::string room_name{};
};

#endif /* ER_ROOM_H */
