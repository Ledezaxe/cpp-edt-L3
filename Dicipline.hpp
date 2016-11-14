//
// Dicipline.hpp for  in /home/ledezaxe/cpp
// 
// Made by ledezaxe
// Login   <quentin.rouanet@etudiant.univ-lr.fr>
// 
// Started on  Sat Nov  5 15:24:42 2016 Quentin Rouanet
// Last update Wed Nov  9 16:46:31 2016 Rouanet Quentin
//

#ifndef DICIPLINE_H__
# define DICIPLINE_H__

#include "edt.hpp"
#include "Horaire.hpp"
#include <vector>

#include <cstring> // pour strtok
#include <cstdlib> // pour atoi ça sert pour les horaires

class Dicipline
{

public:

  Dicipline(char *str); // meme chose que dans student
  ~Dicipline();

private:

  string intitule;
  vector<Horaire*> horaire;

public:

  string getNom();
  vector<Horaire*> &getHoraire(); // a manipuler avec précaution car c'est pas une copie
};

#endif /* !DICIPLINE_H__ */
