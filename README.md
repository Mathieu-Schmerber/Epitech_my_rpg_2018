# Epitech_my_rpg_2018

`my_rpg` is a university project made in 2018.
The project requirements were to create a fully fletch Role Play Game in C using the CSFML library.

Therefore we decided to take on the challenge off making it a 3D Game.
The CSFML being a simple drawing library, a complete rendering engine was built on top of a homemade game engine from scratch.

## Features

### Gameplay

`my_rpg` is a pirate game. The player is represented as a pirate boat. The goal of the game is to find and destroy a guard tower somewhere on the map.
In order to defeat the tower, the player will need to complete quests:
- Kill x amount of enemies
- Find and open treasure chests

An endless flow of enemy boats are seeking the player.

Using the golds generated from quest completion, the player may upgrade their boat at the dock (center of the map).
The player boat have 3 evolution stages, they will need to reach the 3rd stage to defeat the tower.

**INPUTS**

[Z Q S D] - Move around

[A] - Fire right

[E] - Fire left

[H] - Interaction

### Engine

The engine features:
- Rendering system
- Custom model loader
- Audio
- Physics
- Particle system
- Interactions
- Input handling

## Installation

### Requirements

This project requires the CSFML library to run.
CSFML is the official C library adaptation fo the SFML.
To install the CSFML follow this guide:
> https://pryp.in/blog/12/build-sfml-and-csfml-on-linux.html#other

## Run

`my_rpg` builds using a Makefile, run the following command in the root folder:
> make

## Team

- **Mathieu Schmerber**: Game engine, rendering, gameplay, AI
- **Thomas Paques**: UI, quest design, sound
- **Theo Miquet**: File parser, optimisation, A* pathfinding
- **Axel Renard**: UI
