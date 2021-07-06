#include "Player.h"

// 구현체 클래스
class Player::Impl
{
    // 기존에 Player 클래스에 있어야 할 멤버 변수가 구현체에 들어 있다.
    std::string     name = "";
    int64_t     hp = 100LL;
    int64_t     mp = 100LL;

public:
    Impl(const std::string& name, int64_t hp, int64_t mp)
        : name{ name }, hp{ hp }, mp{ mp }
    {    
    }

    string      GetName() const noexcept { return name; }
    int64_t     GetHP() const noexcept { return hp; }
    int64_t     GetMP() const noexcept { return mp; }

    void        TakeDamage(int64_t amount) { hp -= amount; }
    void        UseSkill(int64_t amount) { mp -= amount; }
};

// 실제 Player 인터페이스의 구현부
Player::Player(const std::string& name, int64_t hp, int64_t mp)
    : impl{ make_unique<Impl>(name, hp, mp) }
{
}

Player::~Player() noexcept = default;

std::string Player::GetName() const noexcept
{
    // 구현체의 함수를 이용하는 것을 볼 수 있다.
    return impl->GetName();
}

int64_t Player::GetHP() const noexcept
{
    return impl->GetHP();
}

int64_t Player::GetMP() const noexcept
{
    return impl->GetMP();
}

void Player::TakeDamage(int64_t amount)
{
    impl->TakeDamage(amount);
}

void Player::UseSkill(int64_t amount)
{
    impl->UseSkill(amount);
}