package exp6;

import com.sun.org.apache.bcel.internal.util.ByteSequence;

import java.io.*;
import java.util.Arrays;

public class Mp3MetaReader {
    public static void main(String[] arg) throws IOException {
        Mp3Meta meta = Mp3Meta.readMp3(new File("./王杰-一场游戏一场梦.mp3"));

        System.out.println(meta);

    }
}
