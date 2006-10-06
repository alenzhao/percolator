#ifndef SCORES_H_
#define SCORES_H_
#include <vector>
#include "IsoChargeSet.h"
using namespace std;

class ScoreHolder{
public:
  double score;
  int index;
  int label;
  int set;
  ScoreHolder() {score=0.0;index=0;label=0;set=0;}
  virtual ~ScoreHolder() {;}
  void operator = (const ScoreHolder& other)
    {score=other.score;index=other.index;label=other.label;set=other.set;}
};

bool operator>(const ScoreHolder &one, const ScoreHolder &other) 
    {return (one.score>other.score);}

class Scores
{
public:
	Scores();
	~Scores();
	double calcScore(const double *features);
	void calcScores(double *w, IsoChargeSet &set);
	void getPositiveTrainingIxs(double fdr,vector<int>& ixs);	
protected:
    double *w_vec;
    vector<ScoreHolder> scores;
};

#endif /*SCORES_H_*/