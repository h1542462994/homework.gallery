package dao;

public class LoginState {
    private UserPassport passport;
    private boolean state;

    public LoginState() {
        state = false;
        passport = new UserPassport();
    }

    public UserPassport getPassport() {
        return passport;
    }

    public LoginState(UserPassport passport, boolean state) {
        this.passport = passport;
        this.state = state;
    }

    public void setPassport(UserPassport passport) {
        this.passport = passport;
    }

    public boolean isState() {
        return state;
    }

    public void setState(boolean state) {
        this.state = state;
    }

}
