#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Player Class
class Player {
	string name;
	int totalScore;
	int ballsPlayed;
public:		
	Player() { // Intialization
		totalScore = 0;
		ballsPlayed = 0;
	}
	
	// Sets Player's Name
	void setName(string playerName){
		name = playerName;
	}
	
	string getName() {
		return name;
	}
	
	// Sets Player's Scores
	void setScore(int obtainedScore){
		totalScore += obtainedScore;
	}
	
	int getScore() {
		return totalScore;
	}
	
	// Sets Number of Balls Played
	void setBalls(int numOfBalls){
		ballsPlayed += numOfBalls;
	}
	
	int getBalls() {
		return ballsPlayed;
	}
};

// Calculates Scores obtained by Player on each ball and Updates Scores and Balls
int calculateScores(Player *p) {
	
	cout << "Scores Per Ball: ";
	int num;
	
	 while (true) {
	        int num = -1 + rand() % (6 - (-1) + 1); // Generates numbers from -1 to 6
	        
	        if (num == -1) {
	        	p->setBalls(1); // Increaments each ball played
	            cout << "OUT!" << endl;
	            break; // Exit the loop if -1 is generated
	        } else if (num != 5) {
	        	p->setBalls(1);
	        	p->setScore(num); //Increases the Player's Score
	            cout << num << ", ";
	        }
	    }

	return num;
}

int main() {
	
	srand(time(NULL)); // For Randum Numbers Time Complexity
		
	string PlayerNames[11] = {"Babar Azam", 
							"Naseem Shah", 
							"Agha Salman", 
							"Mohammad Amir", 
							"Shaheen Afridi", 
							"Shadab Khan", 
							"Imad Wasim", 
							"Fakhar Zaman", 
							"Haris Rauf", 
							"Mohammad Rizwan", 
							"Iftikhar Ahmed"};
	
	Player player[11]; // Intialization of 11 Player Instances
	
	
	// Setting the Players names according to array given
	for(int i = 0; i < 11; i++){
		player[i].setName(PlayerNames[i]);
	}
	
	
	// Each Turn is given to Player for Total Scores calculation
	for(int i= 0; i<11; i++){
		cout << i + 1 << ". ";
		cout << player[i].getName() << endl;
		calculateScores(&player[i]);
		
		cout << "Total Score: " << player[i].getScore()
             << right << setw(20) << "Balls Played: " << player[i].getBalls() << endl;
		
		
		cout << endl;
	}
	

   // Match Summary of All Players
    cout << "<<<<<<<<< Match Summary >>>>>>>>" << endl;
    cout << left << setw(16) << "Player Name" << setw(8) << "Score" << setw(12) << "Balls Played" << endl;
    
    
    // Summary Details of Each Player
    for (int i = 0; i < 11; i++) {
        cout << left << setw(16) << player[i].getName()
             << setw(8) << player[i].getScore()
             << setw(12) << player[i].getBalls() << endl;
    }
    
    
    // Highest Score Calculation and Man of the Match Announcement
    int maxScore = player[0].getScore();
    string TopPlayerName = player[0].getName();
    
    for(int i = 1; i < 11; ++i){
    	if(player[i].getScore() > maxScore){
    		maxScore = player[i].getScore();
    		TopPlayerName = player[i].getName();
		}
	}
	
	cout << "\nMan of the Match: " << TopPlayerName << endl;
	
	return 0;
}
