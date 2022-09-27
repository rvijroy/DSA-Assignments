#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

class GameEntry {
   public:
    GameEntry(const string &n = "", int s = 0);
    string getName() const;
    int getScore() const;

   private:
    string name;
    int score;
};

GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {
}

string GameEntry::getName() const { return name; }

int GameEntry::getScore() const { return score; }

class Scores {
   public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry &e);
    GameEntry remove(int i);
    void printAllScores();

   private:
    int maxEntries;      // maximum number of entries
    int numEntries;      // actual number of entries
    GameEntry *entries;  // array of game entries
};

Scores::Scores(int maxEnt) {              // constructor
    maxEntries = maxEnt;                  // save the max size
    entries = new GameEntry[maxEntries];  // allocate array storage
    numEntries = 0;                       // initially no elements
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry &e) {
    if (numEntries == maxEntries)  // the array is full
        return;

    // if not full, one more entry
    entries[numEntries] = e;  // put e in new spot
    numEntries++;
}

GameEntry Scores::remove(int i) {
    if ((i < 0) || (i >= numEntries))  // invalid index
        throw("IndexOutOfBounds - Invalid index");

    GameEntry e = entries[i];  // save the removed object
    entries[i] = entries[numEntries - 1];
    numEntries--;  // one fewer entry
    return e;      // return the removed object
}

void Scores::printAllScores() {
    for (int i = 0; i < numEntries; i++) {
        cout << entries[i].getName() << " : " << entries[i].getScore() << "\n";
    }
}
void showOptions() {
    cout
        << "1:	Add Player\n"
        << "2:	Remove Player By Index\n"
        << "3:	Print Scores\n"
        << "4:	Exit\n";
}
int main() {
    Scores scoresObj;
    int option;
    string playerName;
    int score;

    while (1) {
        showOptions();
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter Player Name and Score\n";
                cin >> playerName >> score;
                scoresObj.add(GameEntry(playerName, score));
                break;
            case 2:
                int index;
                cout << "Enter the index\n";
                cin >> index;
                scoresObj.remove(index);
                break;
            case 3:
                scoresObj.printAllScores();
                break;
            case 4:
                return EXIT_SUCCESS;
        }
    }
}