//
// horaire.hpp for  in /home/ledezaxe/cpp
// 
// Made by ledezaxe
// Login   <quentin.rouanet@etudiant.univ-lr.fr>
// 
// Started on  Sat Nov  5 16:01:27 2016 Quentin Rouanet
// Last update Wed Nov  9 16:10:22 2016 Rouanet Quentin
//

#ifndef HORAIRE_H__
# define HORAIRE_H__

#include "edt.hpp"

class Horaire
{

public:

  Horaire(string jour, int debut, int fin);
  ~Horaire();

  // rien de private ici car il n'y a aucun traitement spécial il s'agit de stocker les horaires ici

  string jour;
  int debut;
  int fin;
};

#endif /* !HORAIRE_H__ */
