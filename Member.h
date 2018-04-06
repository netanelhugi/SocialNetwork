#include <iostream>
#include <vector>
#include <map>


using namespace std;

// static int MembersCount = 0;//static variable that count the number of members
static int MemberID = 100000;//unique number for each member

class Member{

    int id;//for the unique number
    static int MembersCount;//static variable that count the number of members

    public:
    Member();//Default constructor
    ~Member();//destructor

    map <int,Member*> followers;//members follow this object
	map <int,Member*> following;//members this object follow 

    //follow&unfollow function
    void follow(Member& m);
    void unfollow(Member& m);

    int numFollowers();//return the number of members this object follow
    int numFollowing();//return the number of members who follow this object
    static int count();//return the number of the system's users

    
};