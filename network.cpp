#include "network.h"
#include "profile.h"
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

Network::Network(){
	numUsers = 0;
	for(int i = 0; i < MAX_USERS; i++) {
		for(int j = 0; j < MAX_USERS; j++) {
			following[i][j] = false;
		}
	}
}

int Network::findID(string usrn) {
	for(int i = 0; i < numUsers; i++){
		if(profiles[i].getUsername() == usrn) {
			return i;
		}
	}
	return -1;
}

bool Network::addUser(string usrn, string dspn) {
	if(numUsers >= MAX_USERS) {
		return false;
	} else if (findID(usrn) != -1) {
		return false;
	}
	
	for(int i = 0; i < usrn.size(); i++) {
		if(!isalnum(usrn[i])) {
			return false;
		}
	}
	profiles[numUsers] = Profile(usrn, dspn);
	numUsers++;
	return true;
}

bool Network::follow(string usrn1, string usrn2) {
	if(findID(usrn1) != -1 && findID(usrn2) != -1) {
		following[findID(usrn1)][findID(usrn2)] = true;
		return true;
	}
	return false;
}

void Network::printDot() {
	cout << "digraph {" << endl;
	for(int i = 0; i < numUsers; i++) {
		cout << "\t\"@" << profiles[i].getUsername() << "\"" << endl;
	}
	cout << endl;
	for(int i = 0; i < numUsers; i++) {
		for(int j = 0; j < numUsers; j++) {
			if(following[i][j] == true) {
				cout << "\t\"@" << profiles[i].getUsername() << "\"" << " -> " << "\"@" << profiles[j].getUsername() << "\""<< endl;
			}
		}
	}
	cout << "}" << endl;
}
