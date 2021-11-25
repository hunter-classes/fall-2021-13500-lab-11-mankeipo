#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("TASK A") {
	Profile p1("marco", "Marco");
	Profile p2;
	CHECK(p1.getUsername() == "marco");
	CHECK(p1.getFullName() == "Marco (@marco)");
	CHECK(p2.getUsername() == "");
        CHECK(p2.getFullName() == " (@)");
	p1.setDisplayName("Marco Rossi");
	CHECK(p1.getUsername() == "marco");
        CHECK(p1.getFullName() == "Marco Rossi (@marco)");
}

TEST_CASE("TASK B") {
	Network nw;
	CHECK(nw.addUser("mario", "Mario") == true);
	CHECK(nw.addUser("luigi", "Luigi") == true);
	CHECK(nw.addUser("mario", "Mario2") == false);
	CHECK(nw.addUser("mario 2", "Mario2") == false);
	for(int i = 2; i < 20; i++) {
		nw.addUser("mario" + to_string(i),"Mario" + to_string(i));
	}
	CHECK(nw.addUser("yoshi", "Yoshi") == false);
}

TEST_CASE("TASK C") {
	Network nw;
	nw.addUser("mario", "Mario");
	nw.addUser("luigi", "Luigi");
	nw.addUser("yoshi", "Yoshi");
	CHECK(nw.follow("mario", "luigi") == true);
	CHECK(nw.follow("mario", "yoshi") == true);
	CHECK(nw.follow("luigi", "mario") == true);
	CHECK(nw.follow("i", "mario") == false);
}
