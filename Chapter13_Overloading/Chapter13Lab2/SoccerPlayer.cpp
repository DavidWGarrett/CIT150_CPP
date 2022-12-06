#include "SoccerPlayer.h"

// default constructor
SoccerPlayer::SoccerPlayer()
{
	this->setJerseyNumber(0);
	this->setGoals(0);
	this->setAssists(0);
}

// constructor
SoccerPlayer::SoccerPlayer(int jerseyNumber, int goals, int assists)
{
	this->setJerseyNumber(jerseyNumber);
	this->setGoals(goals);
	this->setAssists(assists);
}

// determines if first player has better stats than second player
bool SoccerPlayer::operator > (SoccerPlayer& player) const
{
	return ((this->goals + this->assists) > (player.goals + player.assists));
}

// output player info with cout
std::ostream& operator<<(std::ostream& output, const SoccerPlayer& player)
{
	output << "Soccer Player #" << player.getJerseyNumber() << " scored " << player.getGoals()
		<< " goals and had " << player.getAssists() << " assists." << std::endl;

	return output;
}

// input player info
void SoccerPlayer::operator >> (struct playerInfo player)
{
	//SoccerPlayer::SoccerPlayer(player.jerseyNumber, player.goals, player.assists);
	this->setJerseyNumber(player.jerseyNumber);
	this->setGoals(player.goals);
	this->setAssists(player.assists);
}
