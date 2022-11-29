#ifndef H_election
#define H_election

#pragma once

#include <iostream>

// Election class stores the number of total votes


class Election
{
public:
	// constructor
	Election() { totalVote = 0; }

	// mutator/accessor
	int getTotalVote() { return totalVote; }
	void setTotalVote(int totalVote) { this->totalVote = totalVote; }

	void addToTotalVotes(int vote) { totalVote += vote; } // Can add to the vote count
private:
	int totalVote;
};

#endif