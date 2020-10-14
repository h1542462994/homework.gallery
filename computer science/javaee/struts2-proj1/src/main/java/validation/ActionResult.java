package validation;

public interface ActionResult {
    boolean pass();
    String[] messages();
    int actionResult();

}
