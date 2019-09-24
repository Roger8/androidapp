package com.roger.facejni;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    private TextView t1;
    private FaceAction faceact = new FaceAction();


    private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            "android.permission.READ_EXTERNAL_STORAGE",
            "android.permission.WRITE_EXTERNAL_STORAGE" };


    public static void verifyStoragePermissions(Activity activity) {

        try {
            //检测是否有写的权限
            int permission = ActivityCompat.checkSelfPermission(activity,
                    "android.permission.WRITE_EXTERNAL_STORAGE");
            if (permission != PackageManager.PERMISSION_GRANTED) {
                // 没有写的权限，去申请写的权限，会弹出对话框
                ActivityCompat.requestPermissions(activity, PERMISSIONS_STORAGE,REQUEST_EXTERNAL_STORAGE);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        verifyStoragePermissions(this);

        t1 = findViewById(R.id.textView);
        Button btn1 = (Button)findViewById(R.id.button1);
        btn1.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v1){

                t1.setText("hhhhhh");
                faceact.Helloworld();
                float [] landmarks = new float[106*2];

                for(int i=0;i<106;i++){

                    landmarks[i*2] = i;
                    landmarks[i*2+1] = i*2f;
                }

                String out = FaceAction.Estimateaction(landmarks);
                t1.setText(out);

                int[] angles = new int[3];
                angles = FaceAction.EstimatePoseAngle(landmarks);
//                System.console().printf("yaw: %d, pitch: %d, roll: %d \n", angles[0], angles[1], angles[2]);
            }

        });

    }


}
