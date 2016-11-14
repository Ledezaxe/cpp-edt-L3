//
// student.hpp for  in /home/ledezaxe/cpp
// 
// Made by ledezaxe
// Login   <quentin.rouanet@etudiant.univ-lr.fr>
// 
// Started on  Fri Nov  4 14:14:52 2016 Quentin Rouanet
// Last update Wed Nov  9 18:20:45 2016 Rouanet Quentin
//

#ifndef STUDENT_H__
# define STUDENT_H__

#include "edt.hpp"
#include "Dicipline.hpp"
#include <vector>

class Student
{

public:

  Student(char *str, vector<Dicipline*> mat); // ça correspond au retour du getline passé à la fonction c_str pour pouvoir utiliser strtok
  ~Student();

private:

  string nom;
  vector<Dicipline*> matiere; // faire un new et un delete du bouzin

public:

  string getNom();
  vector<Dicipline*> &getMatiere();
  string conflit(); // le truc à lancer pour vérifier les conflits renvoie "" (vide) si y a pas de conflits ... de canard... désolé

};

#endif /* !STUDENT_H__ */
