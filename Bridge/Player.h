#include <string>
#include <memory>

using namespace std;

class Player
{
    // 포인터를 만들기 위해 클래스 전방 선언을 한다.
    class Impl;

    // 과거에는 포인터를 사용했으나
    // C++11 이후부터는 std::unique_ptr을 사용한다.
    std::unique_ptr<Impl> impl;

public:
    Player(const std::string& name, int64_t hp, int64_t mp);
    ~Player();

    std::string     GetName() const noexcept;
    int64_t         GetHP() const noexcept;
    int64_t         GetMP() const noexcept;

    void            TakeDamage(int64_t amount);
    void            UseSkill(int64_t amount);
};