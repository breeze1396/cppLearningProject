#pragma once
#include <vector>
#include <string>
#include <utility>
#include <memory>

struct TrieNode
{
	TrieNode() {
		children.resize(26);
		isWord = false;
	}
	std::vector<std::unique_ptr<TrieNode>> children;
	bool isWord;
};

class Trie
{
public:
	Trie() = default;
	~Trie() = default;
	void insert(const std::string s);
	bool startWith(const std::string s);
	bool search(const std::string s);
private:
	TrieNode root;
};


inline void Trie::insert(const std::string s)
{
	TrieNode* node = &root;
	for (auto c : s)
	{
		if (node->children[c - 'a'] == nullptr)
		{
			node->children[c - 'a'] = std::make_unique<TrieNode>();
		}
		node = node->children[c - 'a'].get();
	}
	node->isWord = true;
}

inline bool Trie::startWith(const std::string s)
{
	TrieNode* node = &root;
	for (auto c : s)
	{
		if (node->children[c - 'a'] == nullptr)
		{
			return false;
		}
		node = node->children[c - 'a'].get();
	}
	return true;
}

inline bool Trie::search(const std::string s)
{
	TrieNode* node = &root;
	for (auto c : s)
	{
		if (node->children[c - 'a'] == nullptr)
		{
			return false;
		}
		node = node->children[c - 'a'].get();
	}
	return node->isWord;
}
