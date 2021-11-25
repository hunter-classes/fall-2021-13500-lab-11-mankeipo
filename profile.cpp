#include "profile.h"
using namespace std;

Profile::Profile(string usrn, string dspn) {
	username = usrn;
	displayname = dspn;
}

Profile::Profile() {
	username = "";
	displayname = "";
}

string Profile::getUsername() {
	return username;
}

string Profile::getFullName() {
	return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn) {
	displayname = dspn;
}
