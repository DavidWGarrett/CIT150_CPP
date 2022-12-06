#ifndef SOCCERPLAYER_H
#define SOCCERPLAYER_H

#include <iostream>

#pragma once

// used with >> operator
struct playerInfo
{
	int jerseyNumber;
	int goals;
	int assists;
};

class SoccerPlayer
{
	// Used to output player object info
	friend std::ostream& operator<<(std::ostream&, const SoccerPlayer&);
public:
	// setter/getters
	void setJerseyNumber(int jerseyNumber) { this->jerseyNumber = jerseyNumber; }
	int getJerseyNumber() const { return jerseyNumber; }
	void setGoals(int goals) { this->goals = goals; }
	int getGoals() const { return goals; }
	void setAssists(int assists) { this->assists = assists; }
	int getAssists() const { return assists; }

	// constructors
	SoccerPlayer();
	SoccerPlayer(int, int, int);

	// See which SoccerPlayer object has the most goals/assists
	bool operator > (SoccerPlayer& player) const;

	// Used to input player info
	void operator >> (struct playerInfo);

private:
	int jerseyNumber;
	int goals;
	int assists;
};

#endif