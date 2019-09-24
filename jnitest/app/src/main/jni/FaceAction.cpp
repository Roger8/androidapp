//
// Created by Roger on 2019/9/23.
//

#include "FaceAction.h"
using namespace std;

Pt2d p(float x, float y){
    Pt2d pt ;
    pt.x = x;
    pt.y = y;
    return pt;
}

Pt2F::Pt2F() {
    x=0;
    y=0;
}

Pt2F::~Pt2F(){}

Pt2F::Pt2F(float x_, float y_) {
    x= x_;
    y= y_;
}

Pt2F getPt2F(float* landmarks , int indx){
    Pt2F px = Pt2F(landmarks[indx*2],landmarks[indx*2+1]);
    return px;
}

float cal_pts_dist(Pt2F p1 , Pt2F p2){
    return (float)sqrt(pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2));
}

float cal_distance_ratio(Pt2F p1, Pt2F p2, Pt2F p3){
    float d1 = cal_pts_dist(p1,p3);
    float d2 = cal_pts_dist(p2,p3);
    float ratio =0;

    ratio = (atan(d1/d2)/Pi*180-45)*2;
    return ratio;
}

float cal_distance_ratio2(Pt2F p0 ,Pt2F p1, Pt2F p2, Pt2F p3){
    Pt2F pt;
    pt.x = (p2.x+p3.x)/2;
    pt.y = (p2.y+p3.y)/2;
    float d1 = cal_pts_dist(p0, pt);
    float d2 = cal_pts_dist(p1, pt);
    float ratio = (atan(d1/d2)/Pi*180-45)*2;
    return ratio;
}

float cal_oblique_eye(Pt2F p1 ,Pt2F p2){
    return atan((p2.y - p1.y)/(p2.x-p1.x))/Pi*180;
}

float cal_oblique_eye2(Pt2F p0 ,Pt2F p1, Pt2F p2){
    float angle1 = cal_oblique_eye(p1, p2);
    float angle2 = cal_oblique_eye(p0,p2);
    return 0.5f*(angle2-angle1);
}


FaceAction::FaceAction(){}

string FaceAction::estimateaction(float* landmarks){
    return acts[0];
}


void FaceAction::estimateYawPitchRoll(float *landmarks, int * yawpitchroll) {
    int YPR[3];
    int pindx[] = {96, 97,51,76,82,90,94,0,32};
    // p96: lefteye center, p97 : right eye center,
    // p51: nose upest, p76: left mouth corner, p82: right mouth corner,
    // p90: mouth inner center up, p94: mouth inner center bottom
    // p0: left cheek upest, p32 : right cheek upest
    Pt2F p96 = Pt2F(landmarks[96*2],landmarks[96*2+1]);
    Pt2F p97 = Pt2F(landmarks[97*2],landmarks[97*2+1]);
    Pt2F p51 = Pt2F(landmarks[51*2],landmarks[51*2+1]);
    Pt2F p76 = Pt2F(landmarks[76*2],landmarks[76*2+1]);
    Pt2F p82 = Pt2F(landmarks[82*2],landmarks[82*2+1]);
    Pt2F p90 = Pt2F(landmarks[90*2],landmarks[90*2+1]);
    Pt2F p94 = Pt2F(landmarks[94*2],landmarks[94*2+1]);
    Pt2F p0 = Pt2F(landmarks[0*2],landmarks[0*2+1]);
    Pt2F p32 = Pt2F(landmarks[32*2],landmarks[32*2+1]);

    float angle_roll_eye = cal_oblique_eye(p96, p97);
    float angle_yaw_eye=cal_distance_ratio(p96, p97, p51);

    float angle_yaw_mouse=cal_distance_ratio2(p76, p82, p90,p94);
    float angle_roll_mouse=cal_oblique_eye(p76, p82);

    float angle_pitch=cal_oblique_eye2(p0,p32,p51);


    YPR[0] = (int)angle_yaw_eye;
    YPR[1] = (int)angle_pitch;
    YPR[2] = (int)angle_roll_eye;

    *yawpitchroll = (int)angle_yaw_eye;
    *(yawpitchroll+1)= (int)angle_pitch;
    *(yawpitchroll+2) = (int)angle_roll_eye;

}

bool  FaceAction::Helloworld(){
       return true;
}

