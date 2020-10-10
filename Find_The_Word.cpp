//Bobble C++ Assessment Problem 1: Find the Word

#include <bits/stdc++.h> 
#include <iostream>
#include<fstream>

using namespace std;

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
	string val;

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key,string value) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->val = value ; 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
struct TrieNode * search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return NULL; 

		pCrawl = pCrawl->children[index]; 
	} 

	if(pCrawl != NULL && pCrawl->isEndOfWord)
	return pCrawl;
	else
	return NULL; 
} 




int main()
{
    ifstream fin;
    //freopen("triesss.txt","w",stdout);
    string line;
    struct TrieNode *root = getNode();
    // Open an existing file
    fin.open("EnglishDictionary.csv");
     while(!fin.eof()){

            fin>>line;
            //cout<<line<<" "<<endl;
            
            std::stringstream str_strm(line);
   			string tmp;
   			vector<string> words;
   			words.clear();
   			char delim = ','; // Ddefine the delimiter to split by

		   while (std::getline(str_strm, tmp, delim)) {
		      words.push_back(tmp);
		   }

            //cout<<*words.begin()<<" "<<*(words.begin()+1)<<endl;
            insert(root, *words.begin(),*(words.begin()+1));
          
	}
	string word_search;
	cout<<"Enter the word to be searched in dictionary:";
	cin>>word_search;
	struct TrieNode *temp = search(root,word_search);
	
	if(temp==NULL)
	cout<<"NO"<<endl;
	else
	cout<<"YES"<<","<<temp->val<<endl;

            

    return 0;
}

/*

----------Input/Output-----------
-> g++ -o a.exe Find_The_Word.cpp
->a
Enter a word to be searched in dictionary:
->wow
YES,158

*/
