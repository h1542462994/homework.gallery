package org.tty.test1.foundation;

public class ResourceManager {
    private static ResourceManager gResourceManager = null;

    private ResourceManager() {}

    private void init() {

    }

    public String getRelativePath(String filePath) {
        return getClass().getResource(filePath).getPath();
    }

    public static ResourceManager getInstance() {
        if (gResourceManager == null) {
            gResourceManager = new ResourceManager();
            gResourceManager.init();
        }
        return gResourceManager;
    }
}
