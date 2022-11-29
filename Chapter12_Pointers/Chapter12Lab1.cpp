/*
David Garrett
Chapter 12 Lab 1
11-28-22
*/

#include <iostream>
#include <iomanip>
#include "candidate.h" // Candidate class
#include "election.h" // Election class

void inputCandidateInfo(Candidate candidates[], int arraySize); // User inputs info about candidates
void calculateVote(Candidate candidates[], Election* election, int arraySize); // calculate vote total and percentage
void displayResults(Candidate candidates[], Election* election, int arraySize); // print results

int main()
{
    Candidate* candidates; // Points to the address of the candidates. 
    Election* election;
    int numberOfCandidates;
    int totalVotes = 0;

    std::cout << "Enter the number of candidates: "; // Value user inputs is used to create dynamic array
    std::cin >> numberOfCandidates;

    candidates = new Candidate[numberOfCandidates]; // Creates dynamic array of candidates
    election = new Election;

    inputCandidateInfo(candidates, numberOfCandidates); // User inputs info about candidates
    calculateVote(candidates, election, numberOfCandidates);  // calculate vote total and percentage
    displayResults(candidates, election, numberOfCandidates); // print results

    delete [] candidates; // delete dynamic array
    delete election;

    return 0;

}

void inputCandidateInfo(Candidate candidates[], int arraySize)
{
    // Iterates through the array of candidates
    // Sets the name and number of votes

    for (int i = 0; i < arraySize; i++)
    {
        std::string name;
        int votes;

        std::cout << "Enter in candidate " << i + 1 << "'s name: ";
        std::cin >> name;

        candidates[i].setName(name);

        std::cout << "Enter the votes received by " << candidates[i].getName() << ": ";
        std::cin >> votes;

        candidates[i].setVotes(votes);
    }
}

void calculateVote(Candidate candidates[], Election* election, int arraySize)
{
    int highestVoteTotal = 0;
    int winner = -1;

    // Add all the votes for each candidate

    for (int i = 0; i < arraySize; i++)
        election->addToTotalVotes(candidates[i].getVotes());

    // Finds the percentage of vote share

    for (int i = 0; i < arraySize; i++)
    {
        double voteShare = candidates[i].getVotes() / (double) election->getTotalVote();

        candidates[i].setVoteShare(voteShare);

        if (highestVoteTotal < candidates[i].getVotes()) // Test to see if candidate has the most votes
        {
            highestVoteTotal = candidates[i].getVotes();
            winner = i;
        }
    }

    candidates[winner].setWinner(true); // Candidate with most votes is set to winner
}

// Display Candidate names, votes, vote percentage, total votes, and the winner

void displayResults(Candidate candidates[], Election* election, int arraySize)
{
    std::string winner;

    std::cout << "\n\nCandidate" << std::setw(20) << "Votes Received" <<
        std::setw(20) << "% of Total Votes" << std::endl;

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << std::setw(19) << std::left << candidates[i].getName() << std::setw(18) << candidates[i].getVotes()
                  << std::setw(19) << std::showpoint << std::fixed << std::setprecision(2) << candidates[i].getVoteShare() * 100 << std::endl;

        if (candidates[i].getWinner() == true)
        {
            winner = candidates[i].getName();
        }
    }

    std::cout << std::setw(19) << std::left << "Total" << election->getTotalVote() << std::endl
        << "The Winner of the Election is " << winner << "." << std::endl;
    
}

