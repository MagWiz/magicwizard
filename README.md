# Magic Wizard

[![Join the chat at https://gitter.im/MagWiz/magicwizard](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/MagWiz/magicwizard?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

## Simple Crossplatform 2D Game

![MagWiz01](https://magwiz.net/img/screenshots/MagicWizard_001.png)

## Introduction

Magic Wizard is a simply 2D platform game. Most game mechanics have been implemented, however it lacks dedicated graphics, audio and levels (although simply level editor is being provided :) ). I have started this project to learn some C++ game programming, thus many things would be coded in another way if I would have to rewrite everything.

## Requirements

* Linux, OSX, Windows (although builds on OSX and Windows are not straight forward, yet)
* Simple and Fast Multimedia Library [SFML](http://www.sfml-dev.org/) 

## Installation

Assuming that you have deb based distribution (Debian, Ubuntu among others):
```sh
sudo apt-get install libsfml-dev
git clone https://github.com/MagWiz/magicwizard.git
cd magicwizard
make 
./mw
```
## Level editor

To launch the level editor you need install python bindings for sfml, for example:

```sh
sudo apt-get install python-sfml python3-sfml
leveleditor/editor.py
```



## Binaries

There are some development builds, you can find them here: https://magwiz.net/builds/

## License

Magiz Wizard source code are distributed under the [zlib/png license](LICENSE). Information regarding artwork can be found in a file [CREDITS.md](CREDITS.md).

## Home page

https://magwiz.net

## Screenshots

![Magic Wizard gameplay](https://picup.it/media/pictures/mw720p_rhwPLBR.png)
![Magic Wizard level change](https://picup.it/media/pictures/guimw.png)

## Ideas

* More shaders - more aggressive blur while running etc
