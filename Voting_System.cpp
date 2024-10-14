#include <iostream>
#include <string>
using namespace std;

class VotingSystem {
private:
    string candidates[3];      // List of candidates
    int votes[3] = {0, 0, 0};  // Array to store votes for each candidate

public:
    // Constructor to initialize the candidates
    VotingSystem() {
        candidates[0] = "Alice";
        candidates[1] = "Bob";
        candidates[2] = "Charlie";
    }

    // Function to display the list of candidates
    void displayCandidates() {
        cout << "List of candidates:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << candidates[i] << endl;
        }
    }

    // Function to vote for a candidate
    void vote(int candidateNumber) {
        if (candidateNumber >= 1 && candidateNumber <= 3) {
            votes[candidateNumber - 1]++;
            cout << "You voted for " << candidates[candidateNumber - 1] << "!\n";
        } else {
            cout << "Invalid candidate number. Please vote again.\n";
        }
    }

    // Function to display the voting results
    void displayResults() {
        cout << "\nVoting results:\n";
        for (int i = 0; i < 3; i++) {
            cout << candidates[i] << " received " << votes[i] << " votes.\n";
        }

        // Find the candidate with the most votes
        int maxVotes = 0;
        int winnerIndex = -1;
        for (int i = 0; i < 3; i++) {
            if (votes[i] > maxVotes) {
                maxVotes = votes[i];
                winnerIndex = i;
            }
        }

        if (maxVotes > 0) {
            cout << "\nThe winner is " << candidates[winnerIndex] << " with " << maxVotes << " votes!\n";
        } else {
            cout << "\nNo votes were cast.\n";
        }
    }
};

int main() {
    VotingSystem votingSystem;
    int choice;

    while (true) {
        cout << "\n===== Voting Menu =====\n";
        cout << "1. View Candidates\n";
        cout << "2. Vote\n";
        cout << "3. View Results\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                votingSystem.displayCandidates();
                break;
            case 2: {
                int candidateNumber;
                votingSystem.displayCandidates();
                cout << "Enter the candidate number to vote for: ";
                cin >> candidateNumber;
                votingSystem.vote(candidateNumber);
                break;
            }
            case 3:
                votingSystem.displayResults();
                break;
            case 4:
                cout << "Thank you for participating in the voting system!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
