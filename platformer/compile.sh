#!/bin/bash

g++ -c $1 $2
g++ main.o Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lGL -lsfml-audio
./sfml-app 

