#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"

int main()
{
	Trie trie;
	std::vector<std::string> listWords{"can", "cat", "come", "do", "i", "in", "inn"};
	for (auto& str : listWords)
	{
		trie.insert(str);
	}
	std::cout << trie.startWith("ca") << std::endl;
	std::cout << trie.search("cddadt") << std::endl;

}
