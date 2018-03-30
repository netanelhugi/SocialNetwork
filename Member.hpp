#include <iostream>
#include <vector>


using namespace std;

int MemberNum = 0;//static variable that count the number of members
int MemberID = 100000;//unique number for each member

class Member{

    string name;
    int id;//for the unique number
    int numFollowing;//number of members i follow
    int numfollowers;//number of members that follow me



    public:
    Member();//Default constructor
    Member(string fullName);//constructor with option to insert name to member
    
    //follow&unfollow function
    void follow(Member& m);
    void unfollow(Member& m);
    
    int getNumFollwing();//return the number of members this object follow
    int getNumFollwers();//return the number of members who follow this object
    vector<Member> following;//vector of the members this object follow
    vector<Member> followers;//vector of the members who follow this object
    bool checkFollow(Member m);//function to check if this object follow m

    //functions to find the index of member in vector
    int findFollowingIndex(Member m);
    int findFollowersIndex(Member t);

    //print the vector
    void printFollowingList();
    void printFollowersList();

};