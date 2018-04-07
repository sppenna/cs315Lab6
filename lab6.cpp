/*
Skyler Penna
CS315 Lab 6
Opens target text file and creates a dictionary using a Binary Search Tree, recording the 
number of words, line number the word appears on, and allows the user to search for particular words.
*/
#include "binarysearchtree.h"

//removes the punctuation from the input file
string tokenize(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (ispunct(str[i]) && str[i] != ' ') {
            str.erase(i);
        }
    }
    return str;
}

int main(int argc, char* argv[1]) {
    string str;
    int lineNum = 1, wordNum = 0;

    string d;

    ifstream dict;

    cout << "Enter a file name: ";
    cin >> d;
    cout << endl;

    dict.open(d.c_str());

    BinarySearchTree<string> t;
    
    //initialize variables to record function speed.
    double finish_time, start_time = clock();
    
    while (getline(dict, str)) {

        istringstream iss (str);

        string word;
        //reads each string separated by ' ' call tokenize function to remove punctuation    
        while (iss >> word) {
            word = tokenize(word);
            t.insert(word, lineNum);
            wordNum++;
        }
        lineNum++;   
    }
    
    finish_time = clock();
    double time = (finish_time-start_time) / CLOCKS_PER_SEC;

    //user inputs
    cout << "Total number of words: " << right << setw(24) << wordNum << endl;
    cout << "Total number of distinct words: " << right << setw(15) << t.size(t.getRoot()) << endl;
    cout << "Time taken to build the tree: " << right << setw(23) << time << endl;
    cout << "Height of the tree: " << right << setw(26) << t.height(t.getRoot()) << endl;
    cout << "---------------------------------" << endl;
    cout << "Options: (1) Display Index, (2) Search, (3) Save Index, (4) Quit "<< endl;
    string in;
    cin >> in;
    while (in != "4") {
        if (in == "1") {
            cout << endl;
            t.printTree();
            cout << "Options: (1) Display Index, (2) Search, (3) Save Index, (4) Quit"<< endl;
            cin >> in;
        } else if (in == "2") {
            cout << endl;
            cout << "Search word? ";
            string w;
            cin >> w;
            t.search(w);
            cout << "Options: (1) Display Index, (2) Search, (3) Save Index, (4) Quit"<< endl;
            cin >> in;
        } else if (in == "3") {
            string input;
            cout << "Enter the file name for the saved tree: ";
            cin >> input;
            ofstream fileName(input.c_str());
            t.printTree(fileName);
            cout << endl;
            cout << "Options: (1) Display Index, (2) Search, (3) Save Index, (4) Quit"<< endl;
            cin >> in;
        } else {
            return 0;
        }
    
    }
}

