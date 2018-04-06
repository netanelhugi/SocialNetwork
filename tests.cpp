#include <iostream>
using namespace std;

#include "Member.cpp"


Member avi, beni, chana;

void test1() {
    //assignment test1
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

void test2(){
    //test to chack if member can follow himself
    Member eli;

    eli.follow(eli);//You can not follow yourself!
}

void test3(){
    //test if member can unfollow another members without he follow him
    
    avi.unfollow(beni);//You are not following this member!
}