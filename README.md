# ExGameLib

Game Engine written in C++ with SFML.

I am using this project as a means to learn new technologies and systems. As such, the code is constantly being refactored and played with. 

## Getting Started

### Installation
You will first need SFML and nlohman JSON (links to both found below). You can include manually, but using vckpkg you can run the below commands to install each package:
```
vcpkg install sfml
vcpkg install nlohmann-json
vcpkg install entt
```

### Usage

Currently, you can show a window and load entities from a JSON file (including textures) onto the screen.

To do this, `#include "Game.h"` then insert the below in to your main function:

```cpp
EGL::Game game;
game.Run();
```

Create an `entities.json` file and put in the entity attributes in similar to below:

```json
{
  "player": {
    "name": "Jimmy",
    "health": 10,
    "texture": "player.png",
    "position": [0, 0]
  },
  "villager": {
    "name": "Fred",
    "health": 10
  },
  "skeleton": {
    "health": 5,
    "texture": "enemy.png",
    "position":[100, 100]
  }
}
```

When run, the file will be loaded into the game state and the screen will output the entities at the correct with position with the correct texture.
Provided the image file is reachable, the sprites will be shown on the screen.
![](/Assets/example_screenshot1.png)

## Future Plans
- [ ] Implement ChaiScript as game scripting language
- [ ] Replace SFML with lower level graphics implementation, OpenGL most likely

## Libraries Used
- Lohmann N. JSON for Modern C++ (version 3.9.1). URL: https://github.com/nlohmann/json
- SFML - Simple and Fast Multimedia Library (version 2.5.1). URL: https://www.sfml-dev.org/index.php
- ENTT (version 3.8.0). URL: https://github.com/skypjack/entt
