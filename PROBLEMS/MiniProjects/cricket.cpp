#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Team;
class Player;
class Match;

enum class TossDecision {
    Bat,
    Bowl
};

class Player {
public:
    string name;

    int runs = 0;
    int balls = 0;

    int ballsBowled = 0;
    int runsGiven = 0;
    int wicketsTaken = 0;
};

class Team {
public:
    string name;
    vector<Player*> players;
    string Captain;
    TossDecision decision;

    int runs = 0;
    int wickets = 0;
    int curballs = 0;
    int totballs = 0;

    int wides = 0;
    int noBalls = 0;
    int byes = 0;
    int legByes = 0;
};

class Match {
public:
    Team team1;
    Team team2;
    int overs = 0;
    string Tosswinner;
};

class MatchManager {
    Match* match = new Match();

public:
    void startMenu() {
        int choice;

        cout << "============================\n";
        cout << " SIMPLE CRICKET TRACKER\n";
        cout << "============================\n";
        cout << "1. Start Match\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            startMatch();
        }
        else {
            cout << "Exiting...\n";
        }
    }

    void startMatch() {
        GetTeamNames();
        GetOvers();
        GetToss();

        Team* firstBattingTeam = getFirstBattingTeam();
        Team* firstBowlingTeam = getOtherTeam(firstBattingTeam);

        cout << "\nFIRST INNINGS STARTING\n";
        GetOpeningPlayers(firstBattingTeam, firstBowlingTeam);
        runCounter(firstBattingTeam, firstBowlingTeam, 0);

        int target = firstBattingTeam->runs + 1;

        cout << "\nTARGET FOR " << firstBowlingTeam->name << ": " << target << "\n";

        int choice;
        cout << "Start second innings?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nSECOND INNINGS STARTING\n";
            GetOpeningPlayers(firstBowlingTeam, firstBattingTeam);
            runCounter(firstBowlingTeam, firstBattingTeam, target);
            showResult(firstBattingTeam, firstBowlingTeam, target);
        }
        else {
            cout << "Match stopped after first innings.\n";
        }
    }

    void GetTeamNames() {
        cout << "ENTER THE NAME OF HOST TEAM: ";
        cin >> match->team1.name;

        cout << "ENTER THE NAME OF VISITOR TEAM: ";
        cin >> match->team2.name;
    }

    void GetOvers() {
        cout << "OVERS: ";
        cin >> match->overs;

        while (match->overs <= 0 || match->overs > 20) {
            cout << "PLEASE ENTER OVERS BETWEEN 1 AND 20: ";
            cin >> match->overs;
        }

        match->team1.totballs = match->overs * 6;
        match->team2.totballs = match->overs * 6;
    }

    void GetToss() {
        int tossChoice;
        int choice;

        cout << "WHO WON THE TOSS?\n";
        cout << "1. " << match->team1.name << "\n";
        cout << "2. " << match->team2.name << "\n";
        cout << "Enter choice: ";
        cin >> tossChoice;

        if (tossChoice == 1) {
            match->Tosswinner = match->team1.name;
            cout << match->team1.name << " WON THE TOSS!!!\n";
            cout << "1. BAT\n2. BOWL\n";
            cout << "TYPE 1 or 2: ";
            cin >> choice;

            if (choice == 1) {
                match->team1.decision = TossDecision::Bat;
            }
            else {
                match->team1.decision = TossDecision::Bowl;
            }
        }
        else {
            match->Tosswinner = match->team2.name;
            cout << match->team2.name << " WON THE TOSS!!!\n";
            cout << "1. BAT\n2. BOWL\n";
            cout << "TYPE 1 or 2: ";
            cin >> choice;

            if (choice == 1) {
                match->team2.decision = TossDecision::Bat;
            }
            else {
                match->team2.decision = TossDecision::Bowl;
            }
        }
    }

    Team* getFirstBattingTeam() {
        if (match->Tosswinner == match->team1.name) {
            if (match->team1.decision == TossDecision::Bat) {
                return &match->team1;
            }
            return &match->team2;
        }

        if (match->team2.decision == TossDecision::Bat) {
            return &match->team2;
        }
        return &match->team1;
    }

    Team* getOtherTeam(Team* team) {
        if (team == &match->team1) {
            return &match->team2;
        }
        return &match->team1;
    }

    Player* createPlayer(string name) {
        Player* player = new Player();
        player->name = name;
        return player;
    }

    int findPlayerIndex(Team* team, string name) {
        for (size_t i = 0; i < team->players.size(); i++) {
            if (team->players[i]->name == name) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    void GetOpeningPlayers(Team* battingTeam, Team* bowlingTeam) {
        string name;

        cout << "ENTER STRIKER NAME: ";
        cin >> name;
        battingTeam->players.push_back(createPlayer(name));

        cout << "ENTER NON-STRIKER NAME: ";
        cin >> name;
        battingTeam->players.push_back(createPlayer(name));

        changeBowler(bowlingTeam);
    }

    void showScore(Team* battingTeam, Team* bowlingTeam) {
        cout << "\n****************************\n";
        cout << battingTeam->name << " "
             << battingTeam->runs << "/"
             << battingTeam->wickets << " in "
             << battingTeam->curballs / 6 << "."
             << battingTeam->curballs % 6
             << " overs\n";

        if (battingTeam->players.size() >= 2) {
            cout << "STRIKER: " << battingTeam->players[0]->name
                 << " " << battingTeam->players[0]->runs
                 << "(" << battingTeam->players[0]->balls << ")\n";

            cout << "NON-STRIKER: " << battingTeam->players[1]->name
                 << " " << battingTeam->players[1]->runs
                 << "(" << battingTeam->players[1]->balls << ")\n";
        }

        if (!bowlingTeam->players.empty()) {
            Player* bowler = bowlingTeam->players[0];
            cout << "BOWLER: " << bowler->name
                 << " Overs: " << bowler->ballsBowled / 6 << "." << bowler->ballsBowled % 6
                 << " Runs: " << bowler->runsGiven
                 << " Wickets: " << bowler->wicketsTaken
                 << " Economy: " << economy(bowler) << "\n";
        }

        cout << "Extras: "
             << "Wd " << battingTeam->wides
             << ", NB " << battingTeam->noBalls
             << ", B " << battingTeam->byes
             << ", LB " << battingTeam->legByes << "\n";
        cout << "****************************\n";
    }

    double economy(Player* bowler) {
        if (bowler->ballsBowled == 0) {
            return 0;
        }
        return (bowler->runsGiven * 6.0) / bowler->ballsBowled;
    }

    void showBattingCard(Team* team) {
        cout << "\nBATTING CARD - " << team->name << "\n";
        cout << "----------------------------\n";
        for (Player* player : team->players) {
            cout << player->name << " "
                 << player->runs << "(" << player->balls << ")\n";
        }
    }

    void showBowlingCard(Team* team) {
        cout << "\nBOWLING CARD - " << team->name << "\n";
        cout << "----------------------------\n";
        for (Player* player : team->players) {
            if (player->ballsBowled > 0) {
                cout << player->name
                     << " " << player->ballsBowled / 6 << "." << player->ballsBowled % 6
                     << "-" << player->runsGiven
                     << "-" << player->wicketsTaken
                     << " Econ: " << economy(player) << "\n";
            }
        }
    }

    void swapStrike(Team* battingTeam) {
        if (battingTeam->players.size() >= 2) {
            swap(battingTeam->players[0], battingTeam->players[1]);
        }
    }

    void newBatsman(Team* battingTeam) {
        if (battingTeam->wickets >= 10) {
            return;
        }

        string name;
        cout << "ENTER NEW BATSMAN NAME: ";
        cin >> name;

        Player* batsman = createPlayer(name);
        battingTeam->players.push_back(batsman);
        swap(battingTeam->players[0], battingTeam->players.back());
    }

    void changeBowler(Team* bowlingTeam) {
        string name;
        cout << "ENTER BOWLER NAME: ";
        cin >> name;

        int index = findPlayerIndex(bowlingTeam, name);

        if (index == -1) {
            bowlingTeam->players.push_back(createPlayer(name));
            swap(bowlingTeam->players[0], bowlingTeam->players.back());
        }
        else {
            swap(bowlingTeam->players[0], bowlingTeam->players[index]);
        }
    }

    void checkOverComplete(Team* battingTeam, Team* bowlingTeam) {
        if (battingTeam->curballs > 0 && battingTeam->curballs % 6 == 0 &&
            battingTeam->curballs < battingTeam->totballs) {
            cout << "\nOVER COMPLETED\n";
            swapStrike(battingTeam);
            changeBowler(bowlingTeam);
        }
    }

    void addLegalBall(Team* battingTeam, Team* bowlingTeam) {
        battingTeam->curballs++;
        bowlingTeam->players[0]->ballsBowled++;
    }

    void runCounter(Team* battingTeam, Team* bowlingTeam, int target) {
        int choice;

        while (battingTeam->wickets < 10 && battingTeam->curballs < battingTeam->totballs) {
            if (target > 0 && battingTeam->runs >= target) {
                break;
            }

            showScore(battingTeam, bowlingTeam);

            if (target > 0) {
                cout << "TARGET: " << target
                     << " | NEED " << target - battingTeam->runs << " RUNS\n";
            }

            cout << "1. Add runs\n";
            cout << "2. Wicket\n";
            cout << "3. Wide\n";
            cout << "4. No Ball\n";
            cout << "5. Bye\n";
            cout << "6. Leg Bye\n";
            cout << "7. End Innings\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                int runs;
                cout << "Enter runs: ";
                cin >> runs;

                battingTeam->runs += runs;
                battingTeam->players[0]->runs += runs;
                battingTeam->players[0]->balls++;
                bowlingTeam->players[0]->runsGiven += runs;
                addLegalBall(battingTeam, bowlingTeam);

                if (runs % 2 != 0) {
                    swapStrike(battingTeam);
                }

                checkOverComplete(battingTeam, bowlingTeam);
            }
            else if (choice == 2) {
                battingTeam->wickets++;
                battingTeam->players[0]->balls++;
                bowlingTeam->players[0]->wicketsTaken++;
                addLegalBall(battingTeam, bowlingTeam);

                cout << battingTeam->players[0]->name << " IS OUT!\n";
                newBatsman(battingTeam);
                checkOverComplete(battingTeam, bowlingTeam);
            }
            else if (choice == 3) {
                battingTeam->runs++;
                battingTeam->wides++;
                bowlingTeam->players[0]->runsGiven++;
            }
            else if (choice == 4) {
                int batRuns;
                cout << "Runs from bat on no ball? ";
                cin >> batRuns;

                battingTeam->runs += 1 + batRuns;
                battingTeam->noBalls++;
                battingTeam->players[0]->runs += batRuns;
                bowlingTeam->players[0]->runsGiven += 1 + batRuns;

                if (batRuns % 2 != 0) {
                    swapStrike(battingTeam);
                }
            }
            else if (choice == 5) {
                int runs;
                cout << "Enter bye runs: ";
                cin >> runs;

                battingTeam->runs += runs;
                battingTeam->byes += runs;
                battingTeam->players[0]->balls++;
                addLegalBall(battingTeam, bowlingTeam);

                if (runs % 2 != 0) {
                    swapStrike(battingTeam);
                }

                checkOverComplete(battingTeam, bowlingTeam);
            }
            else if (choice == 6) {
                int runs;
                cout << "Enter leg bye runs: ";
                cin >> runs;

                battingTeam->runs += runs;
                battingTeam->legByes += runs;
                battingTeam->players[0]->balls++;
                addLegalBall(battingTeam, bowlingTeam);

                if (runs % 2 != 0) {
                    swapStrike(battingTeam);
                }

                checkOverComplete(battingTeam, bowlingTeam);
            }
            else if (choice == 7) {
                break;
            }
            else {
                cout << "Invalid choice\n";
            }
        }

        cout << "\nINNINGS OVER\n";
        showScore(battingTeam, bowlingTeam);
        showBattingCard(battingTeam);
        showBowlingCard(bowlingTeam);
    }

    void showResult(Team* firstBattingTeam, Team* secondBattingTeam, int target) {
        cout << "\nMATCH RESULT\n";
        cout << "============================\n";

        if (secondBattingTeam->runs >= target) {
            int wicketsLeft = 10 - secondBattingTeam->wickets;
            cout << secondBattingTeam->name << " WON BY "
                 << wicketsLeft << " WICKETS\n";
        }
        else if (secondBattingTeam->runs == firstBattingTeam->runs) {
            cout << "MATCH TIED\n";
        }
        else {
            int runsMargin = firstBattingTeam->runs - secondBattingTeam->runs;
            cout << firstBattingTeam->name << " WON BY "
                 << runsMargin << " RUNS\n";
        }
    }
};

int main() {
    MatchManager* match = new MatchManager();
    match->startMenu();
    return 0;
}
