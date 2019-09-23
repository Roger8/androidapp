//
// Created by Roger on 2019/9/23.
//

#ifndef JNITEST_FACTACTION_H
#define JNITEST_FACTACTION_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

const vector<string> acts = {"headup", "headdown", "headleft", "headright"};

class FaceAction {

public :
    FaceAction();

    ~FaceAction();

    string estimateaction(int landmarks[]);

    bool Helloworld();


};

#endif //JNITEST_FACTACTION_H
