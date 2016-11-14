//
// Dicipline.cpp for  in /home/ledezaxe/cpp
// 
// Made by ledezaxe
// Login   <quentin.rouanet@etudiant.univ-lr.fr>
// 
// Started on  Sat Nov  5 16:13:09 2016 Quentin Rouanet
// Last update Mon Nov 14 15:43:47 2016 Rouanet Quentin
//

#include "Dicipline.hpp"

Dicipline::Dicipline(char *str)
{
  this->intitule = strsep(&str," []");
  str = str + 2;
  char *ret;
  ret = strtok(str, " []");

  while (ret != NULL)
    {
      while (ret != NULL)
	{
	  string jour = strsep(&ret, "@");
	  int debut = atoi(strsep(&ret, "-"));
	  int fin = atoi(strsep(&ret, " -"));
	  this->horaire.push_back(new Horaire(jour, debut, fin));
	}
      ret = strtok(NULL, " []");
    }
}

Dicipline::~Dicipline()
{

}

string Dicipline::getNom()
{
  return (this->intitule);
}

vector<Horaire*> &Dicipline::getHoraire()
{
  return (this->horaire);
}
