cmake_minimum_required(VERSION 3.30)
project(S1_02 C)

set(CMAKE_C_STANDARD 11)

add_executable(S1_02 main.c
        pioche.c
        joueur.c
        partie.c
        vecteur.c
        joueur.h
        partie.h
        pioche.h
        vecteur.h
        Dictonnaire.c
        Dictonnaire.h
        rail.c
        rail.h
        itemvecteur.h
)
