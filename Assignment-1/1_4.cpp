#include <bits/stdc++.h>
#include <assert.h>

using namespace std;


struct Node {
    int idx;
    Node* next = nullptr;

    Node(int idx) : idx(idx) {}
};


Node* find_harshit(Node* head) {
    Node* slow = head, *fast = head;

    while (slow and fast) {
        slow = slow->next;
        fast = fast->next;

        // This condition is not possible if there is a cycle in the list.
        // We assume that there is always a Harshit in the friend group.
        assert(fast != nullptr);
        fast = fast->next;

        if (slow == fast) break;
    }

    // We assume that there is always a cycle. 
    // The only other way the loop can exit is if slow or fast become null.
    // But that can happen only if there are no cycles contrary to our assumption. 
    assert(slow == fast);

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


int main() {
    int n;
    cin >> n;

    vector<Node*> friends(n);

    for (int i = 0; i < n; ++i) {
        friends[i] = new Node(i);
    }

    int owed;
    for (int i = 0; i < n; ++i) {
        cin >> owed;
        friends[i]->next = friends[owed];
    }

    Node* harshit = find_harshit(friends[0]);
    cout << harshit->idx;
    return 0;
}

// Sample Input: (from the example given in problem)
// 9
// 1 2 3 4 5 6 7 8 3
