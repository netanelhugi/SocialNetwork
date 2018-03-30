#include <iostream>
#include <vector>
#include "Member.hpp"

using namespace std; 

//constructor with option to insert name to member
Member::Member(string fullName) {  
    this->name = fullName;
    //init follow numbers
    this->numfollowers = 0;
    this->numFollowing = 0;
    //give a unique id for the member
    this->id = MemberID++;
    //counet members
    MemberNum++; 
}

//Default constructor
Member::Member(){
    //init follow numbers
    this->numFollowing = 0;
    this->numfollowers = 0;
    //give a unique id for the member
    this->id = MemberID++;
    //counet members
    MemberNum++;
}

void Member::follow(Member& m) {
    //check if i try to follow me
    if(id==m.id){
        cout << "You can not follow yourself!\n";
    }
    //check if i already follow him
    else if(this->checkFollow(m)==false){
        following.insert(following.begin()+numFollowing,m);
        this->numFollowing++; 
        m.followers.insert(m.followers.begin()+m.numfollowers,*this);
        m.numfollowers++;
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
        numFollowing--;
        //delete the member from the vector
        m.followers.erase(m.followers.begin()+ers);
        m.numfollowers--;
    } 
}

//return the number of members this object follow
int Member::getNumFollwing(){
    return this->numFollowing;
}

//return the number of members who follow this object
int Member::getNumFollwers(){
    return this->numfollowers;
}

//function to check if this object follow m
//by the id of the member
bool Member::checkFollow(Member m){
    for(int i=0; i<numFollowing; i++){     
         if(following[i].id==m.id){
             return true;
         }
    }
return false;
}


//functions to find the index of member in vector
int Member::findFollowingIndex(Member m){ 
    for(int i=0; i<numFollowing; i++){     
         if(following[i].id==m.id){
             return i;
         }
    }
    return -1;
}
int Member::findFollowersIndex(Member t){
    for(int i=0; i<numfollowers;i++){
        if(followers[i].id==t.id){
            return i;
        }
    }
    return -1;
}

//print the vectors
void Member::printFollowingList(){
    for(int i=0; i<numFollowing; i++){
        cout << following[i].name << ", id: " <<following[i].id<< "\n";
    }
}
void Member::printFollowersList(){
    for(int i=0; i<numfollowers; i++){
        cout << followers[i].name << ", id: " <<followers[i].id<< "\n";
    }
}

// int main(){

//     Member a("a");
//     Member b("b");
//     Member c("c");
//     Member d("d");
//     Member ofek;

//     a.follow(b);
//     c.follow(b);
//     a.follow(c);
//     // a.follow(d);
//     ofek.follow(b);

//     ofek.printFollowingList();


//     // cout << "check num followers0: " << b.getNumFollwers()<< "\n";
    

//         // cout << "my network members: " << MemberNum << "\n";
//         //a.printFollowingList();
//         // b.printFollowersList();

//         // a.unfollow(b);
//         // cout << "after unfollow\n";
//         // //a.printFollowingList();

//         // cout << "followers\n";

//         // b.printFollowersList();

//         //cout << a.getNumFollwing() << "\n";
//         //cout << a.checkFollow(b) << "\n";
//         //cout << a.findFollowingIndex(c) << "\n";

//     return 0;

// }