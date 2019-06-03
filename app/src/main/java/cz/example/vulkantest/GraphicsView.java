package cz.example.vulkantest;

import android.content.Context;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;


public class GraphicsView extends SurfaceView implements SurfaceHolder.Callback {
    public GraphicsView(Context context) {
        super(context);
        getHolder().addCallback(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        onVulkanCreate(holder.getSurface());
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        onVulkanResize(holder.getSurface(), width, height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        onVulkanDestroy(holder.getSurface());
    }

    private native void onVulkanCreate(Surface surface);
    private native void onVulkanResize(Surface surface, int w, int h);
    private native void onVulkanDestroy(Surface surface);
}
