//
//  main.cpp
//  Card Shuffler Draft 4
//
//  Created by Jan Lao on 2/2/17.
//  Copyright © 2017 University Nevada, Reno. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include <assert.h>
#include <fstream>

using namespace std;

class Card{
public:
    int suit;
    int number;
};

class Deck{
public:
    int n = 1;
};

/////========================= Main Function ===================================
int main() {
    srand(time(NULL));
    int n=1;
    int r;
    
    ofstream myfile;
    myfile.open ("CardResult.txt", ios::app);
    myfile << "WELCOME TO CARD SHUFFLER!" << endl;
    myfile << "* The following numbers indicate (Suit   Value) of a card" << endl;
    myfile << "** For suits: 0 = Spade; 1 = Club; 2 = Heart; 3 = Club" << endl;
    myfile << "** For Values: 1 = Ace; 11 = Jack; 12 = Queen; 13 = King" << endl;
    myfile << "*** PLEASE NOTE: No mention of the assertion means assertion succeeded" << endl<< endl;
    
    ////----------------------Let's create the deck--------------------------------
    Card card;
    vector<Card> deck;
    for(int i=0; i<n; i++){ //Loop that describes the number of decks to shuffle in
        for(int j=0; j<4; j++){ //Loop that decides the suit
            for(int k=1; k<14; k++){ //Loop that describes the number val
                card.suit = j;
                card.number = k;
                deck.push_back(card);
            }
        }
    }
    
    //Check to see if the cards are generated.
    myfile << "BEFORE THE SHUFFLE" << endl;
    for(int q=0; q<52*n;q++){
        myfile << deck.at(q).suit << "\t";
        myfile << deck.at(q).number << endl;
    }
    
    myfile << "The number of decks used (n):" << "\t" << n << endl;
    myfile << "The total number of cards are:" << "\t" << deck.size() << endl;
    
    ////---------------------Let's shuffle the deck!-------------------------------
    Card Temporary;
    
    for(long int x = 0; x < 100000000 ; x++){
        //Selecting 2 random places
        int place1 = rand()%52*n;
        int place2 = rand()%52*n;
        
        //Swapping newly created temporary with 2 places etc. etc.
        Temporary = deck.at(place1);
        deck.at(place1) = deck.at(place2);
        deck.at(place2) = Temporary;
    }
    
    //Result after shuffling
    myfile << endl << "SHUFFLE EXECUTED" << endl;
    for(int r = 0; r<52*n; r++){
        myfile << deck.at(r).suit << "\t";
        myfile << deck.at(r).number << endl;
    }
    
    myfile << "The number of decks used:" << "\t" << n << endl;
    myfile << "The total number of cards are:" << "\t" << deck.size() << endl;
    
    ////---------------------------Test A or B?-------------------------------------
    
    if(n==1){
        myfile << endl << "Test A: Checking if there are any duplicates in one shuffled deck" << endl << endl;
        myfile << "Test B: NOT CONDUCTED--One deck needed" << endl << endl;
        assert(deck.size()==52);
    }
    else if(n!=1){
        myfile << endl << "Test A: NOT CONDUCTED--One deck required" << endl << endl;
        myfile << "Test B: Checking if there are any duplicates in multiple decks shuffled" << endl << endl;
        assert(deck.size()==52*n);
    }
    
    myfile.close();
    
    return 0;
}
