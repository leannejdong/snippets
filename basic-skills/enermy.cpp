// single inheritance
#include<iostream>

class Enemy
{
  public:
    void RunAIScripts() {std::cerr << "Run in Enemy class\n";};
    void Update(double deltaTime) {std::cerr << "Update time in " << deltaTime << " in Enemy class\n";};
  private:
    int m_healthh;
    int m_damage;
};

class Boss : public Enemy
{
  public:
    void Update(double deltaTime) {std::cerr << "Update time in " << deltaTime << " in Boss class\n";};
    // more functions...

};

// we want some functionality of Enermy
class FlyingEnemy: public Enemy
{
    public:
      void Update(double deltaTime) {std::cerr << "Update time in " << deltaTime << " in FlyingEnemy class\n";};
      void FlightAI() {std::cerr << "I'm FlightAI.\n"; };
};

class FlyingBoss : public Boss, public FlyingEnemy{
    public:
    void Update(double deltaTime) {std::cerr << "Update time in " << deltaTime << " in FlyingBoss class\n";};
  
};

void updateAI(){
    FlyingBoss fb;
    fb./*FlyingEnemy::*/Update(0.09);
}
int main()
{
    // FlyingEnemy fly;
    // fly.Update(0.2);
    // fly.FlightAI();
    // FlyingBoss boss;
    // boss.Update(0.04);
    // boss.FlightAI();
  //  FlyingEnemy::Update(0.02);
  updateAI();
}
