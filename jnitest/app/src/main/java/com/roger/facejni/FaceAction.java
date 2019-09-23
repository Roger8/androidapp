package com.roger.facejni;

public class FaceAction {

    // get face actions by face landmarks
    public native  static String Estimateaction();

    public native boolean Helloworld();

    static {
        System.loadLibrary("faceaction");
    }
}
