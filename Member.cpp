#include <iostream>
#include <vector>
#include "Member.h"

using namespace std; 

/**
 *assignment 3 solution 
 *id: 203553490
 *
 *my unit test is in tests.cpp file.
 */

//constructor with option to insert name to member
Member::Member(string fullName) {  
    this->name = fullName;
    //init follow numbers
    this->numFollowers0 = 0;
    this->numFollowing0 = 0;
    //give a unique id for the member
    this->id = MemberID++;
    //counet members
    MembersCount++; 
}

//Default constructor
Member::Member(){
    //init follow numbers
    this->numFollowing0 = 0;
    this->numFollowers0 = 0;
    //give a unique id for the member
    this->id = MemberID++;
    //counet members
    MembersCount++;
}


Member::~Member(){
	MembersCount--;
	this->followers.clear();
}

void Member::follow(Member& m) {
    //check if i try to follow me
    if(id==m.id){
        cout << "You can not follow yourself!\n";
    }
    //check if i already follow him
    else if(this->checkFollow(m)==false){
        following.insert(following.begin()+numFollowing0,m);
        this->numFollowing0++; 
        m.followers.insert(m.followers.begin()+m.numFollowers0,*this);
        m.numFollowers0++;
    }
    else{
        cout << "You are already following this member!\n";
    } 
}

void Member::unfollow(Member& m){
    //check if i dont follow him
    if(this->checkFollow(m)==false){
        cout << "You are not following this member!\n";
    }
    else{
        //find index 
        int ing = findFollowingIndex(m);
        int ers = m.findFollowersIndex(*this);

        //delete the member from the vector
        following.erase(following.begin()+ing);
        numFollowing0--;
        //delete the member from the vector
        m.followers.erase(m.followers.begin()+ers);
        m.numFollowers0--;
    } 
}

//return the number of members this object follow
int Member::numFollowing(){
    return this->numFollowing0;
}

//return the number of members who follow this object
int Member::numFollowers(){
    return this->numFollowers0;
}

//function to check if this object follow m
//by the id of the member
bool Member::checkFollow(Member m){
    for(int i=0; i<numFollowing0; i++){     
         if(following[i].id==m.id){
             return true;
         }
    }
return false;
}


//functions to find the index of member in vector
int Member::findFollowingIndex(Member m){ 
    for(int i=0; i<numFollowing0; i++){     
         if(following[i].id==m.id){
             return i;
         }
    }
    return -1;
}
int Member::findFollowersIndex(Member t){
    for(int i=0; i<numFollowers0;i++){
        if(followers[i].id==t.id){
            return i;
        }
    }
    return -1;
}

//print the vectors
void Member::printFollowingList(){
    for(int i=0; i<numFollowing0; i++){
        cout << following[i].name << ", id: " <<following[i].id<< "\n";
    }
}
void Member::printFollowersList(){
    for(int i=0; i<numFollowers0; i++){
        cout << followers[i].name << ", id: " <<followers[i].id<< "\n";
    }
}

int Member::count(){
    return MembersCount;
}

