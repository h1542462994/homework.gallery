package dao;

public class UserInfo {
    private String name;
    private double coins;
    private PetCollection pets;
    private String email;


    public UserInfo() {
    }
    public UserInfo(String name, double coins, PetCollection pets, String email) {
        this.name = name;
        this.coins = coins;
        this.pets = pets;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getCoins() {
        return coins;
    }

    public void setCoins(double coins) {
        this.coins = coins;
    }

    public PetCollection getPets() {
        return pets;
    }

    public void setPets(PetCollection pets) {
        this.pets = pets;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }



}
