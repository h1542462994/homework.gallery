package exp6;

import java.io.*;
import java.util.Arrays;

public class Mp3Meta {
    /**
     * 版本
     */
    String version;
    /**
     * 作者
     */
    String artist;
    /**
     * 专集
     */
    String album;
    /**
     * 出品年代
     */
    String year;
    /**
     * 类型
     */
    String type;
    /**
     * 版权
     */
    String copyright;

    @Override
    public String toString(){
        return String.format("meta:\n artist:%s\n album:%s\n year:%s\n type:%s\n copyright:%s\n",artist,album,year,type,copyright);
    }

    public static Mp3Meta readMp3(File file) throws IOException {
        //InputStream inStream = new FileInputStream(file);
        RandomAccessFile reader  = new RandomAccessFile(file,"r");
        String charset = "gbk";
        byte[] identity = new byte[3];
        reader.read(identity);

        Mp3Meta meta = new Mp3Meta();

        if(new String(identity).equals("ID3")){
            byte[] version = new byte[1];
            reader.read(version);
            System.out.println((int)version[0]);
            meta.version = String.valueOf((int)version[0]);
            reader.read(new byte[2]);
            byte[] sizeData = new byte[4];
            reader.read(sizeData);
            long size = sizeData[0]*0x200000L+sizeData[1]*0x4000L+sizeData[2]*0x80L+sizeData[3];
            System.out.println(size);

            long point = 10;
            int loop = 0;
            while(point < size){
                try{
                    loop++;
                    System.out.println(String.format("第%s个标签",loop));
                    byte[] flagData = new byte[4];
                    reader.read(flagData);
                    String flag = new String(flagData);
                    System.out.println(flag);
                    byte[] unitSizeData = new byte[4];
                    reader.read(unitSizeData);
                    long unitSize = unitSizeData[0]*0x1000000L+unitSizeData[1]*0x10000L+unitSizeData[2]*0x100L+unitSizeData[3];
                    System.out.println(unitSize);
                    byte[] unitFlagData = new byte[2];
                    reader.read(unitFlagData);

                    byte[] unitData = new byte[(int)unitSize];
                    reader.read(unitData);

                    String unit = new String(unitData, charset);
                    System.out.println(unit);

                    if(flag.equals("TPE1")){
                        meta.artist = unit;
                    } else if(flag.equals("TALB")){
                        meta.album = unit;
                    } else if(flag.equals("TYER")){
                        meta.year = unit;
                    } else if(flag.equals("TCON")){
                        meta.type = unit;
                    } else if(flag.equals("TCOP")){
                        meta.copyright = unit;
                    }


                    point+=10+unitSize;
                } catch (NegativeArraySizeException e){
                    break;
                }
            }

            return meta;
        } else {
            System.out.println("no ID3");
            return null;
        }



    }
}
