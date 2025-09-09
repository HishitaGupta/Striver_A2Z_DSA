#include <bits/stdc++.h>
using namespace std;

int findNumberOfPeople(int currDay , int delay, int forget , int finalDay, int numOfPeople) {

    while (currDay <= finalDay) {

        if (currDay> delay && currDay <= forget) {
            numOfPeople++;
            numOfPeople+= findNumberOfPeople(currDay,currDay+delay,currDay+forget,finalDay,numOfPeople);
        }
        currDay++;
    }

    return numOfPeople;
}


int main() {
    int finalDay=6; int delay =2; int forget =4;int currDay =1;
    int numOfPeople=0;

    cout<<findNumberOfPeople(currDay, delay,forget, finalDay, numOfPeople);
}