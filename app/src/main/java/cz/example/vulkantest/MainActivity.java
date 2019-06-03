package cz.example.vulkantest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;


public class MainActivity extends AppCompatActivity {
    private GraphicsView graphicsView = null;

    static {
        System.loadLibrary("VulkanTest");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        graphicsView = new GraphicsView(this);
        setContentView(graphicsView);
    }
}
