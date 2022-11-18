#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, string>> arr(n);
    unordered_map<string, int> total_score;
    for (auto &[score, name] : arr)
    {
        cin >> name >> score;
        total_score[name] += score;
    }

    set<string> winners;
    int max_score = numeric_limits<int>::min();

    for (auto &[name, score] : total_score)
    {
        // cout << name << " " << score << " " << max_score << "\n";
        if (score > max_score)
        {
            winners = set<string>();
            winners.insert(name);
            max_score = score;
        }
        else if (score == max_score)
            winners.insert(name);
    }

    // cout << "Printing winners: \n";
    // for (auto w: winners) cout << w << " ";
    // cout << "\n";

    // cout << "Trying to tie break: \n";
    unordered_map<string, int> curr_score;
    for (auto &[score, name] : arr)
    {
        if (winners.find(name) == winners.end()) {
            // cout << name << " was not a winner. Continuing.\n";    
            continue;
        }

        // cout << name << " " << score << "\n";
        curr_score[name] += score;
        if (curr_score[name] >= max_score) {
            cout << name << "\n";
            return 0;
        }
    }

    return 0;
}