/*
** main.c for  in /home/ledezaxe/cpp
** 
** Made by ledezaxe
** Login   <quentin.rouanet@etudiant.univ-lr.fr>
** 
** Started on  Fri Nov  4 13:32:09 2016 Quentin Rouanet
// Last update Mon Nov 14 15:47:37 2016 Rouanet Quentin
*/

#include "edt.hpp"
#include "Dicipline.hpp"
#include "Student.hpp"

// include des gestion des erreur dues aux fichiers non-valides
#include <cstdlib>
#include <csignal>

void catch_verif_fichier(int )
{
  cerr << "Erreur : Très mauvais formatage de fichiers\nMerci de respecter le format donné dans les fichiers students_format.txt et schedule_format.txt" << endl;
  exit(EXIT_FAILURE);
}

int main()
{
  // gestion de la validité des fichiers

  signal(SIGSEGV, catch_verif_fichier);

  // création des matieres


  ifstream sche("schedule.txt", ios::in);
  vector<Dicipline*> matieres;

  if (sche)
    {
      string line;
      while (getline(sche, line))
	{
	  char *str = (char *)line.c_str();
	  matieres.push_back(new Dicipline(str));
	}
    }
  else
    {
      cerr << "erreur d'ouverture de schedule.txt" << endl;
      return (-1);
    }


  // création des étudiants


  vector<Student*> etudiants;
  ifstream stud("students.txt", ios::in);

  if (stud) // en gros "si c'est bon"
    {
      string line;
      while (getline(stud, line))
	{
	  char *str = (char *)line.c_str();
	  etudiants.push_back(new Student(str, matieres));
	}
    }
  else
    {
      cerr << "erreur d'ouverture de students.txt" << endl;
      return (-1);
    }


  // traitement de superposition des matieres par etudiant


  unsigned int i = 0;
  while (i < etudiants.size())
    {
      string res = etudiants[i]->conflit();
      if (res.compare("") != 0) // si il y a un conflit
	cout << "Conflicts for " << etudiants[i]->getNom() << " :\n" << res << endl;
      else
	cout << etudiants[i]->getNom() << " : OK" << endl;
      i++;
    }
  return (0);
}
