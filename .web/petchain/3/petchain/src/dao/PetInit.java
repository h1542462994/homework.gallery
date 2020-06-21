package dao;

import util.Generator;

import java.util.Arrays;
import java.util.Objects;

/**
 * 使用猜数字游戏生成第0代宠物
 */
public class PetInit {
    public PetInit(){
        pet = Pet.generate();
        number = new Generator().randInt(0, 100);
    }

    private String guessResult;
    private Pet pet;
    private Integer number;
    private Boolean guessed = false;

    public void distribute(){
        pet.setAttributeOld(Arrays.copyOf(pet.getAttribute(), 8));
        new Generator().distribute(pet.getAttribute());
    }

    public Pet getPet() {
        return pet;
    }

    public Integer getNumber() {
        return number;
    }

    public String getGuessResult() {
        return guessResult;
    }

    public void setGuessResult(String guessResult) {
        this.guessResult = guessResult;
    }

    public Boolean getGuessed() {
        return guessed;
    }

    public void setGuessed(Boolean guessed) {
        this.guessed = guessed;
    }
}
