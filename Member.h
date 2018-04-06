#include <iostream>
#include <vector>


using namespace std;

static int MembersCount = 0;//static variable that count the number of members
static int MemberID = 100000;//unique number for each member

class Member{

    string name;
    int id;//for the unique number
    int numFollowing0;//number of members i follow
    int numFollowers0;//number of members that follow me


    public:
    Member();//Default constructor
    Member(string fullName);//constructor with option to insert name to member
    //~Member();
    
    //follow&unfollow function
    void follow(Member& m);
    void unfollow(Member& m);
    
    int numFollowers();//return the number of members this object follow
    int numFollowing();//return the number of members who follow this object

    vector<Member> following;//vector of the members this object follow
    vector<Member> followers;//vector of the members who follow this object

    bool checkFollow(Member m);//function to check if this object follow m
    static int count();

    //functions to find the index of member in vector
    int findFollowingIndex(Member m);
    int findFollowersIndex(Member t);

    //print the vector
    void printFollowingList();
    void printFollowersList();

    void setNUM(int n);

};