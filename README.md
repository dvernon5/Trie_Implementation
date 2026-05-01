# Trie Data Structure in C++

A simple trie implementation written in C++. Nothing fancy — just a clean, working trie that supports word insertion, search, and prefix checking.

---

## What's a Trie?

A trie (pronounced "try") is a tree-like data structure that stores strings character by character. Each node represents a single letter, and words are formed by following a path from the root down to a leaf. It's particularly good at prefix lookups, which makes it useful for things like autocomplete.

---

## What This Project Does

- **Insert** words into the trie
- **Search** for an exact word
- **Check prefixes** — does a given string exist as the start of any word?
- **Display** all stored words (traversal output)

---

## Project Structure

```
.
└── trie.cpp    # Everything lives here — TrieNode, TrieSystem, and main
```

Two classes keep things organized:

- `TrieNode` — holds the character data, 26 child pointers (one per letter), and an end-of-word flag
- `TrieSystem` — wraps the root node and exposes the public interface

---

## How to Build and Run

You'll need a C++ compiler (g++ works fine).

```bash
g++ -o trie trie.cpp
./trie
```

Expected output:

```
dad was found
cat was not found
da is a prefix
ca is not a prefix
andadt
```

---

## Example Usage

```cpp
TrieSystem root;

root.insert("and");
root.insert("ant");
root.insert("dad");

root.displaySearchResult("dad");   // dad was found
root.displaySearchResult("cat");   // cat was not found
root.displayPrefixResult("da");    // da is a prefix
root.displayPrefixResult("ca");    // ca is not a prefix

root.displayTrie();
```

---

## A Few Notes

- Only lowercase English letters are supported (`a–z`)
- Memory is handled automatically — `TrieSystem` cleans up after itself when it goes out of scope
- No external dependencies, just the standard library

---

## Why I Built This

Mostly as a learning exercise to get comfortable with tries, recursive memory management, and clean class design in C++. It's a good structure to build on if you want to add things like deletion or wildcard search later.
