package validation;

public class ActionResult {
    public ActionResult(boolean pass, int actionResult, String... messages){
        this.pass = pass;
        this.actionResult = actionResult;
        this.messages = messages;
    }

    private final boolean pass;
    private final int actionResult;
    private final String[] messages;

    public boolean isPass() { return pass; }
    public int getActionResult() { return actionResult; }
    public String[] getMessages() { return messages; }
}
