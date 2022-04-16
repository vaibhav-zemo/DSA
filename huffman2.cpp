#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Node
{
public:
    char character;
    int freq;
    Node *left;
    Node *right;
    Node(char ch, int freq)
    {
        character = ch;
        this->freq = freq;
        left = NULL;
        right = NULL;
    }
};

void buildTree(string word)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < word.size(); i++)
    {
        freq[word[i]]++;
    }

    

    priority_queue<Node*,vector<Node*>,greater<Node*>> pq;
    for (int i = 0; i < freq.size(); i++)
    {
        pq.push(Node())
    }
    
}

void freq(string word)
{
}

int main()
{
    string st = "hello i am vaibhav pathak learning huffman coding";

    return 0;
}