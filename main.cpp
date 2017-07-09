#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include<cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
/*
have a vector <node> , node ->string (word),offest of info about it in file
first
call class add to write in file use small data (10words)
add get info from file player have  tries
after it he is lose
but corect char not in tries
*/
int maxtries=5;
string to_go="";
string wor="";
struct node{
    string word;
    int offest;
};
struct info{
    char info1[100];

};
vector<node>words;
void z(){
      cout<<"                      +----+ "<<endl;
      cout<<"                      |    | "<<endl;
      cout<<"                      |    O  "<<endl;
      cout<<"                      |   /|\\ "<<endl;
      cout<<"                      |   / \\ "<<endl;
}
 int rand_num(){
    while(true){
     int siz=words.size();
     int i=rand() % 10+1;
     if(i<=siz){
        return i;
     }
    }
 }
  bool is_here(char w){
     for(int j=0;j<wor.size();j++){
        if(wor[j]==w){
            wor[j]='*';
            to_go[j]=w;
            return true;
        }
     }
     return false;
 }
 string chooses_word(int i){
     string w=words[i].word;
     wor=w;
     for(int j=0;j<w.size();j++){cout<<"* ";to_go+="*";}
     cout<<endl;
     return w;
 }
 bool check(string h){if(h==to_go){return true;}else{return false;}}
 bool try_to_guess( string word_from_list){
     string h=word_from_list;
     cout<<"all char will be lower case "<<endl;
     while(true){
        cout<<"guess one :- ";
        char w;
        cin>>w;
        if(w=='*'){continue;}
        bool tries=is_here(w);
        if(tries==0){
            maxtries--;
            cout<<"wrong char ,try again"<<endl;
        }else{
            cout<<"------------ correct ---------------- "<<endl;
            cout<<"            "<<to_go<<endl;
        }
        if(maxtries==-1){
            return false;
        }
        else{
            if(check(h)){
                return true;
            }

        }
     }

 }
class add{
public:
    string info1,info2,info3,info4,info5,info6,info7,info8,info9,info10;
    char infot1[100],infot2[100],infot3[100],infot4[100],infot5[100],infot6[100],infot7[100],infot8[100],infot9[100],infot10[100];
    node node1,node2,node3,node4,node5,node6,node7,node8,node9,node10;
    void inzalitiation(){
        node1.offest=0*100;node1.word="india";words.push_back(node1);
        node2.offest=1*100;node2.word="engineer";words.push_back(node2);
        node3.offest=2*100;node3.word="policeman";words.push_back(node3);
        node4.offest=3*100;node4.word="grape";words.push_back(node4);
        node5.offest=4*100;node5.word="car";words.push_back(node5);
        node6.offest=5*100;node6.word="twitter";words.push_back(node6);
        node7.offest=6*100;node7.word="wristwatch";words.push_back(node7);
        node8.offest=7*100;node8.word="cat";words.push_back(node8);
        node9.offest=8*100;node9.word="key";words.push_back(node9);
        node10.offest=9*100;node10.word="knife";words.push_back(node10);
        info1="country in Asia";
        info2="who study math in College";
        info3="who keep country safe";
        info4="Fruit has more than one colors";
        info5="make to arrival to place";
        info6="social media network";
        info7="some thing in your hand";
        info8="pet";
        info9="to open";
        info10="cut it";

    }
    void put_in_char(){
        strcpy(infot1,info1.c_str());
        strcpy(infot2,info2.c_str());
        strcpy(infot3,info3.c_str());
        strcpy(infot4,info4.c_str());
        strcpy(infot5,info5.c_str());
        strcpy(infot6,info6.c_str());
        strcpy(infot7,info7.c_str());
        strcpy(infot8,info8.c_str());
        strcpy(infot9,info9.c_str());
        strcpy(infot10,info10.c_str());
    }
    void write_in_file(){
        inzalitiation();
        put_in_char();
        fstream file;
        file.open("info.txt",ios::in|ios::out);
        file.seekg(words[0].offest,ios::beg);
        file.write((char*)&infot1,sizeof(infot1));
        ////////////////////////////
        file.seekg(words[1].offest,ios::beg);
        file.write((char*)&infot2,sizeof(infot2));
        ////////////////////////////////////////
        file.seekg(words[2].offest,ios::beg);
        file.write((char*)&infot3,sizeof(infot3));
        ////////////////////////////////////
        file.seekg(words[3].offest,ios::beg);
        file.write((char*)&infot4,sizeof(infot4));
        /////////////////////////////////////////////
        file.seekg(words[4].offest,ios::beg);
        file.write((char*)&infot5,sizeof(infot5));
        /////////////////////////////////////////////
        file.seekg(words[5].offest,ios::beg);
        file.write((char*)&infot6,sizeof(infot6));
        ////////////////////////////////////////////
        file.seekg(words[6].offest,ios::beg);
        file.write((char*)&infot7,sizeof(infot7));
        /////////////////////////////////////////////
        file.seekg(words[7].offest,ios::beg);
        file.write((char*)&infot8,sizeof(infot8));
        //////////////////////////////////////////////
        file.seekg(words[8].offest,ios::beg);
        file.write((char*)&infot9,sizeof(infot9));
        //////////////////////////////////////////////////
        file.seekg(words[9].offest,ios::beg);
        file.write((char*)&infot10,sizeof(infot10));
        file.close();


    }
};
int main()
{
    add d;
    d.write_in_file();
   fstream file;
    file.open("info.txt",ios::in|ios::out);
    cout << "\n\nWelcome to hangman...Guess a word from the info will appear in consle";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << maxtries << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;;
	int rand_number=rand_num();
	cout<<rand_number<<endl;
	file.seekg(words[rand_number].offest,ios::beg);
	char q[100];
	file.read((char*)q,sizeof(q));
	cout<<" ----------- info about word --------------------"<<endl;
	cout<<"-------------"<<q<<"------------------"<<endl;
	string word_from_list=chooses_word(rand_number);
	if(try_to_guess( word_from_list)){
        cout<<"you are winer "<<endl;
        cout<<"the word is "<<to_go<<endl;
	}else{
	    cout<<"loser "<<endl;
	    z();

	}


    return 0;
}
