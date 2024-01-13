# RAYLIB C++ Project Template for VSCode

* Starter project for coding [games in C++ using Raylib]
* Using [Visual Studio Code] as an IDE

# Steps

* Install [Raylib] 
* Install [Visual Studio Code]
* Set up [C++ support in VS Code]
* Download this template
* Double-click the `main.code-workspace` file.
* Edit the `main.cpp` file to create your game.
* Press ⌘-⇧-B (on Mac) or Terminal > Run Build Task...

# Changes 

Over the templates listed below what I did:

* Added a header file for writing tests using [DocTest].
* Changed the `launch.json` and `tasks.json` Project Name
* Made the Makefile not executable 
* Added all this doco so I could remember how to use this.
* Made a basic `main.cpp` that I liked.
* Included the `doctest.h` header file to write tests with.

## Executable Makefile is bad

There is a make clean rule in the Makefile which deletes every file in the 
folder that is executable. If you do `make clean` this will delete the Makefile.

## Project Name

**TL; DR - don't put spaces in the TOP LEVEL folder name.**

The way the `launch.json` and `tasks.json` was set up the currently edited
file was used for `PROJECT_NAME`. This is a disaster if you have been looking
at the `Makefile` as it will get overwritten. Its also bad if you have multiple
source files as the binary name changes depending on what file you last edited.

Now the project folder name is used for the `PROJECT_NAME`. So if your project
is inside a folder called `CoolGame` then the executable will be called `CoolGame`.

This works great for me because I am incapable of doing any technical project
where I name folders with spaces in them. It may cause problems for you if spaces
in file names happen to not work. 
    * so when this var injected in to the `Makefile` the game binary
    * is named after the folder - instead of changing to whatever file is open

# Sprite Sheet 

* [by Jesse M on itch.io]

# Visual Studio Code

* Guide to [using VS Code with Raylib] on the Raylib site.

# DocTest

A single header file gives you the ability to include unit tests inline in your
code very simply.  Super useful for testing out little classes and utilities.
There is nothing to install.

* [DocTest]

# Credits

* Based on the template from [GameDev.tv]
* Which seems to be based on [templates on Raylib]

[C++ support in VS Code]: https://code.visualstudio.com/docs/languages/cpp
[games in C++ using Raylib]: https://www.raylib.com/examples.html
[Visual Studio Code]: https://code.visualstudio.com/download
[DocTest]: https://github.com/doctest/doctest
[by Jesse M on itch.io]: https://jesse-m.itch.io/skeleton-pack
[using VS Code with Raylib]: https://github.com/raysan5/raylib/wiki/Using-raylib-in-VSCode
[GameDev.tv]: https://gitlab.com/GameDevTV/CPPCourse/vscode-template
[templates on Raylib]: https://github.com/raysan5/raylib/wiki/raylib-templates
