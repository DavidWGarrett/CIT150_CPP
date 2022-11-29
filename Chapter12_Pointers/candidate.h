#ifndef H_candidate
#define H_candidate

#pragma once

#include <iostream>

// Candidate objects has variables for the name, number of votes, vote share, and if candidate is winner

class Candidate
{
public:

	// constructor
	Candidate() { name = ""; votes = 0; voteShare = 0.0; winner = false; }
	Candidate(std::string name, int votes) { setName(name); setVotes(votes); voteShare = 0.0; winner = false; }

	// mutators/accessors
	std::string getName() const { return name; }
	void setName(std::string name) { this->name = name; }
	int getVotes() const { return votes; }
	void setVotes(int votes) { this->votes = votes; }
	double getVoteShare() const { return voteShare; }
	void setVoteShare(double voteShare) { this->voteShare = voteShare; }
	bool getWinner() const { return winner; }
	void setWinner(bool winner) { this->winner = winner; }
private:
	std::string name;
	int votes;
	double voteShare;
	bool winner;
};


#endif