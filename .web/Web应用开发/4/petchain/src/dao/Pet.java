package dao;

import com.sun.xml.internal.ws.api.ha.StickyFeature;
import enums.Levels;
import request.AddDogRequest;
import store.IWebUrl;
import store.ServiceContainer;
import util.Generator;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;

public class Pet {

    private int[] attributeOld;
    /**
     * 莱克狗各个属性的品质等级。
     * 0表示普通，1表示稀有
     */
    private int[] attribute;
    private String imageUrl;
    private int batch;
    private String name;
    private String uid;

    public String getImageUrl() {
        return imageUrl;
    }

    public void setImageUrl(String imageUrl) {
        this.imageUrl = imageUrl;
    }

    public int getBatch() {
        return batch;
    }

    public void setBatch(int batch) {
        this.batch = batch;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getUid() {
        return uid;
    }

    public void setUid(String uid) {
        this.uid = uid;
    }

    public double getPrize() {
        return 188.0;
    }

    public String getLevel(){
        long count = Arrays.stream(attribute).filter((item)-> item == 1).count();
        if(count >= 8){
            return Levels.UUR;
        } else if(count >= 6){
            return Levels.UR;
        } else if(count >= 4){
            return Levels.SSR;
        } else if(count >= 3){
            return Levels.SR;
        } else if(count >= 2){
            return Levels.R;
        } else {
            return Levels.N;
        }
    }

    public static Pet random(){
        Pet pet = new Pet();
        IWebUrl url = ServiceContainer.get().webUrl();
        Generator generator = new Generator();
        pet.setImageUrl(url.getUrl("/image/" + generator.randInt(1, 14) + ".png"));
        pet.setBatch(0);
        pet.setAttribute(generator.randDistribution(generator.randInt(3,6),8));
        pet.setName("小星");
        pet.setUid(String.valueOf(generator.randInt(0, 99999)));
        return pet;
    }

    /**
     * 生成第一代莱茨狗
     * @return 宠物
     */
    public static Pet generate() {
        Pet pet = new Pet();
        IWebUrl url = ServiceContainer.get().webUrl();
        Generator generator = new Generator();
        pet.setImageUrl(url.getUrl("/image/" + generator.randInt(1, 14) + ".png"));
        pet.setBatch(0);
        pet.setAttribute(generator.randDistribution(3, 8));
        pet.setName("小星");
        pet.setUid(String.valueOf(generator.randInt(0, 99999)));
        return pet;
    }

    public static Pet fromRequest(AddDogRequest request){
        Pet pet = new Pet();
        IWebUrl url = ServiceContainer.get().webUrl();
        pet.setImageUrl(url.getUrl("/image/" + request.getImageUrl() + ".png"));
        pet.setBatch(Integer.parseInt(request.getBatch()));
        pet.setName(request.getName());
        pet.setUid(String.valueOf(new Generator().randInt(0, 99999)));
        pet.setAttribute(new int[]{
                request.getAttribute_0(),
                request.getAttribute_1(),
                request.getAttribute_2(),
                request.getAttribute_3(),
                request.getAttribute_4(),
                request.getAttribute_5(),
                request.getAttribute_6(),
                request.getAttribute_7(),
        });
        return pet;
    }

    public static ArrayList<Pet> randoms(int count){
        ArrayList<Pet> pets = new ArrayList<>();
        for(int i = 0; i < count; ++i){
            pets.add(Pet.random());
        }
        return pets;
    }

    public int[] getAttribute() {
        return attribute;
    }

    public void setAttribute(int[] attribute) {
        this.attribute = attribute;
    }

    public String[] getAttributeForDisplay(){
        String[] strings = new String[this.attribute.length];
        for (int i = 0; i < this.attribute.length; ++i){
            strings[i] = "";
            if(this.attributeOld != null && this.attributeOld[i] != this.attribute[i]){
                strings[i] += this.attributeOld[i] == 1 ? "稀有->": "普通->";
            }
            strings[i] += this.attribute[i] == 1 ? "稀有": "普通";
        }
        return strings;
    }

    public int[] getAttributeOld() {
        return attributeOld;
    }

    public void setAttributeOld(int[] attributeOld) {
        this.attributeOld = attributeOld;
    }
}
