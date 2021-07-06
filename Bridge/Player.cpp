#include "Player.h"

// ����ü Ŭ����
class Player::Impl
{
    // ������ Player Ŭ������ �־�� �� ��� ������ ����ü�� ��� �ִ�.
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

// ���� Player �������̽��� ������
Player::Player(const std::string& name, int64_t hp, int64_t mp)
    : impl{ make_unique<Impl>(name, hp, mp) }
{
}

Player::~Player() noexcept = default;

std::string Player::GetName() const noexcept
{
    // ����ü�� �Լ��� �̿��ϴ� ���� �� �� �ִ�.
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