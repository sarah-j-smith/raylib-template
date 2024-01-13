/*
    Copyright (c) 2024 Sarah Smith
*/
#include "Character.h"
#include "Constants.h"

#include "raymath.h"

#include <iostream>

// #define _TEST

#ifdef _TEST
#include "doctest.h"
#endif

#ifdef _TEST
class Character_Test: public Character {
public:
    using Character::Character;
    Vector2 getPos() const { return pos; }
    float getWidth() const { return wd; }
    float getHeight() const { return ht; }
    float getRunningTime() const { return runningTime; }
    int getFrame() const { return frame; }
};

TEST_CASE("character tests") 
{
    constexpr float DT = 1.0f / 60.0f;
    constexpr float centeredX = (windowWidth - 220/10) / 2.0f;
    constexpr float centeredY = (windowHeight - 33) / 2.0f;
    constexpr Texture2D mockTexture{ 1, 220, 33, 4, 1 };
    auto sut = new Character_Test{ mockTexture, 10 };
    REQUIRE(sut);

    SUBCASE("construction")
    {

        CHECK(sut->getWidth() == 22);
        CHECK(sut->getHeight() == 33);
        CHECK(sut->getPos().x == centeredX);
        CHECK(sut->getPos().y == centeredY);
        CHECK(sut->getRunningTime() == 0.0f);
        CHECK(sut->getFrame() == 0);
    }
    SUBCASE("move")
    {
        sut->move(0.1);
        CHECK(sut->getPos().x == centeredX + 3.0f);
        CHECK(sut->getPos().y == centeredY);
    }
    SUBCASE("update")
    {
        sut->update(DT);
        CHECK(sut->getRunningTime() == DT);
        CHECK(sut->getFrame() == 0);
        sut->update(DT * 6);
        CHECK(sut->getRunningTime() == 0.0f);
        CHECK(sut->getFrame() == 1);
    }
}
#endif

Character::Character(Texture2D texture, int numberOfFrames)
    : tex(texture)
    , w(texture.width / numberOfFrames)
    , h(texture.height)
    , wd(w)
    , ht(h)
    , pos(Vector2{(windowWidth - wd) / 2.0f, (windowHeight - ht) / 2.0f})
{
    velocity = 30.0f;
    updateTime = 1.0f / 12.0f; // Target 12 fps
}

Character::~Character()
{
    UnloadTexture(tex);
}

void Character::move(float deltaTime)
{
    // World move
    pos.x += velocity * deltaTime;
    if (pos.x > windowWidth * 0.8 || pos.x < 0.2)
    {
        velocity = -velocity;
        leftRight = -leftRight;
    }
}

void Character::update(float deltaTime)
{
    if (dix < 10)
    {
        deltas[dix++] = deltaTime;
    } else if (dix == 11) {
        std::cout << "Deltas:" << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << deltas[i] << std::endl;
        }
        dix++;
    }
    // Update animation
    if (runningTime > updateTime)
    {
        runningTime = 0;
        frame++;
        if (frame >= frameCount)
            frame = 0;
    } else {
        runningTime += deltaTime;
    }
};

void Character::draw()
{
    Rectangle src{frame * wd, 0.0f, leftRight * wd, ht};
    Rectangle dst{pos.x, pos.y, wd * scale, ht * scale};
    DrawTexturePro(tex, src, dst, Vector2Zero(), 0.0, WHITE);
}
