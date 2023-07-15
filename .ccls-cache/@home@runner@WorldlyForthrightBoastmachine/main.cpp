#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next)
      return true;

    vector<int> values;
    ListNode *curr = head;
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
ListNode *createLinkedList() {
  int val;
  ListNode *head = nullptr;
  ListNode *tail = nullptr;

  cout << "Enter the elements of the linked list (enter -1 to end):\n";
  while (true) {
    cin >> val;
    if (val == -1) {
      break;
    }
    ListNode *newNode = new ListNode(val);
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
void deleteLinkedList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Solution solution;
  char choice;

  cout << "=== Linked List Palindrome Checker ===\n\n";

  do {
    ListNode *head = createLinkedList();

    bool isPal = solution.isPalindrome(head);
    if (isPal) {
      cout << "\nThe linked list is a palindrome.\n";
    } else {
      cout << "\nThe linked list is not a palindrome.\n";
    }

    deleteLinkedList(head);

    cout << "\nDo you want to test another linked list? (y/n): ";
    cin >> choice;
    cout << endl;
  } while (choice == 'y' || choice == 'Y');

  cout << "Thank you for using the Linked List Palindrome Checker. Goodbye!\n";

  return 0;
}
