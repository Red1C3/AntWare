#pragma once
#include<ClockAdapter.h>
#include<SoundAdapter.h>
#include<SoundBufferAdapter.h>
#include <GameObject.h>
namespace aw
{
    class Ant : public GameObject
    {
    protected:
        unsigned hp = 5;
        ClockAdapter timeSinceDamage, timeSinceLastAlphaDecrease;
        Material originalMaterial;
        bool isHurting = false;
        bool isAlive = true;
        SoundBufferAdapter hurtSoundBuffer;
        SoundAdapter hurtSound;
        virtual void die();

    public:
        ClockAdapter timeSinceDealtDamage;

        Ant(std::shared_ptr<Mesh> mesh, Material material, GameObject *parent);
        virtual ~Ant();
        void start() override;
        void update() override;
        void damage(unsigned amount);
        unsigned getHp();
        bool timeToDestroy();
    };
}