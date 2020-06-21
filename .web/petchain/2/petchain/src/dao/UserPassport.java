package dao;

public class UserPassport  {
    private String name;
    private String nameError;
    private String password;
    private String passwordError;

    public UserPassport() {
    }

    public UserPassport(String name, String password) {
        this.name = name;
        this.password = password;
    }

    public void clearError(){
        this.nameError = null;
        this.passwordError = null;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNameError() {
        return nameError;
    }

    public void setNameError(String nameError) {
        this.nameError = nameError;
    }

    public String getPasswordError() {
        return passwordError;
    }

    public void setPasswordError(String passwordError) {
        this.passwordError = passwordError;
    }
}
