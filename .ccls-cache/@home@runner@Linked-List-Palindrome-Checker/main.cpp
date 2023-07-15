#include <iostream>
#include <vector>
#include <limits> // Add this line
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        vector<int> values;
        ListNode* curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        int left = 0;
        int right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right])
                return false;
            left++;
            right--;
        }

        return true;
    }
};

// Function to create a linked list from user input
ListNode* createLinkedList() {
    int val;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter the elements of the linked list, separated by spaces (enter -1 to end):\n";
    cout << "Example: 1 2 3 -1\n";
    while (true) {
        if (!(cin >> val)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter integers only.\n";
            continue;
        }
        if (val == -1) {
            break;
        }
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

// Function to delete the linked list and free memory
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    char choice;

    cout << "=== Linked List Palindrome Checker ===\n\n";

    do {
        ListNode* head = createLinkedList();

        bool isPal = solution.isPalindrome(head);

        cout << "\n----------------------------------------\n";
        if (isPal) {
            cout << "The linked list is a palindrome.\n";
        } else {
            cout << "The linked list is not a palindrome.\n";
        }
        cout << "----------------------------------------\n";

        deleteLinkedList(head);

        while (true) {
            cout << "\nDo you want to test another linked list? (y/n): ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
                continue;
            }
            cout << endl;
            break;
        }
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Linked List Palindrome Checker. Have a great day!\n";

    return 0;
}
