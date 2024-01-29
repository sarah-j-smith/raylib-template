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

#ifdef _TEST

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#else

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "raylib.h"
#include "raymath.h"

#include "Constants.h"
#include "Character.h"

#include <iostream>

const int FRAME_RATE = 24;

class GameData
{
public:
    Character *skeleton;
};

GameData *gd = 0;

void GameLoop()
{
    const float dT = GetFrameTime();
    gd->skeleton->move(dT);
    gd->skeleton->update(dT);

    BeginDrawing();
    ClearBackground(BLUE);

    gd->skeleton->draw();

    EndDrawing();
}

int main(int argc, char *argv[])
{
    InitWindow(windowWidth, windowHeight, argv[0]);

    std::cout << "Hello world" << std::endl;

    const int numberOfFrames = 13;
    gd->skeleton = new Character {
        LoadTexture("resources/SkeletonWalk.png"),
        numberOfFrames
    };

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(GameLoop, FRAME_RATE, 1);
#else
    SetTargetFPS(FRAME_RATE);
    while (!WindowShouldClose())
    {
        GameLoop();
    }
#endif

    // Free and unload texture
    delete gd->skeleton;

    CloseWindow();
}

#endif