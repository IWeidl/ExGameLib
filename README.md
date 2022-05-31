# ExGameLib

Game Engine written in C++ with SFML.

I am using this project as a means to learn new technologies and systems. As such, the code is constantly being refactored and played with. 

## Getting Started

### Installation
You will first need SFML and nlohman JSON (links to both found below). You can include manually, but using vckpkg you can run the below commands to install each package:
```
.\vcpkg\vcpkg install sfml
.\vcpkg\vcpkg install nlohmann-json
```

### Usage

Currently, all you can do is load sprites into a game with a specified texture and coordinates. 

To do this, first populate the Textures.json file with the names of the image files you want to load in:

```cpp
{
  "Player": "player.png",
  "Enemy": "enemy.png"
}
```

Then, in the Entities.json file, create your entities following this structure:

```cpp
{
  "Player": {
    "TextureID": 0,
    "Position": [ 50, 50 ]
  },
  "Enemy": {
    "TextureID": 1,
    "Position": [200, 200]
  }
}
```
Finally, instert the below in to your main function:

```cpp
    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "SFML Roguelike");
    Game game(gameWindow);
    game.Run();
```

## Future Plans
- [ ] Implement 3rd Party Entity Component System, thinking about using enTT
- [ ] Implement ChaiScript as game scripting language
- [ ] Replace SFML with lower level graphics implementation, OpenGL most likely

## Libraries Used
- Lohmann N. JSON for Modern C++ (version 3.9.1). URL: https://github.com/nlohmann/json
- SFML - Simple and Fast Multimedia Library (version 2.5.1). URL: https://www.sfml-dev.org/index.php
