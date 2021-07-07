#include <iostream>
#include <memory>
#include <vector>

class Enemy
{
  public:
    void RunAIScripts() {std::cerr << "Run in Enemy class\n";};
    virtual void Update(double deltaTime) {std::cerr << "Update time in " << deltaTime << " in Enemy class\n";};
    virtual ~Enemy() = default;
  private:
    int m_healthh;
    int m_damage;
};

class Boss : public Enemy
{
  public:
    void Update(double deltaTime) override {std::cerr << "Update time in " << deltaTime << " in Boss class\n";};
    // more functions...

};

// we want some functionality of Enermy
class FlyingEnemy : public Enemy
{
    public:
      void Update(double deltaTime) override {std::cerr << "Update time in " << deltaTime << " in FlyingEnemy class\n";};
      void FlightAI() {std::cerr << "I'm FlightAI.\n"; };
};

class FlyingBoss : public Enemy
{
    public:
    void Update(double deltaTime) override {std::cerr << "Update time in " << deltaTime << " in FlyingBoss class\n";};
  
};

void updateAI(){
    FlyingBoss fb;
    //fb.FlyingEnemy::Update(0.09);
    fb.Update(0.09);

}


int main()
{
  //updateAI();
  using std::unique_ptr;
  using std::vector;
  using std::make_unique;
  vector<unique_ptr<Enemy>> enemies;// helpful to have all the enemies stored in a single container, you'd need to have a base class.
  enemies.push_back(make_unique<FlyingEnemy>());
  enemies.push_back(make_unique<FlyingBoss>());
  enemies.push_back(make_unique<Boss>());

  double delta_time = 0.1;

  for (const unique_ptr<Enemy> &enemy_ptr : enemies) {
      enemy_ptr->Update(delta_time);
  }
}

// w/o virtual, when creating a flight boss object, we have two copies of everything inherits from boss class.
// This is because both FlyingEnermy and Boss classes have copies from the Enemy class that they have inherited.
// With virtual on, FlyingBoss class has only one instance of anything gained through inheritance
