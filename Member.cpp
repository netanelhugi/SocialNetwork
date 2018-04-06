#include "Member.h"

using namespace std;
int Member::MembersCount = 0;
map<int, Member *>::iterator it;

/**
 *assignment 3 solution 
 *id: 203553490
 *
 *my unit test is in tests.cpp file.
 */

//Default constructor
Member::Member()
{
    //give a unique id for the member
    this->id = MemberID++;
    //counet members
    MembersCount++;
}

Member::~Member()
{
    MembersCount--;

    for (it = followers.begin(); it != followers.end(); it++)
    {
        if (it->second->following.find(this->id) != it->second->following.end())
            it->second->following.erase(it->second->following.find(this->id));
    }
    for (it = following.begin(); it != following.end(); it++)
    {
        if (it->second->followers.find(this->id) != it->second->followers.end())
            it->second->followers.erase(it->second->followers.find(this->id));
    }
}

void Member::follow(Member &m)
{

    if (id == m.id)
    {
        cout << "You can not follow yourself!\n";
    }

    if (following.find(m.id) == following.end())
    {
        following.insert(pair<int, Member *>(m.id, &m));
        m.followers.insert(pair<int, Member *>(id, this));
    }
    else
    {
        cout << "You are already following this member!\n";
    }
}

void Member::unfollow(Member &m)
{

    map<int, Member *>::iterator it;
    it = following.find(m.id);

    if (it != following.end())
    {
        following.erase(it);
        m.followers.erase(m.followers.find(this->id));
    }
}

//return the number of members this object follow
int Member::numFollowing()
{
    return this->following.size();
}

//return the number of members who follow this object
int Member::numFollowers()
{
    return this->followers.size();
}

int Member::count()
{
    return MembersCount;
}
