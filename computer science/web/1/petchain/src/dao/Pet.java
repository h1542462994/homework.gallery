package dao;

import enums.Levels;
import store.IWebUrl;
import store.ServiceContainer;
import util.Generator;

public class Pet {


    private String imageUrl;
    private String level;
    private int batch;
    private String name;
    private String uid;
    private double prize;

    public String getImageUrl() {
        return imageUrl;
    }

    public void setImageUrl(String imageUrl) {
        this.imageUrl = imageUrl;
    }

    public String getLevel() {
        return level;
    }

    public void setLevel(String level) {
        this.level = level;
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
        return prize;
    }

    public void setPrize(double prize) {
        this.prize = prize;
    }

    public static Pet random(){
        Pet pet = new Pet();
        IWebUrl url = ServiceContainer.get().webUrl();
        Generator generator = new Generator();
        pet.setImageUrl(url.getUrl("/image/" + generator.randInt(1, 14) + ".png"));
        pet.setBatch(0);
        pet.setLevel(Levels.NORMAL);
        pet.setName("小星");
        pet.setPrize(188.00);
        pet.setUid(String.valueOf(generator.randInt(0, 99999)));
        return pet;
    }

}
