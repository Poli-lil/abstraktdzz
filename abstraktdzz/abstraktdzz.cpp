#include <iostream>
using namespace std;

class IHackable {
public:
    virtual void applyHack(int level) = 0;
    virtual bool isHacked()const = 0;
    virtual ~IHackable(){}
};
class VendingMachine :public IHackable {
    bool hacked = false;
public:
    void applyHack(int level) override {
        if (level >= 2) {
            hacked = true;
            cout << "Автомат взломан! \n";
        }
        else cout << "Фвтомат ударил током!\n";
    }
    bool isHacked() const override {
        return hacked;
    }
};
class SmartDoor : public IHackable {

    bool hacked = false;

public:

    void applyHack(int level) override {

        if (level >= 5) {
            hacked = true;
            cout << "Дверь открылась!\n";

        }
        else cout<<"«Уровень навыка недостаточен\n";

    }

    bool isHacked() const override { return hacked; }

};

class CyberEnemy {
protected:
    int health;

public:
    CyberEnemy(int h) : health(h) {}
    virtual void attack() = 0;
    virtual ~CyberEnemy() {}
};

class CyberGuard : public CyberEnemy, public IHackable {
    bool hacked = false;

public:
    CyberGuard() : CyberEnemy(100) {}
    void attack() override {
        cout << "Oхранник атакует!\n";
    }

    void applyHack(int level) override {

        if (level >= 7) {
            hacked = true;
            cout << "Охранник заморожен!\n";
        }
        else {
            health -= 20;
            cout <<  "«Охранник получил 20 урона.Здоровье:"
                << health << "\n";
        }
    }
    bool isHacked() const override { return hacked; }
};

class AutoTurret : public CyberEnemy, public IHackable {
    bool hacked = false;
public:

    AutoTurret() : CyberEnemy(80) {}
    void attack() override {
        cout << "Турель стреляет!\n";
    }
    void applyHack(int level) override {
        if (level >= 4) {
            hacked = true;
            cout << "Турель сменила цель!\n";
        }
        else cout << "Уровень навыка недостаточен.\n";
    }
    bool isHacked() const override { return hacked; }
};
class NetRunner {
    int skillLevel;
public:
    NetRunner(int level) : skillLevel(level) {}
    void breachProtocol(IHackable& target) {
        target.applyHack(skillLevel);
    }
};

int main() {
    NetRunner hacker(5);
    SmartDoor door;
    VendingMachine vending;
    CyberGuard guard;
    AutoTurret turret;
    cout << "Система кибер взлома \n";
    cout << "Уровень хакера : 5 \n";
    hacker.breachProtocol(door);
    hacker.breachProtocol(vending);
    hacker.breachProtocol(guard);
    hacker.breachProtocol(turret);
}