#include <iostream>
#include <string>

class TrieNode {
  public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode() : endOfWord(false) {
      for (int idx = 0; idx < 26; idx++) {
        children[idx] = nullptr;
      }
    }
    void display() {
      for (int idx = 0; idx < 26; idx++) {
        if (children[idx] != nullptr) {
            std::cout << static_cast<char>('a' + idx);
            children[idx]->display();
        }
      }
    }
    ~TrieNode() {
      for (int idx = 0; idx < 26; idx++) {
        free(children[idx]);
      }
    }
};

class TrieSystem {
  public:
    TrieSystem() : root(new TrieNode()) {}
    void insert(const std::string& key);
    bool searchTrie(const std::string& key);
    bool isPrefix(const std::string& key);
    void displayTrie();
    void displaySearchResult(const std::string& key);
    void displayPrefixResult(const std::string& key);
    ~TrieSystem() { delete root; };

  private:
    TrieNode* root;
};

void TrieSystem::insert(const std::string& key) {
  TrieNode* curr = root;
  for (const auto& ch: key) {
    int index = ch - 'a';
    if (curr->children[index] == nullptr) {
      TrieNode* newNode = new TrieNode;
      curr->children[index] = newNode; // Connect curr position to new node.
    }
    // Move the curr pointer to the next existing node for the current character.
    curr = curr->children[index]; 
  }
  curr->endOfWord  = true;
}

bool TrieSystem::searchTrie(const std::string& key) {
  TrieNode* curr = root;
  for (const auto& ch: key) {
    int index = ch - 'a';
    if (curr->children[index] == nullptr) {
      return false;
    }
    curr = curr->children[index];
  }

  return curr->endOfWord;
}

bool TrieSystem::isPrefix(const std::string& key) {
  TrieNode* curr = root;
  for (const auto ch: key) {
    int index = ch - 'a';
    if (curr->children[index] == nullptr) {
      return false;
    }
    curr = curr->children[index];
  }

  return true;
}

void TrieSystem::displayTrie() {
  root->display();
  std::cout << "\n";
}

void TrieSystem::displaySearchResult(const std::string& key) {
  if (searchTrie(key)) {
    std::cout << key << " was found\n";
  } else {
    std::cout << key << " was not found\n";
  }
}

void TrieSystem::displayPrefixResult(const std::string& key) {
  if (isPrefix(key)) {
    std::cout << key << " is a prefix\n";
  } else {
    std::cout << key << " is not a prefix\n";
  }
}

int main(int argc, char* argv[]) {
  TrieSystem root;
  std::string key = "and";
  root.insert(key);
  key = "ant";
  root.insert(key);
  key = "dad";
  root.insert(key);
  key = "dad";
  root.displaySearchResult(key);
  key = "cat";
  root.displaySearchResult(key);
  key = "da";
  root.displayPrefixResult(key);
  key = "ca";
  root.displayPrefixResult(key);
  root.displayTrie();
  
  return 0;
}
