/*
    Copyright (c) 2024 Sarah Smith
*/
#include "Character.h"
#include "Constants.h"

#include "raymath.h"

#include "doctest.h"

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