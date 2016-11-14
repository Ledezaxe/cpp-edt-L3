//
// student.cpp for  in /home/ledezaxe/cpp
// 
// Made by ledezaxe
// Login   <quentin.rouanet@etudiant.univ-lr.fr>
// 
// Started on  Fri Nov  4 14:31:58 2016 Quentin Rouanet
// Last update Mon Nov 14 15:43:30 2016 Rouanet Quentin
//

#include "Student.hpp"

Student::Student(char *str, vector<Dicipline*> mat)
{
  this->nom = strsep(&str," []");
  str = str + 2;
  char *ret;
  ret = strtok(str, " []");

  while (ret != NULL)
    {
      string name = ret;
      unsigned int i = 0;
      while (i < mat.size())
	{
	  if (mat[i]->getNom().compare(name) == 0)
	    {
	      this->matiere.push_back(mat[i]);
	      i = mat.size();
	    }
	  i++;
	}
      ret = strtok(NULL, " []");
    }
}

Student::~Student()
{

}

string Student::getNom()
{
  return (this->nom);
}

string Student::conflit()
{
  string res = "";
  unsigned int i = 0;

  while (i < this->matiere.size() - 1)
    {
      unsigned int j = i + 1;
      vector<Horaire*> h_mat_1 = matiere[i]->getHoraire();
      while (j < this->matiere.size())
	{
	  vector<Horaire*> h_mat_2 = matiere[j]->getHoraire();
	  unsigned int index_h_m_1 = 0;

	  while (index_h_m_1 < h_mat_1.size())
	    {
	      unsigned int index_h_m_2 = 0;

	      while (index_h_m_2 < h_mat_2.size())
		{
		  if (h_mat_1[index_h_m_1]->jour.compare(h_mat_2[index_h_m_2]->jour) == 0) // si c'est le meme jour
		    {
		      if (h_mat_1[index_h_m_1]->debut < h_mat_2[index_h_m_2]->fin || h_mat_2[index_h_m_2]->debut < h_mat_1[index_h_m_1]->fin) // si ça se chevauche
			{
			  res += "-> ";
			  res += matiere[i]->getNom();
			  res += " day : ";
			  res += h_mat_1[index_h_m_1]->jour;
			  res += " start : ";
			  res += to_string(h_mat_1[index_h_m_1]->debut);
			  res += "h end : ";
			  res += to_string(h_mat_1[index_h_m_1]->fin);
			  res += "h\n   Conflicts with :\n";

			  res += "-> ";
			  res += matiere[j]->getNom();
			  res += " day : ";
			  res += h_mat_2[index_h_m_2]->jour;
			  res += " start : ";
			  res += to_string(h_mat_2[index_h_m_2]->debut);
			  res += "h end : ";
			  res += to_string(h_mat_2[index_h_m_2]->fin);
			  res += "h\n";
			}
		    }
		  index_h_m_2++;
		}
	      index_h_m_1++;
	    }
	  j++;
	}
      i++;
    }

  return (res);
}

vector<Dicipline*> &Student::getMatiere()
{
  return (this->matiere);
}
