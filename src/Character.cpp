/*

    Copyright (c) 2024 Sarah Smith

    MIT License

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.


*/
#include "Character.h"
#include "Constants.h"

#include "raymath.h"

Character::Character(Texture2D texture, int numberOfFrames)
    : tex(texture)
    , w(texture.width / numberOfFrames)
    , h(texture.height)
    , wd(w)
    , ht(h)
    , pos(Vector2{(windowWidth - wd) / 2.0f, (windowHeight - ht) / 2.0f})
    , frameCount(numberOfFrames)
{
    velocity = 30.0f;
    updateTime = 1.0f / 12.0f; // Target 12 fps
}

Character::~Character()
{
    UnloadTexture(tex);
}

/**
 * Called to update the characters world movement prior 
 * Note that the very first iteration of the game loop `deltaTime`
 * will be `0` (zero).
*/
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

/**
 * Called to update the characters animation prior to display
 * Note that the very first iteration of the game loop `deltaTime`
 * will be `0` (zero).
*/
void Character::update(float deltaTime)
{
    // Update animation
    runningTime += deltaTime;
    if (runningTime > updateTime)
    {
        runningTime = 0;
        frame++;
        if (frame >= frameCount)
            frame = 0;
    }
};

void Character::draw()
{
    Rectangle src{frame * wd, 0.0f, leftRight * wd, ht};
    Rectangle dst{pos.x, pos.y, wd * scale, ht * scale};
    DrawTexturePro(tex, src, dst, Vector2Zero(), 0.0, WHITE);
}
