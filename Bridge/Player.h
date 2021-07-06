#include <string>
#include <memory>

using namespace std;

class Player
{
    // �����͸� ����� ���� Ŭ���� ���� ������ �Ѵ�.
    class Impl;

    // ���ſ��� �����͸� ���������
    // C++11 ���ĺ��ʹ� std::unique_ptr�� ����Ѵ�.
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