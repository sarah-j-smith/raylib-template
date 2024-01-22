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

#include "raylib.h"
#include "raymath.h"

#include "Constants.h"
#include "Character.h"

#include <iostream>

int main(int argc, char *argv[])
{
    InitWindow(windowWidth, windowHeight, argv[0]);

    std::cout << "Hello world" << std::endl;

    const int numberOfFrames = 13;
    auto skeleton = new Character {
        LoadTexture("Skeleton Walk.png"),
        numberOfFrames
    };

    SetTargetFPS(6);
    while (!WindowShouldClose())
    {
        const float dT = GetFrameTime();
        skeleton->move(dT);
        skeleton->update(dT);

        BeginDrawing();
        ClearBackground(BLUE);

        skeleton->draw();

        EndDrawing();
    }

    // Free and unload texture
    delete skeleton;

    CloseWindow();
}

#endif