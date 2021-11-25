#pragma once
#include <string>
#include "profile.h"
using namespace std;

class Network {
private:
  static const int MAX_USERS = 20;
  int numUsers;                    
  Profile profiles[MAX_USERS];
  int findID (string usrn);
  bool following[MAX_USERS][MAX_USERS];
public:
  Network();
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1, string usrn2);
  void printDot();
};
