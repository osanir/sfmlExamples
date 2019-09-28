#!/bin/bash

g++ -c $1 -o sfml-app.o
g++ sfml-app.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lGL -lsfml-audio
./sfml-app 

