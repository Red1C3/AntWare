#pragma once
#include "ClockAdapter.h"
#include <GameObject.h>
namespace aw
{
    class Bullet : public GameObject
    {
    private:
        ClockAdapter timer;
        float lifeSpan = 5.0f;
        float speed = 40.0f;

    public:
        Bullet(std::shared_ptr<Mesh> mesh, Material material, GameObject *parent, glm::vec3 projectVec);
        void start() override;
        void update() override;
        bool timeOut();
    };
}