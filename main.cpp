#include <iostream>
using namespace std;

#include "Member.cpp"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.getNumFollwers() << " " <<  chana.getNumFollwing() << endl; // 0 1
	cout << "  " << avi.getNumFollwers() << " " <<  avi.getNumFollwing() << endl; // 1 0
	cout << "  " << MemberNum << endl; // 4
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

int main() {
    test2();
    test3();

    // avi.follow(avi);
	// cout << avi.getNumFollwers() << " " << avi.getNumFollwing() << endl; // 0 0
	// avi.follow(beni);
	// cout << avi.getNumFollwers() << " " << avi.getNumFollwing() << endl; // 0 1
	// cout << beni.getNumFollwers() << " " << beni.getNumFollwing() << endl; // 1 0
	// cout << MemberNum << endl; // 3
	// cout << endl;

	// avi.follow(beni); // duplicate follow has no effect
	// cout << avi.getNumFollwers() << " " << avi.getNumFollwing() << endl; // 0 1
	// avi.unfollow(beni);	
	// cout << avi.getNumFollwers() << " " << avi.getNumFollwing() << endl; // 0 0
	// cout << endl;

	// cout << chana.getNumFollwers() << " " <<  chana.getNumFollwing() << endl; // 0 0
	// test1();
	// cout << chana.getNumFollwers() << " " <<  chana.getNumFollwing() << endl; // 0 0
	// cout << avi.getNumFollwers() << " " <<  avi.getNumFollwing() << endl; // 0 0
	// cout << MemberNum << endl; // 3
}