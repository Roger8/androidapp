//
// Created by Roger on 2019/9/23.
//

#ifndef JNITEST_FACTACTION_H
#define JNITEST_FACTACTION_H

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
const float Pi=3.14159265f;
struct Pt2d
{
    float x;
    float y;
};

class Pt2F{
public:
    float x;
    float y;
    Pt2F();
    Pt2F(float x_, float y_);

    ~Pt2F();
};

const vector<string> acts = {"headup", "headdown", "headleft", "headright"};

class FaceAction {

public :
    FaceAction();

    ~FaceAction() {};

    string estimateaction(float* landmarks);

    void estimateYawPitchRoll(float* landmarks, int * yawpitchroll);

    bool Helloworld();


};

#endif //JNITEST_FACTACTION_H
