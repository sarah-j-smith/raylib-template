/*
    Copyright (c) 2024 Sarah Smith
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character
{
public:
    Character(Texture2D texture, int numberOfFrames);
    ~Character();
    void setPosition(const Vector2 &vec) { pos = vec; }
    void move(float deltaTime);
    void update(float deltaTime);
    void draw();
    
protected:
    // Sprite size
    Texture2D tex{};
    float deltas[10];
    int dix{0};
    int w{};
    int h{};
    float wd{};
    float ht{};

    // World pos
    Vector2 pos{};
    float velocity{};
    float leftRight = 1.0f;

    // Animation
    float updateTime{};
    float runningTime{};
    int frame{};
    int frameCount{};
};

#endif