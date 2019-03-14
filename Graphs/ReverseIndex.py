#! /usr/bin/python

class Node:
    """
        Represents a node in the Trie
        The leaves have the boolean flag isTerminal set to true
    """
    def __init__(self, letter):
        self.letter = letter
        self.children = {}
        self.positions = []
        self.isTerminal = False

class Trie:
    def __init__(self):
        self.root = Node(' ')

    def __contains__(self, word):
        node = self.root;
        for c in word:
          if c not in  node.children:
            return False
          node = node.children[c]
        return node.isTerminal

    def __getitem__(self, word):
        node = self.root
        for c in word:
          if c not in node.children:
            node.children[c] = Node(c)
          node = node.children[c]
        node.isTerminal = True
        return node.positions

    def __str__(self):
        self.output([self.root])
        return ''
 
    def output(self, currentPath, indent=''):
        #Depth First Search
        currentNode=currentPath[-1]
        if currentNode.isTerminal:
            word=''.join([node.letter for node in currentPath])
            print indent+word+' '+str(currentNode.positions)
            indent+='  '
        for letter, node in sorted(currentNode.children.items()):
            self.output(currentPath[:]+[node], indent)

import re
def getWords(text):
	return re.sub(r'[^a-z0-9]', ' ', text.lower()).split()

def createIndex(text):
  trie = Trie()
  words = getWords(text)
  for pos, word in enumerate(words):
    trie[word].append(pos)
  return trie

def getIndex(trie, word):
  if word in trie:
    return trie[word]
  else:
    return []

import sys
def main():
  trie = createIndex(sys.argv[1])
  print getIndex(trie, 'cat')

if __name__ == "__main__":
  # execute only if run as a script
  main()

